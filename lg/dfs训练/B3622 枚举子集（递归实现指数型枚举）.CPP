// 24-12-2 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
bool arr[20];
void printa()
{
  for (int i = 1; i <= n; i++)
  {
    if (arr[i])
      cout << "Y";
    else
      cout << "N";
  }
  cout << endl;
}

bool judge()
{
  for (int i = 1; i <= n; i++)
    if (arr[i] == false)
      return false;
  return true;
}

void solve()
{
  if (judge())
    return;
  bool carry = false;
  if (arr[n] == false)
  {
    arr[n] = true;
    printa();
  }
  else
  {
    // arr[n] = false;
    carry = true;
    for (int i = n; i >= 1; i--)
    {
      if (arr[i] == true)
        arr[i] = false;
      else if (arr[i] == false)
      {
        arr[i] = true;
        break;
      }
    }
    printa();
  }
  solve();
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++)
    arr[i] = false;
  printa();
  solve();
  return 0;
}
