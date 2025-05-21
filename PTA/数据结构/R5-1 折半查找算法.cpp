#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct
{
	KeyType *data; /*表基址*/
	int length;	   /*表长*/
} SSTable;
void CreatSSTable(SSTable *ST); /*有序表创建，由裁判实现，细节不表*/
int BiSearch(SSTable ST, KeyType e, int low, int high);
int main()
{
	SSTable ST;
	int n, result, i;
	KeyType e;
	CreatSSTable(&ST);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &e);
		result = BiSearch(ST, e, 1, ST.length);
		if (result)
			printf("%d is found\n", e);
		else
			printf("%d is not found\n", e);
	}
	return 0;
}
int BiSearch(SSTable ST, KeyType e, int low, int high)
{
	int mid;
	if (low > high)
		return 0;
	mid = (low + high) / 2;
	if (ST.data[mid] == e)
		return mid;
	if (e < ST.data[mid])
		return BiSearch(ST, e, low, mid - 1);
	else
		BiSearch(ST, e, mid + 1, high);
}