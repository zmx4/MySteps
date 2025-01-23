#include <iostream>
#include <cstdio>

int main()
{
	std::ios::sync_with_stdio(false); // 关闭同步
	std::cin.tie(nullptr);		 // 解绑定 cin 和 cout

	int a, b;
	std::cin >> a;		  // 使用 C++ 的输入
	std::scanf("%d", &b); // 使用 C 的输入

	std::cout << "a: " << a << std::endl;
	std::printf("b: %d\n", b);

	return 0;
}