#include<stdio.h>

void quickSort(int *number, int first, int last) {
    int i, j, random;
    int temp;
    if (first<last) {
        random = first;
        i = first;
        j = last;
        while (i<j) {
            while (number[i] <= number[random] && i<last)
                i++;
            while (number[j]>number[random])
                j--;
            if (i<j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[random];
        number[random] = number[j];
        number[j] = temp;
        quickSort(number, first, j - 1);
        quickSort(number, j + 1, last);
    }
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
	
    //选择排序法感觉和冒泡排序差不多，这里似乎是冒泡排序
	int j=0;
	int tmp=0;
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(shuru[j]>shuru[j+1]){
				tmp=shuru[j];
				shuru[j]=shuru[j+1];
				shuru[j+1]=tmp;
			}
			
		}
	}
    
    //快速排序法
    quickSort(shuru,0,n-1);
    
	for(i=0;i<n;i++){
		printf("%d ",shuru[i]);
	}
	return 0; 
}
