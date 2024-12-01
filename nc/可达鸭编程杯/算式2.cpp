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
		if(a[i]==1&&(a[i-1]!=1||i==0))
		{
			b[j]=i;
			j++;
		}
        if(a[i]==1&&a[i-1]==1)
        {
          a[i-1]=0;a[i]=2;
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
			//cout<<suma[k]<<" ";
		}
		if(a[i]==1)
		{
			suma[k]++;
			//cout<<a[i]<<" ";
			k++;
			//cout<<endl;
		}
	}
	long long int sumw=1;
	for(int i=0;i<=k;i++)
	{
		sumw*=suma[i];
		//cout<<suma[i]<<" ";
		//cout<<suma<<endl;
	}
	if (sumw<1000000007)cout<<sumw<<" ";
	else cout<<sumw%1000000007<<" ";

	sort(c,c+n);
	/*
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<" ";
	}
	*/
	long long int temp = 0;long long int sign = 0;
	long long int sumq = 0;
	for(int i=0;i<n;i++)
	{
		if(c[i]==1)
		{
			temp++;
		}
		else if(c[i]==2 && sign == 0)
		{
			sign = 1;
			sumq+=c[i]+temp;
			//cout<<sumq<<endl;
		}
		else if(c[i]>2 && sign == 0)
		{
			sign = 1;
			sumq+=temp;
			sumq*=c[i];
			//cout<<sumq<<endl;
		}
		else if(c[i]!=1 && sign == 1)
		{
			sumq*=c[i];
			//cout<<sumq<<endl;
		}
	}
	if (sumw<1000000007)cout<<sumq<<endl;
	else cout<<sumq%1000000007<<endl;
	return 0;
}