#include <iostream>

int main() {
    for (int i = 0; i < 10; ++i) {
        //if (i % 3 == 0) { // 当i是3的倍数时跳过接下来的两次迭代
            i++; // 增加i以跳过下一次迭代
            continue;
        //}
        std::cout << i << std::endl;
    }

    return 0;
}