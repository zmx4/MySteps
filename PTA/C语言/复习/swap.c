#include <stdio.h>
void swap(int *x,int *y);
int main() {
    int x;
    int y;
    x = 20;
    y = 16;
    printf("x = %d\ny = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}

void swap(int *a, int *b) {
    int temp;

    temp =*a;
   
	*a = *b;
    
	*b = temp;
}