#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n;cin>>n;
    //int yhsj[11][11]={1};
    vector<vector<int>> yhsj(11, vector<int>(11, 1));
    for(int i = 2;i < n;i++)
    {
        for(int j = 1;j <i;j++)
        {
            yhsj[i][j]=yhsj[i-1][j-1]+yhsj[i-1][j];
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 5 - i;j++)
        {
            cout<<" ";
        }
        for(int j = 0;j <= i ;j++)
        {
            //cout<<yhsj[i][j];
            //if(j!=i)cout<<"   ";
            printf("%4d",yhsj[i][j]);
        }
        cout<<endl;
    }
}