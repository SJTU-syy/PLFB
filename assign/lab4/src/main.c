#include"genbank.h"
#include"fasta.h"
#include<stdio.h>
#define FILE_NAME_IN "../data/genbank/NM000207.gb"
#define FILE_NAME_OUT "../data/fasta/NM000207.fasta"
#define N 100


char str[N + 1];
FEATURE* tmp = NULL;

int main(){
    FILE *fi; fi = fopen(FILE_NAME_IN, "r");
    FILE *fo; fo = fopen(FILE_NAME_OUT, "w");
    char* ORIGIN = Origin(fi);

    while(fgets(str,N,fi)!=NULL){
        switch(genflag(str)){
            case 1:
                tmp=gene(str,ORIGIN);
                fasta(*tmp,fo);
                break;
            case 2:
                tmp=mRNA(str,ORIGIN);
                fasta(*tmp,fo);
                break;
            case 3:
                tmp=CDS(str,ORIGIN);
                fasta(*tmp,fo);
                break;
            default:
                break;
        }
    }

    fclose(fi);
    fclose(fo);
    return 0;
}