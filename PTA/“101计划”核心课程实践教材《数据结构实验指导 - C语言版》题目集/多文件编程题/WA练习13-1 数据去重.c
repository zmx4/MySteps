#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105
#define MAX_NUMS 100000

long long numbers[MAX_NUMS]; // 存储所有整数
int count = 0;               // 实际存储的整数数量

// 比较函数用于qsort
int compare(const void *a, const void *b)
{
    long long diff = *(long long *)b - *(long long *)a; // 降序排列
    if (diff > 0)
        return 1;
    if (diff < 0)
        return -1;
    return 0;
}

int main()
{
    int k;
    scanf("%d", &k);
    getchar();

    char filenames[N][N];

    for (int i = 0; i < k; i++)
    {
        fgets(filenames[i], N, stdin);
        filenames[i][strcspn(filenames[i], "\n")] = '\0';
    }

    char outfile[N];
    fgets(outfile, N, stdin);
    outfile[strcspn(outfile, "\n")] = '\0';

    FILE *file;
    for (int i = 0; i < k; i++)
    {
        file = fopen(filenames[i], "r");
        if (file == NULL)
        {
            printf("Cannot open file %s\n", filenames[i]);
            continue;
        }

        long long num;
        while (fscanf(file, "%lld", &num) == 1)
        {
            numbers[count++] = num;
        }

        fclose(file);
    }
    qsort(numbers, count, sizeof(long long), compare);

    file = fopen(outfile, "w");
    if (file == NULL)
    {
        printf("Cannot open output file %s\n", outfile);
        return 1;
    }

    if (count > 0)
    {
        fprintf(file, "%lld\n", numbers[0]);
        for (int i = 1; i < count; i++)
        {
            if (numbers[i] != numbers[i - 1])
            {
                fprintf(file, "%lld\n", numbers[i]);
            }
        }
    }

    fclose(file);

    return 0;
}