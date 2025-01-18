#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,low,std;cin>>a>>b>>c>>d>>low>>std;
    int maxNumber = max(max(a,b),max(c,d)),minNUmber = min(min(a,b),min(c,d));
    int signa = 0,signb = 0,signc = 0,signd = 0,sign = 0;
    if(a<low||a<maxNumber-std){signa = 1;sign++;}
    if(b<low||b<maxNumber-std){signb = 1;sign++;}
    if(c<low||c<maxNumber-std){signc = 1;sign++;}
    if(d<low||d<maxNumber-std){signd = 1;sign++;}
    if(sign==1)
    {   
        if(signa==1)cout<<"Warning: please check #1!";
        if(signb==1)cout<<"Warning: please check #2!";
        if(signc==1)cout<<"Warning: please check #3!";
        if(signd==1)cout<<"Warning: please check #4!";
    }
    else if(sign==0)
    {
        cout<<"Normal";
    }
    else
    {
        cout<<"Warning: please check all the tires!";
    }
}