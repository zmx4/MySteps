#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt(abs((x1 - x2) * (x1 - x2)) + abs((y1 - y2) * (y1 - y2)));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	double x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double a=dis(x1,y1,x2,y2),b=dis(x1,y1,x3,y3),c=dis(x2,y2,x3,y3);
	cout<<format("{:.2f}",a+b+c)<<endl;

	return 0;
}