#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int a[6]={31,41,59,26,41,58};
	for(int i=0;i<6;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	
	for(int j=1;j<6;j++){
		int key=a[j];                    //key=a[1]=41  key=a[3]=26
		int i=j-1;                       //i=0          i=2
		while(i>=0&&a[i]>key){           //NO    		YES
			//printf("%d\n",a[i]);        
			a[i+1]=a[i];                 //				a[3]=a[2]=59 i=1
			//printf("%d\n",a[i]);						a[2]=a[1]=41 i=0
			//printf("%d\n",a[i]+1);					a[1]=a[0]=31 i=-1
			i-=1;						 //		
		}
		a[i+1]=key;                       //a[1]=41     a[0]=26
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