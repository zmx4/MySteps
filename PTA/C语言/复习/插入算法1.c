/*插入算法*/
#include <stdio.h>
#define N 9
int main() {
	int i=0, j=0; //循环变量慧
	//num 已排好序的数组
	//数组的大小比数组当前大小多1是为了给插入的数预留位置	
	//in 要插入的数字
	int num[N + 1] = { 1,4,7,13,16,19,22,25,28 }, in;
	//打印要插入的数组的所有元素
	printf("插入前的数组元素:");
	for (i = 0; i < N; i++) {
		printf(" %d ", num[i]);
	}
	//从键盘读取一个要插入的数
	printf("\n请输入一个要插入的数:");
	scanf_s("%d", &in);
	printf("\n%d\n",in);
	//先找要插入的位置
	/*

	for (i = 0; i < N; i++) {
		if (num[i] > in)//找到位置并跳出for循环
		{
			break;
		}
	}
	//移位，向后移位
	for (j = N; j > i; j--)
	{//为要插入的数字留出位置
		num[j] = num[j - 1];
	}
	num[i] = in;//将来插入的数保存在该位置
	//打印插入后的数组元素
	printf("\n插入后的数组元素:\n");
	*/

	for(i=0;i< N;i++){
		if(in<num[i]){
			break;
		}
	}
	for(j=N;j>i;j--){
		num[j]=num[j-1];
	}
	printf("\n%d\n",i);
	num[i]=in;
	for (i = 0; i < N + 1; i++)
	{
		printf(" %d ", num[i]);
	}
	printf("\n");
	return 0;
}
