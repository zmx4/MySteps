#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    int i=0,a=0;
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
    do{
        scanf("%d",&i);
        if(i==1){
            printf("price = 3.00\n");
        }
        else if(i==2){
            printf("price = 2.50\n");
        }
        else if(i==3){
            printf("price = 4.10\n");
        }
        else if(i==4){
            printf("price = 10.20\n");
        }
        else if(i==0){
            break;
        }else{
            printf("price = 0\n");
        }
        a++;
    }while(a<5);
    
}