#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int kMaxSize = 1e5 + 10;
class ArrNode
{
public:
    vector<int> data_; // 使用vector来动态管理数组大小
    int size_;         // 数组的大小
    explicit ArrNode(int n) : size_(0), data_(vector<int>(n)) {}
};
int main()
{
    int n, x;
    cin >> n;
    ArrNode array(kMaxSize);
    array.size_ = n;
    for (int i = 0; i < n; i++)
    {
        cin >> array.data_[i];
    }
    cin >> x;
    if (!DecrSeqInsert(array, x))
    {
        cout << "Insertion failed." << endl;
    }
    for (int i = 0; i < array.size_; i++)
    {
        if (i > 0)
            cout << " ";
        cout << array.data_[i];
    }
    cout << endl;
    cout << "Array size = " << array.size_ << endl;
    return 0;
}
bool DecrSeqInsert(ArrNode &array, int x)
{
    if (array.size_ >= kMaxSize)
    {
        return false; // 数组已满，插入失败
    }
    int i = 0;
    while (i < array.size_ && array.data_[i] > x)
    {
        i++;
    }
    if (array.data_[i] == x)
        return false; // 元素已存在，插入失败
    for (int j = array.size_; j > i; j--)
    {
        array.data_[j] = array.data_[j - 1];
    }
    
    array.data_[i] = x;
    array.size_++;
    return true; // 插入成功
}