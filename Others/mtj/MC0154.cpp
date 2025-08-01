#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
double distancefrompointtoline(double px, double py, double ax, double ay, double bx, double by)
{
    double abx = bx - ax, aby = by - ay;
    double apx = px - ax, apy = py - ay;
    double r = (abx * apx + aby * apy) / (abx * abx + aby * aby);
    if (r < 0)
        return dist(px, py, ax, ay); // 最近到 A
    if (r > 1)
        return dist(px, py, bx, by); // 最近到 B
    // 垂足 H 在线段上
    double hx = ax + r * abx, hy = ay + r * aby;
    return dist(px, py, hx, hy);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int x1, y1, x2, y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int xq, yq;
    cin >> xq >> yq;

    double distance1 = distancefrompointtoline( xq, yq,x1, y1, x2, y2);
    double distance2 = distancefrompointtoline( xq, yq,x2, y2, x3, y3);
    double distance3 = distancefrompointtoline( xq, yq,x3, y3, x1, y1);
    double min_distance = min({distance1, distance2, distance3});
    // cout<<distance1 << " " << distance2 << " " << distance3 << endl;
    cout << fixed << setprecision(2) << min_distance << endl;




    return 0;
}