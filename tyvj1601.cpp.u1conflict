/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 15:42:36
 * File Name: tyvj1601.cpp
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
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int hp[30005],n,m;
char c;
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>hp[i];
    cin>>m;
    while(m--)
    {
       char cmd;
       int a,b;
      cin>>cmd;
     if(cmd == 'A') { 
         cin>>a>>b;
         hp[a]-=b;
     }
     if(cmd == 'C'){
         cin>>a>>b;
         hp[a]+=b;
     }
     if(cmd == 'Q'){
         cin>>a;
         cout<<hp[a]<<endl;
     }
    }
     int ans = 0;
     for(int i = 1;i<=n;i++)
         if( hp[i]>0) ans++;
     cout<<ans<<endl;
    return 0;
}

