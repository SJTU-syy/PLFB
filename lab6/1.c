#include<stdio.h>
int main()
{
    int n=0,length=0;
    int shuru[100];
    printf("输入数组长度：");
    scanf("%d",&n);
    printf("输入数组：");
    int i=0;
    for(i=0;i<n;i++){
		scanf("%d",&shuru[i]);
		length+=1;
		if(getchar()=='\n') break;
	  }
	
	int temp=0,pos=0,begin=0,end=0,sum=0;
	for(i=0;i<n;i++){
		temp+=shuru[i];
		if(temp<0){
			temp=0;
			pos=i+1;
		}
		if(temp>sum){
			end=i;
			begin=pos;
			sum=temp;
		}	
	} 
	if(sum==0){
        sum=shuru[0];
		for(i=0;i<n;i++){
			if(shuru[i]>sum){
				sum=shuru[i];
				begin=end=i;
			}
			
		}
	}
	printf("begin at %d,end at %d,maxsum=%d",begin,end,sum);
	return 0; 
}
