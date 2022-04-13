#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* mystrstr(char* dest,char* src) {
        char* tdest = dest;
        char* tsrc = src;
        int i = 0;
        int j = 0;
        while (i <= strlen(tdest) - 1 && j <= strlen(tsrc)-1)
        {
            if (tdest[i] == tsrc[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i-(j-1);
                j = 0;
            }
        }
        if (j == strlen(tsrc))
        {
            return tdest+i-strlen(tsrc);
        }

        return NULL;
}

void get_next(char s[],int next[])
{
    int i=0;
    int j=-1;
    next[0]=-1;
    int len=strlen(s);
    while(i<len-1)
    {
        if(j==-1||s[i]==s[j])
        {
			next[++i]=++j;
        }
        else
        {
            j=next[j];
        }
    }
}

int KMP(char s1[],char s2[],int next[])
{
    int i=0;
    int j=0;
    int len1=strlen(s1);
    int len2=strlen(s2);
    while(i<len1&&j<len2)
    {
        if(j==-1||s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>=len2)
        return i-len2;
    else
        return -1;
}


int main(){
   FILE * fp;
   fp = fopen ("../DNA.fasta", "w+");
   int i,j;
   for(j = 0;j<10;j++){
   	//fprintf(fp,"DNA list%d: ",j);
    for(i = 0;i<100;i++)
	fprintf(fp, "%c",rand()%26+'A');
	fprintf(fp,"\n");
   }
   
   char list[110];
   char pattern[]="J";
   printf("pattern字符串是:%s\n",pattern);
   fseek(fp, 0, SEEK_SET);
   printf("暴力查找算法：\n");
   i=0;
   char* tmp;
   while(fgets(list,110,fp)!=NULL){
   	//printf("%s test\n",list);
   	tmp = mystrstr(list,pattern);
   	if(tmp==NULL) printf("seq%d: %d\n",i,-1);
   	else printf("seq%d: %d\n",i,tmp-list);
   	i++;
   }
   //else printf("test\n");
   
	fseek(fp, 0, SEEK_SET);
	printf("\nKMP算法：\n");
	   i=0;
	   int NEXT[110];
	   while(fgets(list,110,fp)!=NULL){
	   	//printf("%s test\n",list);
	   	get_next(list,NEXT);
	   	printf("seq%d: %d\n",i,KMP(list,pattern,NEXT));
	   	i++;
	   }
	
   	fclose(fp);
   	return(0);
}