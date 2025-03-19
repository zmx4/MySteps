#include <stdio.h>
int main(void) {
    int p[7] = {11, 13, 14, 15, 16, 17, 18};
    int i = 0, j = 0;
    while (i < 7 && p[i] % 2 == 1)j += p[i++];
    printf("%d\n", j);
    return 0;
}