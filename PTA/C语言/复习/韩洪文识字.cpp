#include <iostream>
using namespace std;
int main()
{
    int qwe;cin>>qwe;
    while(qwe--)
    {
        int length;cin>>length;
        char a[length];
        int k[122];
        scanf("%s",&a);
        for(int i=0;i<length;i++)
        {
            if(a[i]>'A'&&a[i]<'Z')
            {
                a[i] += 32;
            }
            int o=(int)a[i];
            k[o] += 1;
            cout<<o<<endl;
        }
        int qwq=0;
        for(int i=97;i<=122;i++)
        {
            if(k[i]>qwq)qwq=k[i];
        }
        printf("%d\n",qwq);
    }
}