#include <bits/stdc++.h>
using namespace std;
bool isIDnumber(const string &a)
{
    int sum=0;
    for(int i=0;i<17;i++)
    {
        if(a[i] < '0' || a[i] > '9')
        {
            return false;
        }
        //else if(a[i]>'0'&&a[i]<'9')
        //{
            if(i==0 )sum+=(a[i] - '0')*7;
            if(i==1 )sum+=(a[i] - '0')*9;
            if(i==2 )sum+=(a[i] - '0')*10;
            if(i==3 )sum+=(a[i] - '0')*5;
            if(i==4 )sum+=(a[i] - '0')*8;
            if(i==5 )sum+=(a[i] - '0')*4;
            if(i==6 )sum+=(a[i] - '0')*2;
            if(i==7 )sum+=(a[i] - '0')*1;
            if(i==8 )sum+=(a[i] - '0')*6;
            if(i==9 )sum+=(a[i] - '0')*3;
            if(i==10)sum+=(a[i] - '0')*7;
            if(i==11)sum+=(a[i] - '0')*9;
            if(i==12)sum+=(a[i] - '0')*10;
            if(i==13)sum+=(a[i] - '0')*5;
            if(i==14)sum+=(a[i] - '0')*8;
            if(i==15)sum+=(a[i] - '0')*4;
            if(i==16)sum+=(a[i] - '0')*2;
        //}
    }
    int c = sum % 11;
    if     (c== 0&&a[17]=='1')return true;
    else if(c== 1&&a[17]=='0')return true;
    else if(c== 2&&a[17]=='X')return true;
    else if(c== 3&&a[17]=='9')return true;
    else if(c== 4&&a[17]=='8')return true;
    else if(c== 5&&a[17]=='7')return true;
    else if(c== 6&&a[17]=='6')return true;
    else if(c== 7&&a[17]=='5')return true;
    else if(c== 8&&a[17]=='4')return true;
    else if(c== 9&&a[17]=='3')return true;
    else if(c==10&&a[17]=='2')return true;
    else return false;
}
int main()
{
    int qwe;cin>>qwe;
    int sign;
    while(qwe--)
    {
        string a;cin>>a;
        if(!isIDnumber(a))
        {
            cout<<a<<endl;
            sign +=1;
        }
    }
    if(sign==0)cout<<"All passed";
}