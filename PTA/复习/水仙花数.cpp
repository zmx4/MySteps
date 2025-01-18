#include<iostream>
#include<math.h>
#include <string>
using namespace std;
int main(){
    int s;cin>>s;
    int i=pow(10,s);
    int im=pow(10,s+1);
    int sum=0;
    for(i;i<im;i++)
    {
        string strNumber = to_string(i);
        for(int j=0;j<s;j++)
        {
            sum+=pow(j,s);
        }
        if(sum==i)cout<<sum<<endl;
    }
}