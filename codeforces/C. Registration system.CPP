//24-11-27 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct RegistrationSystem
{
  string name;
  int cnt = 0;
  //int number;
};
RegistrationSystem reg[1000005];
bool existTargetName(const string& targetName)
{
  for (auto& r : reg)
  {
    if (!r.name.empty() && r.name == targetName)
    {
      return true;
    }
  }
  return false;
}
//
//signed main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
///*
//  string s;cin>>s;
//	int n;cin>>n;
//
//  for(int i=0;i<n;i++)
//  {
//    cin>>s;
//    //reg[i].number=i;
//    if(existTargetName(s))
//    {
//      reg[i].cnt++;
//      if(reg[i].cnt > 1)
//      {
//        cout<<reg[i].name<<reg[i].cnt<<endl;
//      }
//      else
//      {
//        cout<<"OK"<<endl;
//      }
//    }
//    else
//    {
//
//    }
//  }
//*/
//    int n;cin>>n;
//    int j = 0;
//    while (n--)
//    {
//      string name;cin>>name;
//      if (existTargetName(name))
//      {
//
//      }
//    }
//    return 0;
//}
int main() {
  int n;
  cin >> n;

  unordered_map<string, int> nameCount;

  for (int i = 0; i < n; ++i) {
    string name;
    cin >> name;

    if (nameCount.find(name) == nameCount.end()) {
      cout << "OK" << endl;
      nameCount[name] = 1;
    } else {
      int count = nameCount[name];
      string newName = name + to_string(count);
      cout << newName << endl;
      nameCount[name] = count + 1;
      nameCount[newName] = 1;
    }
  }

  return 0;
}
