#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
struct Node
{
	int data, nextpos;
	bool removed = false; // 标记是否被删除
};
vector<Node> l(N);		 // 初始化向量大小
unordered_set<int> seen; // 用于跟踪已经出现过的绝对值

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int L, N;
	cin >> L >> N;
	for (int i = 0; i < N; i++)
	{
		int addr;
		cin >> addr;
		cin >> l[addr].data >> l[addr].nextpos;
	}

	// 第一次遍历：标记需要删除的节点
	for (int curr = L; curr != -1; curr = l[curr].nextpos)
	{
		int absValue = abs(l[curr].data);
		if (seen.find(absValue) != seen.end())
		{
			l[curr].removed = true;
		}
		else
		{
			seen.insert(absValue);
		}
	}

	// 构建去重链表和被删除链表
	int uniqueHead = -1, uniqueTail = -1;
	int removeHead = -1, removeTail = -1;

	for (int curr = L; curr != -1; curr = l[curr].nextpos)
	{
		if (l[curr].removed)
		{
			// 加入删除链表
			if (removeHead == -1)
			{
				removeHead = curr;
			}
			else
			{
				l[removeTail].nextpos = curr;
			}
			removeTail = curr;
		}
		else
		{
			// 加入去重链表
			if (uniqueHead == -1)
			{
				uniqueHead = curr;
			}
			else
			{
				l[uniqueTail].nextpos = curr;
			}
			uniqueTail = curr;
		}
	}

	// 设置两个链表的尾部
	if (uniqueTail != -1)
		l[uniqueTail].nextpos = -1;
	if (removeTail != -1)
		l[removeTail].nextpos = -1;

	// 输出去重后的链表
	for (int curr = uniqueHead; curr != -1; curr = l[curr].nextpos)
	{
		cout << setw(5) << setfill('0') << curr << " " << l[curr].data << " ";
		if (l[curr].nextpos == -1)
			cout << "-1" << endl;
		else
			cout << setw(5) << setfill('0') << l[curr].nextpos << endl;
	}

	// 输出被删除的链表
	for (int curr = removeHead; curr != -1; curr = l[curr].nextpos)
	{
		cout << setw(5) << setfill('0') << curr << " " << l[curr].data << " ";
		if (l[curr].nextpos == -1)
			cout << "-1" << endl;
		else
			cout << setw(5) << setfill('0') << l[curr].nextpos << endl;
	}

	return 0;
}