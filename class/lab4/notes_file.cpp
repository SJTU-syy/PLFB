#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_NAME_IN "NM000207.gb"
#define FILE_NAME_OUT "shuchu.fasta"
#define N 100



int main() {
	FILE *fp; fp = fopen(FILE_NAME_IN, "r");
	FILE *fp1; fp1 = fopen(FILE_NAME_OUT, "w");
	if (fp == NULL) {
		printf("Failed to open %s\n", FILE_NAME_IN);
		exit(EXIT_FAILURE);
	}
	

	//printf("%d\n",fgetc(fp));
	//printf("%d",ftell(fp));
	
	
	char str[N + 1];
	while(fgets(str,N,fp)!=NULL){
		printf("%s",str);
		//if(strchr(str,'FEATURES')!=NULL)
		//printf("1\n2\n3\n4\n");
		if(strstr(str,"FEATURES")!=NULL)
		printf("1\n2\n3\n4\n");
		
		
	} //发现错误在于strchr只能搜索单个字符,如果强行搜索字符串,只会搜索第一个字符,另外有意思的一点是单引号括起来的单个char其实会被识别为int
	
	
	
	
	
	fclose(fp);
	return 0;
}