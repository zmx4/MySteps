void CharPyramid(int n, char ch) {
    for (int a; a <= n; a++) {
        for (int b = a - 1; b >= a; b -= 1) {
            printf(" ");
        }
        for (int c = 0; c < a; c++) {
            printf("G ");
        }
        printf("\n");
    }
}