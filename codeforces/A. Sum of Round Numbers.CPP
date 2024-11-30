#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin>>T;

    while (T--){
        string s;
        cin>>s;

        int t=0;
        for (int i=0;i<s.size();++i){
            if (s[i]=='0')
                continue;
            else
                t++;
        }
        cout<<t<<endl;

        for (int i=0;i<s.size();++i){
            if (s[i]=='0')
                continue;
            else{
                cout<<s[i];
                for (int j=i+1;j<s.size();++j)
                    cout<<"0";
                cout<<" ";
            }
        }
        cout<<endl;
    }
}