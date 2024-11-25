#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int num[4];
	unordered_set<int> uniqueNumbers;
	for(int i=0;i<4;i++)
    {
		cin>>num[i];

        uniqueNumbers.insert(num[i]);

    }

	cout<<3-uniqueNumbers.size()<<endl;
}