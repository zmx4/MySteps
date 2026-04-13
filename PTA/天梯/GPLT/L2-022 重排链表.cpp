#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 存储节点的结构体
struct Node
{
    int address;
    int data;
    int next;
};

// 数组充当内存，直接通过地址下标访问节点，速度极快
Node mem[100005];

signed main()
{
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int start, n;
    if (!(cin >> start >> n))
        return 0;

    // 读取所有给定的节点
    for (int i = 0; i < n; i++)
    {
        int addr, data, next;
        cin >> addr >> data >> next;
        mem[addr] = {addr, data, next};
    }

    // 1. 从起点开始遍历，提取这条链上的所有有效节点
    vector<Node> link;
    int curr = start;
    while (curr != -1)
    {
        link.push_back(mem[curr]);
        curr = mem[curr].next;
    }

    // 2. 双指针交替排列（Ln -> L1 -> Ln-1 -> L2...）
    vector<Node> ans;
    int left = 0, right = link.size() - 1;

    while (left <= right)
    {
        if (left == right) // 奇数个节点，最中间的那个单独插一次
        {
            ans.push_back(link[left]);
            break;
        }
        ans.push_back(link[right]); // 先插入右边（尾部）
        ans.push_back(link[left]);  // 再插入左边（首部）
        right--;
        left++;
    }

    // 3. 按要求格式输出
    for (int i = 0; i < ans.size(); i++)
    {
        if (i < ans.size() - 1)
        {
            // 对于中间节点，下一个地址就是 ans 数组里下一个元素的地址
            cout << setw(5) << setfill('0') << ans[i].address << " "
                 << ans[i].data << " "
                 << setw(5) << setfill('0') << ans[i + 1].address << endl;
        }
        else
        {
            cout << setw(5) << setfill('0') << ans[i].address << " "
                 << ans[i].data << " -1\n";
        }
    }

    return 0;
}