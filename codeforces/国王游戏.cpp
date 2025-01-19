#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct coin
{
    int left;
    int right;
    bool operator<(const coin& x) const
    {
        return max(x.right, left * right) < max(right, x.left * x.right);
    }
};

bool sortByMin(const  coin&a,const  coin&b)
{
    if (a.left != b.left)return max(b.right, a.right*a.left) < max(a.left, b.left*b.right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    coin king, minister[1005];
    cin >> king.left >> king.right;
    for (int i = 0; i < n; i++)
    {
        cin >> minister[i].left >> minister[i].right;
    }

    sort(minister, minister + n);

    long long int maxcoin = king.right, sum = king.right;
    for (int i = 0; i < n; i++)
    {
        //cout << minister[i].left << minister[i].right;

        maxcoin = max(maxcoin, sum / minister[i].right);

        sum *= minister[i].left;
    }
    cout << maxcoin;
    return 0;
}
