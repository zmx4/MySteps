#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int inputs[10]; // 存储用户输入的数组
    int count = 0;  // 记录查询次数的计数器
    int input;      // 单个输入的临时变量

    // 显示菜单
    printf("[1] apple\n"
           "[2] pear\n"
           "[3] orange\n"
           "[4] grape\n"
           "[0] exit\n");

    // 读取用户输入的序列
    for (int i = 0; i < 10; i++) { // 假设最多读取10个输入
        scanf("%d", &input);
        if (input == 0) {
            break; // 如果输入为0，立即退出循环
        }
        if (count < 5) { // 只有在查询次数少于5次时才处理输入
            inputs[count++] = input;
        }
    }

    // 根据输入打印价格信息
    for (int i = 0; i < count; i++) {
        switch (inputs[i]) {
            case 1:
                printf("price = %.2f\n", 3.00);
                break;
            case 2:
                printf("price = %.2f\n", 2.50);
                break;
            case 3:
                printf("price = %.2f\n", 4.10);
                break;
            case 4:
                printf("price = %.2f\n", 10.20);
                break;
            default:
                printf("price = %.2f\n", 0.00);
                break;
        }
    }

    return 0;
}