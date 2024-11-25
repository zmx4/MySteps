//
// Created by Tick on 24-11-22.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int e[N],ne[N];
int head,idx;
void init(){
  head=-1;
  idx = 0;
}
void add_to_head(int x){
  //idx
  ne[idx] = head;
  head = idx;
  e[idx] = x;
  idx++;
}
void add(int k,int x){//将x插到下标为K的点
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx;
  idx++;
}
void del(int k){//将下标为K后的点删除
  ne[k] = ne[ne[k]];
}

int main()
{
  char ope;
  int n;cin>>n;
  init();
  while(n--){
    cin>>ope;
    if(ope=='H'){
      int a;cin>>a;
      add_to_head(a);
    }
    else if(ope=='D'){
      int a;cin>>a;
      //a-=1;
      if (!a)head=ne[head];
      else del(a - 1);
    }
    else if(ope=='I'){
      int k,x;cin>>k>>x;
      add(k - 1,x);
    }
  }
  for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<" ";
  return 0;
}