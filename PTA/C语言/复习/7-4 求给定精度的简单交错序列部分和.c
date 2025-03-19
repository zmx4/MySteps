#include <stdio.h>
#include <math.h>

int main() {
    double eps, sum = 0.0, term = 1.0;
    int n = 1;  // 序列的第一项为1，对应的n值为1
    int sign = 1;  // 控制加减号的变量，初始化为正号

    // 读取精度值
    scanf("%lf", &eps);

    // 循环计算序列和
    while (fabs(term) > eps) {
        sum += sign * term;  // 将当前项加入总和
        n += 3;  // 下一项的分母比当前项多3
        sign *= -1;  // 改变符号
        term = 1.0 / n;  // 计算下一项的值
    }

    // 输出结果，保留六位小数
    printf("sum = %.6f\n", sum);

    return 0;
}