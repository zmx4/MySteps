#include <bits/stdc++.h>
using namespace std;
int main()
{
    int maxpos,minpos,maxnum = INT_MIN,minnum = INT_MAX;
	int n;cin>>n;
    int a[20];
	for(int i = 0;i < n;i++)
	{
        cin>>a[i];
		int num = a[i];
	}
	
	for(int i = 0;i < n;i++)
	{
		if(a[i] > maxnum)
		{
			maxnum = a[i];
			maxpos = i;
		}
		
	}
	swap(a[n-1],a[maxpos]);
	for(int i = 0;i < n;i++)
	{
		if(a[i] < minnum)
		{
			minnum = a[i];
			minpos = i;
		}
	}
	swap(a[0],a[minpos]);
	for(int i = 0;i < n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}