#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) ones++;
    }
    
    // 构造转换数组：如果 a[i] 为 0，翻转后 +1；若为 1，翻转后 -1。
    vector<int> gain(n);
    for (int i = 0; i < n; i++){
        gain[i] = (a[i] == 0) ? 1 : -1;
    }
    
    // 使用 Kadane 算法求最大子数组和
    int best = gain[0];
    int current = gain[0];
    for (int i = 1; i < n; i++){
        current = max(gain[i], current + gain[i]);
        best = max(best, current);
    }
    
    // 如果 best < 0，说明所有元素都是 1，翻转必然会减少一个 1
    if(best < 0)
        cout << ones - 1 << endl;
    else
        cout << ones + best << endl;
    
    return 0;
}