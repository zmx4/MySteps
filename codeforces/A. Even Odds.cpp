#include<bits/stdc++.h>
#define int long long int
using namespace std;

/*
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n];
  long long int j = 1;
  long long int sign;
  for (long long int i = 0; i < n; i++) {
    if (j>n)break;
        arr[i] = j;
    j+=2;
    sign = i;
  }
  j = 2;
  for (long long int i = sign + 1; i < n; i++) {
    //if (j==n||j==n-1)break;
    arr[i] = j;
    j+=2;
  }
  //for (long long int i = 0; i < n; i++) cout<<arr[i]<<" ";
  cout << arr[k-1];
}
*/
signed main() {
  int n,k;cin>>n>>k;
  int odd_count = (n + 1) / 2;

  if (k <= odd_count) {
    cout << 2 * k - 1 << endl;
  } else {
    cout << 2 * (k - odd_count) << endl;
  }

  return 0;
}