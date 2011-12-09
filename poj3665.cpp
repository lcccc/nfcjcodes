/*
 * Author: FreePascal
 * Created Time:  2011/10/15 10:02:52
 * File Name: poj3665.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int n,t;
int r[1005];
int id[1005];
bool mycmp(int a,int b)
{
    return r[a] > r[b] || r[a] == r[b] && a < b;
}
int main() {
    scanf("%d%d",&n,&t);
    for(int i = 1;i <= n;i ++)
    {
       //cin>>r[i];
        scanf("%d",&r[i]);
       id[i] = i;
    }
   while(t--)
   {
      //sort(id+1,id+n+1,mycmp);
      //for(int i = 1;i  <= n;i ++)
          //cout<<id[i] << ' ' << r[id[i]]<<endl;;cout<<endl;
      //cout<<id[1]<<endl;
      int max = 0,idi = 1;
      for(int i = 1;i <= n;i ++)
      {
          if(r[i] > max) { max = r[i];idi = i;}
      }
      printf("%d\n",idi);
      int k = r[idi] / (n-1);
      for(int i = 1;i <= n; i ++)
      {
          if(i != idi)
         r[i] += k;
      }
      k = r[id[1]] - k * (n-1);
      int i = 1;
      while(k>0)
      {
          if(i == idi ) {i ++; continue;}
          r[i]++;
          i ++;
          k --;
          if(i > n) i = 1;
      }
      r[idi] = 0;
      
   } 
    return 0;
}

