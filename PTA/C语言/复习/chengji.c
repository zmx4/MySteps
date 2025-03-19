#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int score=0,p=0;
    scanf("%d",&p);
    int sa=0,sb=0,sc=0,sd=0,se=0;
    for (int a=1;a<=p;a++){
    	scanf("%d",&score);
    	/*
    	if(i<=60){
    	    se++;
    	}
    	else if(i<=70){
    	    sd++;
    	}
    	else if(i<=80){
    	    sc++;
    	}
    	else if(i<=90){
    	    sb++;
    	}
    	else {
    	    sa++;
    	}
    	*/
    	 if (score >= 90) {
            sa++;
        } else if (score >= 80) {
            sb++;
        } else if (score >= 70) {
            sc++;
        } else if (score >= 60) {
            sd++;
        } else {
            se++;
        }
    }
	
	//printf("%d\n",p);
	
	printf("%d %d %d %d %d",sa,sb,sc,sd,se);
}