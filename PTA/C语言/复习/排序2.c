#include <stdio.h>
int main(){
	//printf("a");
    int A[8]={2,4,5,7,1,2,3,6};
	int p=0,q=3,r=7;
    int n1=q-p+1;
    //printf("%d\n",n1);
	int n2=r-q;
    int B1[4],B2[4];
    for(int i=0;i<n1;i++){
        B1[i]=A[i];
    }
    for(int i=0;i<n2;i++){
        B2[i]=A[q+i+1];
    }
    //for(int y=0;y<4;y++){
    //    printf("%d ",B1[y]);
    //}
    int i=0,j=0;
    int s=0;
    for(int k=p;k<=r;k++){
        if(B1[i] <= B2[j]||j>=4){
            A[k] = B1[i];
            i++;
        } else {
            A[k] = B2[j];
            j++;
        }
    }
    for(int y=0;y<=r;y++){
        printf("%d ",A[y]);
    }

    return 0;
}