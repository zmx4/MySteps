#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#include<assert.h>
#include<ctype.h>
#include<time.h>
#include<unistd.h>
#include<stdint.h>
#define MAXN 1000000

typedef struct
{
	int64_t *elem;
	int length;
} SqList;

void create(SqList *L, int n)
{
	L->elem = (int64_t *)malloc(n * sizeof(int64_t));
	L->length = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &L->elem[i]);
	}
}

SqList merge(SqList a, SqList b)
{
	SqList c;
	c.elem = (int64_t *)malloc((a.length + b.length) * sizeof(int64_t));
	c.length = a.length + b.length;
	int i = 0, j = 0, k = 0;
	while (i < a.length && j < b.length)
	{
		if (a.elem[i] < b.elem[j])
		{
			c.elem[k++] = a.elem[i++];
		}
		else
		{
			c.elem[k++] = b.elem[j++];
		}
	}
	while (i < a.length)
	{
		c.elem[k++] = a.elem[i++];
	}
	while (j < b.length)
	{
		c.elem[k++] = b.elem[j++];
	}
	return c;
}

void print(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%lld ", L.elem[i]);
	}
	printf("\n");
}

signed main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	SqList a, b;
	create(&a, n);
	create(&b, m);
	SqList c = merge(a, b);
	print(c);
	free(a.elem);
	free(b.elem);
	free(c.elem);
	return 0;
}