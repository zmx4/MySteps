#include <stdio.h>
#include <math.h>

int main() {
    double input;
    int out;
    scanf("%lf", &input);
    out = (int)floor(input);
    printf("整数部分是: %d\n", out);
    return 0;
}