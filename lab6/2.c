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
	
	int j=0;
	int sum=shuru[0]-shuru[1];
	int little=0,large=1;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(shuru[i]-shuru[j]>sum){
				sum=shuru[i]-shuru[j];
				little=i;
				large=j;
			}
		}
	}
    
	printf("sum=%d,little=%d,large=%d",sum,little,large);
	return 0; 
}

//辅助数组法
#include<stdio.h>
int getmaxsum(int change[],int n,int *little,int *large){
	int temp=0,pos=0,sum=0;
	int i=0;
		for(i=0;i<n-1;i++){
			temp+=change[i];
			if(temp<0){
				temp=0;
				pos=i+1;
			}
			if(temp>sum){
				*large=i;
				*little=pos;
				sum=temp;
			}	
		} 
		if(sum==0){
			sum=change[0];
			for(i=0;i<n-1;i++){
				if(change[i]>sum){
					sum=change[i];
					*little=*large=i;
				}
				
			}
		}
		return sum;
}

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
	
	int little=0,large=0;
	int change[100];
	for(i=0;i<n-1;i++)
	change[i]=shuru[i]-shuru[i+1];
	int sum=getmaxsum(change,n,&little,&large);
	
	printf("sum=%d,begin=%d,end=%d",sum,little,large+1);
	return 0; 
}
