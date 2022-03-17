#include<stdio.h>

int daojiechen(int a,int b){
	int i = a+1;
	int c = 1;
	while(i<=b){
		c*=i;
		i++;
	}
	return c;
}
int main(){
	int n;
	scanf("%d",&n);
	int t;
	int sum = 0;
	for(t = 1;t <= n-1;t++){
		sum+=daojiechen(t,n);
	}
	printf("%d/%d",sum+1,daojiechen(0,n));
	return 0;
}