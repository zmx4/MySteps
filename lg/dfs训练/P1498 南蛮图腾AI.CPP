#include <iostream>
#include <string>
#include <cmath>

// 定义基本图形单元
const std::string upper_triangle = " /\\ ";
const std::string lower_triangle = "/__\\";

// 递归函数绘制图腾
std::string drawTotem(int n) {
    if (n == 1) {
        return upper_triangle + lower_triangle;
    }

    std::string prev_totem = drawTotem(n - 1);
    std::string current_totem;

    // 计算前置空格数量
    int spaces_before = std::pow(2, n - 1) - 1;

    // 构建当前层级图腾
    for (int i = 0; i < prev_totem.length(); ++i) {
        current_totem += (i == 0? "" : "  ");
        current_totem += prev_totem[i];
    }

    current_totem += "  ";

    for (int i = 0; i < prev_totem.length(); ++i) {
        current_totem += prev_totem[i];
    }

    // 添加前置空格
    for (int i = 0; i < spaces_before; ++i) {
        current_totem = " " + current_totem;
    }

    return current_totem;
}

int main() {
    int n;
    std::cin >> n;

    std::string totem = drawTotem(n);

    // 按行输出图腾图形
    for (int i = 0; i < std::pow(2, n); ++i) {
        std::cout << totem.substr(i * totem.length() / std::pow(2, n), totem.length() / std::pow(2, n)) << std::endl;
    }

    return 0;
}