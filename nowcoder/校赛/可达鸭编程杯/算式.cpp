#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int n,j=0;cin>>n;
	long long int a[2005]={0},b[2005]={0};
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
        if(a[i]==1)
        {
	        b[j]=i;
        	j++;
        }

    }
    int suma[2005]={1,1,1},sumb[2005]={1,1,1};
	//for(int i=0;i<j;i++)cout<<b[i]<<endl;
	for(int i=1;i<=j;i++)
    {
          for(int r=b[i-1];r<b[i];r++)
          {
            suma[i]*=a[r];
          }
          //sumb[i]+=suma[i];
    }
    for(int i=1;i<=j;i++)cout<<suma[i]<<" ";
	return 0;
}