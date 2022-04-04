#ifndef __FASTA__
#define __FASTA__
#include<stdio.h>

typedef struct Features{
    const char* name;
    const char* gene_name;
    char* list;
    char* codon_table;
}FEATURE;

void fasta(FEATURE xulie,FILE* outstream);

#endif