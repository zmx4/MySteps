#include <iostream>
using namespace std;
int main(){
    int n,q,s[100000],as[100000];cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i];
        
        if(s[i]>as[i-1])
        {
            as[i]=s[i];
        }
        else
        {
        	as[i]=as[i-1];
		}
        cout<<as[i];
    }
    while(q--)
    {
        int p=0;
        cin>>p;
        cout<<as[p]<<endl;
    }
}