#include<stdio.h>

void fasta(FEATURE* tmp,FILE* outstream){
	fprintf(outstream,">%s | %s%s\n",tmp->name,tmp->gene_name,tmp->list);
};
