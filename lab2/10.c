#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[]){
	char* s = argv[1];
	int length = strlen(s);
	int INT0 = 0;
	int temp0 = 0;
	int INT1 = 0;
	int BINARY[33];
	
	//const char* -> int
	while(temp0<length){
		INT0 = *(s+temp0)-48;
		INT1 = INT1*10 + INT0;
		temp0+=1;
	}
	
	
	//十进制int -> int[]代表的二进制;
	temp0 = 0;
	while(INT1){
		BINARY[temp0++] =INT1%2;
		INT1 /= 2;
	}
	
	for(int i = temp0-1;i>=0;i--){
		printf("%d",BINARY[i]);
	}
	
	return 0;
}