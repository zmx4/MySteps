#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void moveOnesToFront(int arr[], const int &size) {
	int writeIndex = 0;

	for (int readIndex = 0; readIndex < size; ++readIndex) {
		if (arr[readIndex] == 1) {
			swap(arr[writeIndex], arr[readIndex]);
			++writeIndex;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int n,j=0;cin>>n;
	long long int a[2005]={0},b[2005]={0},c[2005]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=0;i<n;i++)
    {	
		if(a[i]==1&&(a[i-1]!=1||i==0))
		{
			b[j]=i;
			j++;
		}
		if(a[i]==1&&a[i-1]==1)
		{
			a[i-1]=0;
           	a[i]=2;
		}
    }
	//for(int i=0;i<n;i++)cout<<a[i]<<" ";
	long long int suma[2005]={1},sumb[2005]={1,1,1};
	for(int i=0;i<=2004;i++)suma[i]=1;
	int k = 0;
	for(int i=0;i<n;i++)
	{
		if (a[i]==0)continue;
		else
		{
			suma[k]*=a[i];
		}
		if(a[i]==1)
		{
			suma[k]++;
			k++;
		}
	}
	long long int sumw=1;
	for(int i=0;i<=k;i++)
	{
		sumw*=suma[i];
	}
	cout<<sumw%1000000007<<" ";

	sort(c,c+n);

	long long int temp = 0;long long int sign = 0;
	long long int sumq = 0;
	for(int i=0;i<n;i++)
	{
		if(sumq+c[i]>sumq*c[i])sumq=sumq+c[i];
		else if(sumq+c[i]<sumq*c[i])sumq*=c[i];
	}
	if(sumq>sumw)cout<<sumq%1000000007<<endl;
        else cout<<sumw%1000000007<<endl;
	return 0;
}