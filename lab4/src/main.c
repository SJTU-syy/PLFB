#include"../include/fasta.h"
#include"../include/genbank.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME_IN "test.txt"
#define FILE_NAME_OUT "../data/fasta/NM000207.fasta"
#define N 100




FEATURE base;
FEATURE* TMP = &base;//TNND,一个bug修一年,欲哭无泪,终于找到了原因.字符数组中a = &a[0],但是并不是所有指针都能这样,如此定义才行.

int main() {
	
 	FILE *fi= fopen(FILE_NAME_IN, "r");
	FILE *fo = fopen(FILE_NAME_OUT, "w");
	printf("%c",fgetc(fi));
    char str[N + 1];
	printf("%s\n",str);

    fgets(str,sizeof(str)-1,fi);
	printf("%s\n",str);
	
	char ORIGIN[1000]="";
	getOrigin(fi,ORIGIN);
    printf("%s\n",ORIGIN);
    fprintf(fo,">ORIGIN\n%s\n\n",ORIGIN);
    //printf("\ntestnode\n");
    
    fseek(fi,0,SEEK_SET); //需要更新主文件流fi
    FILE* ftmp = fi;
	
	
    while(fgets(str,N,fi)!=NULL){
        switch(genflag(str)){
			case 1:
            	ftmp = fi;
                TMP=gene(ftmp,TMP,ORIGIN,str);//有更简写法,但是因为bug不会修,所以用这种四参数方式通过
                fasta(TMP,fo);
                break;
			case 2:
			    ftmp = fi;
			    TMP=mRNA(ftmp,TMP,ORIGIN,str);
			    fasta(TMP,fo);
			    break;
			case 3:
			 	ftmp = fi;
			    TMP=CDS(ftmp,TMP,ORIGIN,str);
			    fasta(TMP,fo);
			    break;
			default:
				break;
		}
    }
        	
	
	
    fclose(fi);
    fclose(fo);
    return 0;
}