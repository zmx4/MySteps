#include <stdio.h>
#include <math.h>

int main(){
    int u;
    scanf("%d",&u);
    for (int ui=0;ui<u;ui++){
        int n,c,k,Num;
        char isVIP;
        scanf("%d %d %d",&n,&c,&k);
        for(int ni=0;ni<n-1;n++){
            scanf("%d %c",&Num,&isVIP);
            if(Num>k){
            	c--;
			}
			else if(Num<k&&isVIP=='Y'){
				c-=2;
			}
        }
        if (c>=0){
        	printf("heihei");
		}
		else{
			printf("awsl");
		}
    }
}