#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a;
        int sign=0;
        cin >> a;
        int k=0;
        for(int i=0;i<a.length();i++)
        {
        	if(a[i] == '9')continue;
        	if(a[i] != '9')
        	{
        		//a[i]+=1;
        		//sign++;
        		//break;
        		k=i;
			}
		}
		if(k!=0)
		{
			a[k]+=1;
        	sign++;
		}
		if(sign==0)
		{
			//string b = a+"0";
			a.push_back('0');
			cout<<a<<endl;
			continue;
		}
		else
		{
			cout<<a<<endl;
		}
    }
    return 0;
}