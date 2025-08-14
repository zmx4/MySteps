#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int n;cin>>n;
    vector<string>fileName(n);
    for(int i = 0; i < n; i++) {
        cin >> fileName[i];
    }
    string outputFileName;
    cin >> outputFileName;
    set<int,greater<int>()> num;
    for(auto &s : fileName) {
        ifstream in(s);
        while(getline(in, s)) 
        {
            num.insert(stoi(s));
        }
        in.close();
    }
    ofstream out(outputFileName);
    for(auto &x : num) {
        out << x << endl;
    }
    out.close();
    // cout << "Output file: " << outputFileName << endl;
    // cout << "Total unique numbers: " << num.size() << endl;
    // cout << "Numbers written to the output file." << endl;
    return 0;
}