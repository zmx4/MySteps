#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct laptop
{
    int price;
    int quality;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin>>n;
    vector<laptop> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].price>>v[i].quality;
    }
    sort(v.begin(),v.end(),[](laptop a,laptop b){
        return a.price<b.price;
    });
    for(int i=0;i<n-1;i++)
    {
        if(v[i].quality>v[i+1].quality)
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<<"Poor Alex"<<endl;

	return 0;
}