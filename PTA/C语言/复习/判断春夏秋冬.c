#include<stdio.h>
	int main() {
		printf("请输入月份:");
		int month;
		scanf_s("%d",&month);
		switch (month) {//整型 字符 Enum枚举
			case 1:
			case 2:
			case 3:printf("春"); break;
			case 4:
			case 5:
			case 6:printf("夏"); break;
			case 7:
			case 8:
			case 9:printf("秋"); break;
			case 10:
			case 11:
			case 12:printf("冬"); break;
			default:printf("没有当前月"); break;
		}
		return 0;
	}