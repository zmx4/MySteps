#include <bits/stdc++.h>
using namespace std;

// 后缀自动机状态结构
struct State
{
	// edges 用 map<int, int> 也可以，但 unordered_map / 数组都行
	// 对于大范围值可用 map，保证不越界； 对于紧凑值可用 vector 等
	// 这里以 map 演示
	map<int, int> edges;
	int link;		  // 后缀链接
	int length;		  // 状态所表示的最长子串长度
	int endpos_count; // 该状态中子串出现的终止位置个数（用于统计出现次数）
};

class SuffixAutomaton
{
public:
	vector<State> st;
	int last; // 指向自动机中表示整个前缀的状态

	// 预留空间，避免动态扩容过多
	SuffixAutomaton(int n)
	{
		st.resize(2 * n + 5);
		// 初始化第一个状态
		st[0].link = -1;
		st[0].length = 0;
		st[0].endpos_count = 0;
		last = 0; // 当前最后一个状态的下标
		size = 1; // 当前已使用的状态数量
	}

	// 向自动机中添加一个元素 (相当于向字符串/数组后面加字符)
	void extend(int c)
	{
		int cur = size++;
		st[cur].length = st[last].length + 1;
		st[cur].endpos_count = 1; // 每新建一个状态，默认最少出现一次

		// 尝试沿着旧状态的边往后找
		int p = last;
		for (; p != -1 && !st[p].edges.count(c); p = st[p].link)
		{
			st[p].edges[c] = cur;
		}

		// 如果 p == -1，说明没有可继续匹配的边，cur 的 link 指向 0
		if (p == -1)
		{
			st[cur].link = 0;
		}
		else
		{
			// 找到了一个拥有 c 边的状态 q
			int q = st[p].edges[c];
			// 如果能直接把 link 连上就行
			if (st[p].length + 1 == st[q].length)
			{
				st[cur].link = q;
			}
			else
			{
				// 否则需要克隆一个状态 clone，用来插入 cur 和 q 之间
				int clone = size++;
				st[clone].length = st[p].length + 1;
				st[clone].edges = st[q].edges;
				st[clone].link = st[q].link;
				st[clone].endpos_count = 0; // 克隆出来的状态，endpos_count = 0

				// 修正原有的指向关系
				for (; p != -1 && st[p].edges[c] == q; p = st[p].link)
				{
					st[p].edges[c] = clone;
				}
				// 更新 cur 和 q 的 link
				st[q].link = clone;
				st[cur].link = clone;
			}
		}
		// 更新 last
		last = cur;
	}

	// 统计所有状态的 endpos_count
	// 原理: 子串出现次数由最短的 (link) 长度关系决定，需要从长到短累加
	void build_endpos_count()
	{
		// 按照长度对状态进行排序，方便从长到短累加出现次数
		vector<int> order(size);
		iota(order.begin(), order.begin() + size, 0);
		sort(order.begin(), order.begin() + size, [&](int a, int b)
			 { return st[a].length > st[b].length; });
		// 从长串向短串转移出现次数
		for (int i = 0; i < size; i++)
		{
			int v = order[i];
			if (st[v].link != -1)
			{
				st[st[v].link].endpos_count += st[v].endpos_count;
			}
		}
	}

	// 统计只出现一次 (exactly once) 的所有子串数量
	long long count_substrings_appear_once()
	{
		// build_endpos_count() 在构建完成后缀自动机后调用
		build_endpos_count();

		long long result = 0;
		// 求每个状态对不同子串的贡献数
		// 对于状态 v，其贡献的“新”子串数量为 (st[v].length - st[ link[v] ].length)
		// 如果 endpos_count == 1，表示该状态所有子串都只出现一次，全部计入
		for (int v = 1; v < size; v++)
		{
			if (st[v].endpos_count == 1)
			{
				int par = st[v].link;
				// 该状态代表的新子串数量
				int diff_len = st[v].length - st[par].length;
				result += diff_len;
			}
		}
		return result;
	}

private:
	int size; // 当前使用了多少个状态
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 示例：输入一个数组，构建后缀自动机，计算只出现过一次的子区间数量
	// 这里以简单的输入示例演示
	int n;
	cin >> n;
	vector<int> arr = {1, 2, 1, 3, 2, 1, 4, 4, 5, 2, 6, 8, 4, 5, 2, 3, 0, 5, 4, 8, 6, 9, 5, 2, 4};
	// for (int i = 0; i < n; i++)
	// {
		// cin >> arr[i];
	// }

	SuffixAutomaton sam(n);
	// 构建后缀自动机
	for (int i = 0; i < n; i++)
	{
		sam.extend(arr[i]);
	}

	// 统计只出现一次的所有子区间数目
	long long ans = sam.count_substrings_appear_once();
	cout << ans << "\n";
	return 0;
}