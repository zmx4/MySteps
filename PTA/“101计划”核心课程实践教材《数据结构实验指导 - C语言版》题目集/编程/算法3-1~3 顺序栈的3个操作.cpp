#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int totalPush = n + 1;
	vector<int> st; // 模拟栈
	int x;
	// 顺序压入 totalPush 个整数，若栈满则输出错误信息
	for (int i = 0; i < totalPush; i++)
	{
		cin >> x;
		if (st.size() == (size_t)n)
		{
			cout << "错误：栈已满。" << "\n";
			// 不执行入栈操作
		}
		else
		{
			st.push_back(x);
		}
	}

	// 执行 totalPush 次取顶并出栈操作
	for (int i = 0; i < totalPush; i++)
	{
		// 先执行取顶操作
		if (st.empty())
		{
			cout << "错误：栈为空。" << "\n";
			cout << -1 << "\n";
		}
		else
		{
			cout << st.back() << "\n";
		}
		// 再执行出栈操作
		if (st.empty())
		{
			cout << "错误：栈为空。" << "\n";
		}
		else
		{
			st.pop_back();
		}
	}

	return 0;
}