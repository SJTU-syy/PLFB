#ifndef __GENBANK__
#define __GENBANK__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Features{
    char* name;
    char* codon_table;
    char gene_name[10];
    char* list[];
    //又一个欲哭无泪的bug,虽然C手册里写了string函数(strcat,strcpy)的要求只是char*,但测试发现上这里必须用动态char数组完成
}FEATURE;


int string_to_int(char* pos);
void getOrigin(FILE* instream,char* p);
int genflag( const char* string);
FEATURE* gene(FILE* instream,FEATURE* tmp,const char* origin,char* string_list);
FEATURE* mRNA(FILE* instream,FEATURE* tmp,const char* origin,char* string_list);
FEATURE* CDS(FILE* instream,FEATURE* tmp,const char* origin,char* string_list);
void amino(char* DNA);


#endif