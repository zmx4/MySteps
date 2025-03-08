#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void solve()
{
    char m[3][3];
    // 修改读取，遍历 j 从 0 开始
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> m[i][j];

    int r = -1, c = -1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(m[i][j]=='?'){
                r = i, c = j;
                break;
            }
        }
        if(r != -1)
            break;
    }
    // 根据所在行的情况确定缺失字母
    bool foundA = false, foundB = false, foundC = false;
    for(int j = 0; j < 3; j++){
        if(m[r][j]=='A') foundA = true;
        if(m[r][j]=='B') foundB = true;
        if(m[r][j]=='C') foundC = true;
    }
    char ans;
    if(!foundA) ans = 'A';
    else if(!foundB) ans = 'B';
    else ans = 'C';
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}