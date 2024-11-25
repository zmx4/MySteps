//24-11-25 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int maxNum = INT_MIN,minNum = INT_MAX,maxPos,minPos;
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if(arr[i]>maxNum)
      {
      	maxNum=arr[i];
        maxPos=i;
      }
      if(arr[i]<minNum)
      {
      	minNum=arr[i];
        minPos=i;
      }
    }

    return 0;
}
