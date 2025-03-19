#include <iostream>
#include <map>
using namespace std;
int getGold(int number) {
    std::map<int, int> goldMap = {
        {6, 10000}, {7, 36}, {8, 720}, {9, 360}, {10, 80},
        {11, 252}, {12, 108}, {13, 72}, {14, 54}, {15, 180},
        {16, 72}, {17, 180}, {18, 119}, {19, 36}, {20, 306},
        {21, 1080}, {22, 144}, {23, 1800}, {24, 3600}
    };
    if (goldMap.find(number) != goldMap.end()) {
        return goldMap[number];
    } else {
        std::cerr << "Error: Input number is out of range." << std::endl;
        return -1;
    }
}
int main()
{
    int a[4][4]={0};int asum = 45;int bsum = 0;int ii,jj;
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++)
        {
            cin>>a[i][j];
            bsum += a[i][j];
            if(a[i][j] = 0)
            {
                int ii = i,jj = j;
            }
        }
    }
    a[ii][jj] = asum - bsum;
    //for(int i )
    int n = 3;
    int sum = 0;
    while(n--)
    {
        int o,p;cin>>o>>p;
        //sum += a[o][p];
        cout<<a[o][p]<<endl;
        //a[o][p] = 0;
    }
    int operate = 0;cin>>operate;
    if(operate<=3)
    {
        for(int i = 1;i<=3;i++)
        {
            sum+=a[operate][i];
            
        }
    }
    else if(operate<=6)
    {
        for(int i = 1;i<=3;i++)
        {
            sum+=a[i][operate];
        }
    }
    else if(operate == 7)
    {
        for(int i = 1;i <= 3;i++)
        {
            sum+=a[i][i];
            cout<<a[i][i]<<endl;
        }
    }
    else if(operate == 8)
    {
        for(int i = 1;i <= 3;i++)
        {
            sum+=a[i][4-i];
        }
    }
    cout<<getGold(sum);
}
/*
#include <bits/stdc++.h>
using namespace std;
int getGold(int number) {
    std::map<int, int> goldMap = {
        {6, 10000}, {7, 36}, {8, 720}, {9, 360}, {10, 80},
        {11, 252}, {12, 108}, {13, 72}, {14, 54}, {15, 180},
        {16, 72}, {17, 180}, {18, 119}, {19, 36}, {20, 306},
        {21, 1080}, {22, 144}, {23, 1800}, {24, 3600}
    };
    if (goldMap.find(number) != goldMap.end()) {
        return goldMap[number];
    } else {
        std::cerr << "Error: Input number is out of range." << std::endl;
        return -1;
    }
}
int main()
{
    int a[4][4]={0};
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++)
        {
            cin>>a[i][j];
        }
    }
    int n = 3;
    int sum = 0;
    while(n--)
    {
        int o,p;cin>>o>>p;
        //sum += a[o][p];
        cout<<a[o][p]<<endl;
        //a[o][p] = 0;
    }
    int operate = 0;cin>>operate;
    if(operate<=3)
    {
        for(int i = 1;i<=3;i++)
        {
            sum+=a[operate][i];
            
        }
    }
    else if(operate<=6)
    {
        for(int i = 1;i<=3;i++)
        {
            sum+=a[i][operate];
        }
    }
    else if(operate == 7)
    {
        for(int i = 1;i <= 3;i++)
        {
            sum+=a[i][i];
        }
    }
    else if(operate == 8)
    {
        for(int i = 1;i <= 3;i++)
        {
            sum+=a[i][4-i];
        }
    }
    cout<<getGold(sum);
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int getGold(int number) {
    std::map<int, int> goldMap = {
        {6, 10000}, {7, 36}, {8, 720}, {9, 360}, {10, 80},
        {11, 252}, {12, 108}, {13, 72}, {14, 54}, {15, 180},
        {16, 72}, {17, 180}, {18, 119}, {19, 36}, {20, 306},
        {21, 1080}, {22, 144}, {23, 1800}, {24, 3600}
    };
    if (goldMap.find(number) != goldMap.end()) {
        return goldMap[number];
    } else {
        std::cerr << "Error: Input number is out of range." << std::endl;
        return -1;
    }
}
int main()
{
    int a[4][4]={0};int asum = 45;int bsum = 0;int ii,jj;
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++)
        {
            cin>>a[i][j];
            bsum += a[i][j];
            if(a[i][j] == 0)
            {
                int ii = i,jj = j;
                //cout<<ii<<" "<<jj<<" "<<bsum<<endl;
            }
        }
    }
    a[ii][jj] = asum - bsum;
    //cout<<a[ii][jj]<<endl;
    int n = 3;
    int sum = 0;
    while(n--)
    {
        int o,p;cin>>o>>p;
        //sum += a[o][p];
        cout<<a[o][p]<<endl;
        //a[o][p] = 0;
    }
    int operate = 0;cin>>operate;
    if(operate<=3)
    {
        for(int i = 1;i<=3;i++)
        {
            sum+=a[operate][i];
            
        }
    }
    else if(operate<=6)
    {
        for(int i = 1;i<=3;i++)
        {
            sum+=a[i][operate];
        }
    }
    else if(operate == 7)
    {
        for(int i = 1;i <= 3;i++)
        {
            sum+=a[i][i];
            cout<<a[i][i]<<endl;
            //cout<<i<<endl;
        }
    }
    else if(operate == 8)
    {
        for(int i = 1;i <= 3;i++)
        {
            sum+=a[i][4-i];
        }
    }
    cout<<getGold(sum);
}
*/