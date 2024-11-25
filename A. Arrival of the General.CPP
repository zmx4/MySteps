//24-11-25 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int maxNum = INT_MIN,minNum = INT_MAX,maxPos,minPos;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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
      if(arr[i]<=minNum)
      {
      	minNum=arr[i];
        minPos=i;
      }
    }
	cout<<minPos<<" "<<maxPos<<" "<<maxNum<<" "<<minPos<<endl;
	int i;
	for(i = 0;maxPos!=0||minPos!=n-1;i++)
	{
          if(maxPos!=0)
          {
            swap(arr[maxPos-1],arr[maxPos]);
            maxPos--;
          	continue;
          }
		  //cout<<i<<" ";
		  if(minPos!=n-1)
		  {
			  swap(arr[minPos],arr[minPos+1]);
		  	  minPos++;
		  }
	}
    //for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout<<i<<endl;
    return 0;
}
