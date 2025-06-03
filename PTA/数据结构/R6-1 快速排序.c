#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct
{
	KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
	int Length;
} SqList;
void CreatSqList(SqList *L); /*待排序列建立，由裁判实现，细节不表*/
int Partition(SqList L, int low, int high);
void Qsort(SqList L, int low, int high);
int main()
{
	SqList L;
	int i;
	CreatSqList(&L);
	Qsort(L, 1, L.Length);
	for (i = 1; i <= L.Length; i++)
		printf("%d ", L.elem[i]);
	return 0;
}
void Qsort(SqList L, int low, int high)
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);
		Qsort(L, low, pivotloc - 1);
		Qsort(L, pivotloc + 1, high);
	}
}
/*你的代码将被嵌在这里 */
void swap(KeyType *a, KeyType *b)
{
    KeyType temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(SqList L, int low, int high)
{
    int pivot = L.elem[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && L.elem[i] < pivot)
            i++;
        while (j > low && L.elem[j] > pivot)
            j--;
        if (i < j)
        {
            swap(&L.elem[i], &L.elem[j]);
            i++;
            j--;
        }
    }
    swap(&L.elem[low], &L.elem[j]);
    return j;
}