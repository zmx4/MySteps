#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int a[MAXSIZE];
void NewArrayToMove(int *a, int n, int m)
{
    m %= n; // 取余节省步骤
    int *b = malloc(sizeof(int ) * n);
    for (int i = m - 1; i < n; i++)
    {
        b[i - m + 1] = a[i];
    }
    for(int i = 0; i < m; i++)
    {
        b[n - m + i] = a[i];
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void moveElements(int *a, int n, int m)
{
    if (n <= 0) 
        return;
    m %= n;      /* 保证 0 ≤ m < n */
    if (m == 0) 
        return;
    /* 右移 m 等价于左移 n-m；为减少移动量，取较小的那一边 */
    if (m > n/2)
        NewArrayToMove(a, n, n - m);
    else
        NewArrayToMove(a, n, m);
}
signed main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    NewArrayToMove(a, n, m);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}