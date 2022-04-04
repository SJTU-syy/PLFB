#include<bits/stdc++.h>
using namespace std;

/*
1. 
#define STR_LEN 80
char dna[STR_LEN + 1];
	it's a common parctice
	
2.char arrays and char pointers can be used as string,the difference is about the cotent of the pointer can't be changed
and if we want to use char* p as a string,we need to point it to an array of characters

3.认为string.h的函数总是可以维护字符串符合末尾有\0
*/

int main(){
	printf("123 , 1\
	take it.\n");
	printf("456 "
		"take it.\n");//发现\号等于空格,连着两个双引号内的内容会被直接连到一起
		
		
	const char* a = "dna" + 1;
	char b = "dna"[1];
	char c[] = "dna";
	char* d = c;
	
	cout<<a<<b<<'\n';  //输出是nan
	cout<<c[1]<<c+1<<d[1]<<d+1<<'\n';//输出是nnanna
	
	
	/*char* p = "dna";
	*p = 'a'; //试图修改会产生segmentation fault,c++直接不允许这种行为
	*/
	
	char* str = "hello";
	char str1[] = "hello";
	char str2[] = {'h','e','l','l','o'};
	printf("%s\n123",str);
	printf("%s\n456",str1);
	printf("%s\n789",str2);
	cout<<str2[4]<<str2[5]<<str[5]<<'\n'; //我也不知道为什么str2会翻倍,也许和C++特性有关,总之不要使用str2的写法-str[5]没有输出显示
	
	
	cout<<strlen(str)<<" "<<sizeof(str);//5 4
	
	char s[] = "AUG", s2[] = "ACGAUA";
		char s3[strlen(s) + strlen(s2) + 1];
		printf("%d\n", strlen(&s[1]));
	
		strcpy(s3, s);
		strcat(s3, s2);
		printf("%s\n", &s3[2]);
		printf("%d\n", strcmp(s, s2));//输出:2\GACGAUA\1,所以取地址符在这里十分有用,编译器会直接对其开头的字符串做处理

}