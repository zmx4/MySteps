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
	/*
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
    */
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] > maxNum)
		{
			maxNum = arr[i];
			maxPos = i;
		}
		/*
		if (arr[i] <= minNum) {
			minNum = arr[i];
			minPos = i;
		}
		*/
	}
	//cout<<minPos<<" "<<maxPos<<" "<<maxNum<<" "<<minNum<<endl;
	int c;
	for(c = 0;maxPos!=0;c++)
	{
          if(maxPos!=0)
          {
            swap(arr[maxPos-1],arr[maxPos]);
            maxPos--;
          	//for(int j=0;j<n;j++)cout<<arr[j]<<" ";
          	//cout<<endl;
          	continue;
          }
		  //cout<<i<<" ";
		/*
		  if(minPos!=n-1)
		  {
			  swap(arr[minPos],arr[minPos+1]);
		  	  for(int j=0;j<n;j++)cout<<arr[j]<<" ";
		  	  cout<<endl;
		  	  minPos++;
		  }
		  */
	}
	for (int j = 0;j<n;j++)
	{
		if (arr[j] <= minNum)
		{
			minNum = arr[j];
			minPos = j;
		}
	}
	for (;minPos!=n-1;c++)
	{
		if(minPos!=n-1)
		{
			swap(arr[minPos],arr[minPos+1]);
			//for(int j=0;j<n;j++)cout<<arr[j]<<" ";
			//cout<<endl;
			minPos++;
		}
	}
    //for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout<<c<<endl;
    return 0;
}
