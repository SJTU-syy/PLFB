#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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


char* getOrigin(FILE* instream,char* p){
	char string[101];
	while(fgets(string,101,instream)!=NULL){
		if(strstr(string,"ORIGIN")==string){
			//printf("find origin!\n");
			//printf("%s\n",string);
			while(fgets(string,101,instream)!=NULL&&strchr(string,'/')!=string){
				int i = 0;
				strncat(p,string+10,10);
				for(i=1;i<6;i++){
					strncat(p,string+10+11*i,10);  //经过长久的测验,发现这里一开始出错的原因是,strcat中的前一个char*不能为NULL(NULL被视作const),也不能用常量初始化,可以直接只写定义,或者直接写成char* ORIGIN = getOrigin(fi,ORIGIN)
				} 
				//printf("%s\n",string+10);
				//printf("%d\n",strlen(string));
			}
			//printf("%s\n",p); 
			char* p1 = p;
			while(*p1!='\0'&&*p1!='\n'){
				p1+=1;
			}
			*p1 = '\0';
			//测试发现因为strncat和fgets的特性,ORIGIN会多出一段(每次更新的时候结尾可能不被覆盖),包括strlen(ORIGIN)的返回也是对的,但是要处理以输出正确的原始序列
			return p;
		}
	}
	return 0;
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
	printf("%d\n%d\n",start,end);
	strncpy(tmp->list,origin+start-1,end-start+1);
	*(tmp->list+end+1) = '\0';
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
	printf("%d\n%d\n",start,end);
	strncpy(tmp->list,origin+start-1,end-start+1);
	*(tmp->list+end+1) = '\0';
	fgets(string,101,instream); //默认/gene紧接在第二行
	strcpy(tmp->gene_name,string+27);
		//printf("%s\n",tmp->gene_name);
		return tmp;
};

FEATURE* CDS(FILE* instream,FEATURE* tmp,const char* origin,char* string_list){
	
	tmp->name = "CDS";
	char string[101 + 1];
	
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
	printf("%d\n%d\n",start,end);
	strncpy(tmp->list,origin+start-1,end-start+1);
	*(tmp->list+end+1) = '\0';
	fgets(string,101,instream); //默认/gene紧接在第二行
	strcpy(tmp->gene_name,string+27);
		//printf("%s\n",tmp->gene_name);
	return tmp;
	
	
};