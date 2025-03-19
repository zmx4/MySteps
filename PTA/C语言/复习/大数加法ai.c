#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char First[100], Second[100];
    char *longer, *shorter;
    int length, length2, num, carry = 0;

    // 输入两个字符串
    scanf("%s", First);
    scanf("%s", Second);

    // 确定较长和较短的字符串
    if (strlen(First) < strlen(Second)) {
        shorter = First;
        longer = Second;
        length = strlen(First);
        length2 = strlen(Second);
    } else {
        shorter = Second;
        longer = First;
        length = strlen(Second);
        length2 = strlen(First);
    }

    // 结果字符串的长度可能比最长的输入字符串多一位
    char result[length2 + 1] = {};

    // 从右向左处理字符串
    for (int i = 0; i < length; i++) {
        num = (shorter[length - 1 - i] - '0') + (longer[length2 - 1 - i] - '0') + carry;
        result[length2 - i] = (num % 10) + '0';
        carry = num / 10;
    }

    // 处理剩余的较长字符串部分
    for (int i = length; i < length2; i++) {
        num = (longer[length2 - 1 - i] - '0') + carry;
        result[length2 - i] = (num % 10) + '0';
        carry = num / 10;
    }

    // 如果还有进位，添加到结果字符串的最前面
    if (carry > 0) {
        result[0] = carry + '0';
    }

    // 输出结果字符串
    for (int i = 0; i <= length2; i++) {
        if (result[i] != '\0') {
            printf("%c", result[i]);
        }
    }

    return 0;
}