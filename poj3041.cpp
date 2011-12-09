/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/17 14:38:55
 * File Name: poj3041.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int n,k,use[600],lin[600];
bool map[600][600];
bool iszg(int x)
{
    for(int i = 1;i <= n;i++)
        if(map[x][i] && !use[i])
        {
            use[i] = 1;
            if(lin[i] == -1 || iszg(lin[i])){
                lin[i] = x;
                return true;
            }
        }
    return false;
}
int main() {
    int ans,t1,t2;
    while(scanf("%d%d",&n,&k)!=EOF){
       ans = 0;
      memset(map,0,sizeof(map)); 
      memset(lin,-1,sizeof(lin));
      for(int i = 0;i < k;i++){
          scanf("%d%d",&t1,&t2);
          map[t1][t2] = true;
      }
      for (int i = 1;i <= n;i++)
      {
          memset(use,0,sizeof(use));
          if(iszg(i))
              ans++;
      }
      printf("%d\n",ans);
    }
    return 0;
}

