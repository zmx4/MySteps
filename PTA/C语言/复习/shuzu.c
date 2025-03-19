#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int a[6]={5,2,4,6,1,3};
	for(int i=0;i<6;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	
	for(int j=1;j<6;j++){
		int key=a[j];
		int i=j-1;
		while(i>=0&&a[i]>key){
			a[i+1]=a[i];
			i-=1;
		}
		a[i+1]=key;
	}

	/*
	    for (int j = 1; j < 6; j++) { // 注意这里从1开始，因为0可以认为已经是排序好的
        int key = a[j];
        int i = j - 1;

        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
	*/
	for(int i=0;i<6;i++){
		printf("%d",a[i]);
	}
}