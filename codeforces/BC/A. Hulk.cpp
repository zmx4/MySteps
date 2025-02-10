
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
    string s = "";
    for(int i=1;i<n;i++)
    {
    	//cout<<"Please input a string:"<<endl;
     	if(i%2==1)s+="I hate that ";
    	if(i%2==0) s+="I love that ";
    }
	if(n%2==1)s+="I hate it";
	else if(n%2==0) s+="I love it";
	cout<<s;
}