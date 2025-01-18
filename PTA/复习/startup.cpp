
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int qwe; cin >> qwe;
    while(qwe--)
    {
        int n, k; cin >> n >> k;
        int a[1005] = { 0 }; int y = 0;
        for(int i = 0;i < k;i++)
        {
            cin >> y>>a[i];
        }
        sort(a, a + k);
        //for (int i = 0; i < k; i++)cout << a[i] << " ";
        int sum = 0;
        int sign = 0;
        for(int i = k - 1;i >= 0;i--)
        {
            sum += a[i];
            //cout<<"qwq"<<a[i];
            sign++;
            if(sign >= n)break;
        }
        cout << sum << endl;
    }
}

