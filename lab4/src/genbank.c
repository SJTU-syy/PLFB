#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/genbank.h"


int string_to_int(char* pos){
	int sum = 0;
	while(*(pos)!='.'&&*(pos)!='\0'&&*(pos)!='\n'){
		//printf("%c sum %d\n",*(pos),sum);
		sum*=10;
		sum+=*(pos)-48;
		pos++;
	}
	return sum;
}


void getOrigin(FILE* instream,char* p){
	char string[101];
	memset(string,0,strlen(string));
	while(fgets(string,101,instream)!=NULL){
		if(strstr(string,"ORIGIN")==string){
			//printf("find origin!\n");
			printf("%s\n",string);
			while(fgets(string,101,instream)!=NULL&&strchr(string,'/')!=string){
				int i = 0;
				strncat(p,string+10,10);
				for(i=1;i<6;i++){
					strncat(p,string+10+11*i,10);  //经过长久的测验,发现这里一开始出错的原因是,strcat中的前一个char*不能为NULL(NULL被视作const),也不能用常量初始化,最好还是用动态字符数组
					//printf("%s\n",p);
					//printf("%s\n",string+10+11*i,10);
				} 
				//printf("%s\n",string+10);
				//printf("%d\n",strlen(string));
			}
			//printf("%s\n",p); 
			
			char* p1 = p;
			while(*p1!='\0'&&*p1!='\n'){
				p1+=1;
			}
			*p1 =0;
			//测试发现因为strncat和fgets的特性,ORIGIN会多出一段(每次更新的时候结尾可能不被覆盖),包括strlen(ORIGIN)的返回也是对的,但是要处理以输出正确的原始序列
		}
	}
};


int genflag( const char* string){
	if(strstr(string,"gene")==string+5) return 1;
	else if(strstr(string,"mRNA")==string+5) return 2;
	else if(strstr(string,"CDS")==string+5) return 3;
	else return 0;
};


FEATURE* gene(FILE* instream,FEATURE* tmp,const char* origin,char* string_list){
	
	tmp->name = "gene";
	char string[101];
	
	//找序列位置
	int start,end;
	char* POS;
	POS = string_list + 21; start = string_to_int(POS);
	while(*(POS)!='\0'&&*(POS)!='\n'){
		if(*(POS-1)=='.'&&*(POS)!='.'){
			end = string_to_int(POS);
			break;
		}
		POS++;
	}
	//printf("%d\n%d\n",start,end);
	memset(tmp->list, 0, strlen(tmp->list));
	strncpy(tmp->list,origin+start-1,end-start+1);
	//*(tmp->list+end+1) = '\0';
	fgets(string,101,instream); //默认/gene紧接在第二行
	strcpy(tmp->gene_name,string+27);
	//printf("%s\n",tmp->gene_name);
		return tmp;
};

FEATURE* mRNA(FILE* instream,FEATURE* tmp,const char* origin,char* string_list){
	
	tmp->name = "mRNA";
	char string[101];
	
	//找序列位置
	int start,end;
	char* POS;
	POS = string_list + 21; start = string_to_int(POS);
	while(*(POS)!='\0'&&*(POS)!='\n'){
		if(*(POS-1)=='.'&&*(POS)!='.'){
			end = string_to_int(POS);
			break;
		}
		POS++;
	}
	//printf("%d\n%d\n",start,end);
	memset(tmp->list, 0, strlen(tmp->list));
	strncpy(tmp->list,origin+start-1,end-start+1);
	//*(tmp->list+end+1) = '\0';
	fgets(string,101,instream); //默认/gene紧接在第二行
	strcpy(tmp->gene_name,string+27);
		//printf("%s\n",tmp->gene_name);
		return tmp;
};

FEATURE* CDS(FILE* instream,FEATURE* tmp,const char* origin,char* string_list){
	
	tmp->name = "CDS";
	char string[100 + 1];
	
	//找序列位置
	int start,end;
	char* POS;
	POS = string_list + 21; start = string_to_int(POS);
	while(*(POS)!='\0'&&*(POS)!='\n'){
		if(*(POS-1)=='.'&&*(POS)!='.'){
			end = string_to_int(POS);
			break;
		}
		POS++;
	}
	//printf("%d\n%d\n",start,end);
	memset(tmp->list, 0, strlen(tmp->list));
	strncpy(tmp->list,origin+start-1,end-start+1);
	//*(tmp->list+end+1) = '\0'; //gdb发现这里采用了和windows不同的储存方法,这种形式控制长度在linux上好像不适用,还好查到了memset函数.
	fgets(string,101,instream); //默认/gene紧接在第二行
	strcpy(tmp->gene_name,string+27);
		//printf("%s\n",tmp->gene_name);

		
	//子密码表
	while(fgets(string,100,instream)!=NULL){
		if(strstr(string,"/translation")==string + 21){
			//printf("test-node\n");
			//printf("string:%s\n",string);
			int flag = 1;
			int i=0;
			//printf("tmp->codon_table:%s\n",tmp->codon_table);
			while(flag){
				POS=string;i=0;
				while(*(POS)!='\0'&&*(POS)!='\n'){
					if (*(POS)=='"'&&*(POS-1)!='=')
					{flag=0;
					//printf("string:%s\n",string);
					//printf("find fuhao in %d\n",i);
					break;}
					POS++;
					i++;
				}
				if(flag){
					strcat(tmp->codon_table,string+21);
					fgets(string,100,instream);
					//printf("tmp->codon_table:%s\n",tmp->codon_table);
				}
				else{
					strncat(tmp->codon_table,string+21,i-20);
					//printf("tmp->codon_table:%s\n",tmp->codon_table);
					break;
				}
			}
		}
	}
	amino(tmp->codon_table);
	return tmp;
	
	
};

void amino(char* DNA){
	char acid[1000];
	memset(acid,0,strlen(acid));
	char* p = DNA+14;
	while((*p)!='"'){
		if(*p=='G') strcat(acid,"GGU");
		else if (*p=='G') strcat(acid,"GGU");
		else if (*p=='A') strcat(acid,"AUU");
		else if (*p=='V') strcat(acid,"GUU");
		else if (*p=='L') strcat(acid,"CUU");
		else if (*p=='I') strcat(acid,"AUC");
		else if (*p=='F') strcat(acid,"UUU");
		else if (*p=='w') strcat(acid,"UGG");
		else if (*p=='Y') strcat(acid,"UAU");
		else if (*p=='D') strcat(acid,"GAU");
		else if (*p=='H') strcat(acid,"CAU");
		else if (*p=='N') strcat(acid,"AAU");
		else if (*p=='E') strcat(acid,"GAA");
		else if (*p=='K') strcat(acid,"AAA");
		else if (*p=='Q') strcat(acid,"CAA");
		else if (*p=='M') strcat(acid,"AUG");
		else if (*p=='R') strcat(acid,"AGA");
		else if (*p=='S') strcat(acid,"AGU");
		else if (*p=='T') strcat(acid,"ACU");
		else if (*p=='C') strcat(acid,"UGU");
		else if (*p=='P') strcat(acid,"CCU");
		p++;
	}
	memset(DNA,0,strlen(DNA));
	strcpy(DNA,acid);
}