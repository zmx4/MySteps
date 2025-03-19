#include <stdio.h>
int main(){
    int A[8] = {2,4,5,7,1,2,3,6};
    int p = 0, q = 3, r = 7;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Allocate the correct size for B1 and B2.
    int B1[n1], B2[n2];

    // Fill B1 and B2 using n1 and n2 as limits.
    for(int i = 0; i < n1; i++){
        B1[i] = A[p + i];
    }
    for(int i = 0; i < n2; i++){
        B2[i] = A[q + i + 1];
    }

    int i = 0, j = 0;
    for(int k = p; k <= r; k++){//n2=4
        if(i < n1 && (j >= n2 || B1[i] <= B2[j])){
            A[k] = B1[i];
            printf("a%d",B1[i]);
            i++;
        } else {
            A[k] = B2[j];
            printf("b%d",B2[j]);
            j++;
        }
    }

    // Print the sorted array.
    for(int y = 0; y <= r; y++){
        printf("%d ", A[y]);
    }
    printf("\n");

    return 0;
}