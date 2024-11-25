//
// Created by Tick on 24-11-22.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int m,idx;
int e[N],l[N],r[N];
void init(){
  //0表示左端点,1表示右端点
  r[0]=1;l[1]=0;
  idx = 2;
}
void add(int k,int x){
  e[idx]=x;r[idx]=r[k];
  l[idx]=k;
  l[r[k]]=idx;
  r[k]=idx;
}
//删除
void remove(int k){
  r[l[k]]=r[k];
  l[r[k]]=l[k];
}