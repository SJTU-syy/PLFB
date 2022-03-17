#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[]){
	char* s1 = argv[1];
	char* s2 = argv[2];
	if(strstr(s1,s2)) printf("yes");
	else printf("no");
	return 0;
}