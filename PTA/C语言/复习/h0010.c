#include <stdio.h>

int main(){
    int a,b=0,c;
    
    //for(int o=0;o<2;o++){
        scanf("%d",&a);
        scanf("%d",&c);
        if(a>0){
        for (int i=1;i<=a;i++){
            b=b+i;
        }
        printf("%d\n",b);
    	}
    	else if(a<0){
        	for (int i=1;i>=a;i--){
        	    b=b+i;
        	}
        	printf("%d\n",b);
    	}
    	else{
        	printf("1\n");
    }
    //a=0;
    //}
    	b=0;
        if(c>0){
        	for (int i=1;i<=c;i++){
        	    b=b+i;
        	}
        	printf("%d\n",b);
    	}
    	else if(c<0){
        	for (int i=1;i>=a;i--){
        	    b=b+i;
        	}
        	printf("%d\n",b);
    	}
    	else{
        	printf("1\n");
    	}
}