#include<stdio.h>

int main()
{
    int n=0,length=0;
    int shuru[100];
    printf("输入数组长度：");
    scanf("%d",&n);
    printf("输入升序数组：");
    int i=0,j=0;
    for(i=0;i<n;i++){
		scanf("%d",&shuru[i]);
		length+=1;
		if(getchar()=='\n') break;	
	}
	int s;
	int little[100],large[100];
	int leng=0;
	printf("输入给定和s：");
	scanf("%d",&s);
    
    //暴力法
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(shuru[i]+shuru[j]==s){
				little[leng]=i;
				large[leng]=j;
				leng+=1;
			}
			
		}
	}
    
    //逐步求解
    i=0;
	int j=n-1;
	int flag=1;
	while(i!=j){
		if(shuru[i]+shuru[j]==s){
			little[leng]=i;
			large[leng]=j;
			if(shuru[j+1]==shuru[j]&&j+1<n){//判断数组元素是否重复
				flag+=1;
			}
			else flag=1;
			leng++;
			j--;
		}
		else if(shuru[i]+shuru[j]>s){
			j--;
		}
		else {
			i++;
			j=j+flag;
		}
	}
    
    
	for(i=0;i<leng;i++){
		printf("%d,%d\n",little[i],large[i]);
	}
	return 0; 
}
