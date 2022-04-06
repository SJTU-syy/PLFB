#include<stdio.h>
#include"../include/fasta.h"
#include"../include/genbank.h"

void fasta(FEATURE* tmp,FILE* outstream){
	if(strlen(tmp->codon_table))
		fprintf(outstream,">%s | %s%s\namino_acid:%s\n\n",tmp->name,tmp->gene_name,tmp->list,tmp->codon_table);
	else
		fprintf(outstream,">%s | %s%s\n\n",tmp->name,tmp->gene_name,tmp->list);
};

