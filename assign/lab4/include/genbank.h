#ifndef __GENBANK__
#define __GENBANK__
#include<stdio.h>

typedef struct Features{
    const char* name;
    const char* gene_name;
    char* list;
    char* codon_table;
}FEATURE;

char* Origin(FILE* instream);
int genflag( const char* string);
FEATURE* gene(const char* string,const char* origin);
FEATURE* mRNA(const char* string,const char* origin);
FEATURE* CDS(const char* string,const char* origin);


#endif