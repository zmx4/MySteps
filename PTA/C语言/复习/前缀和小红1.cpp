#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>q;
signed main(){
    int n;
    cin>>n;
    int a[100005];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=q[a[i]];
        cout<<sum<<" ";
        q[a[i]]++;
        cout<<q[a[i]]<<" "<<a[i]<<endl;
    }
    return 0;
}