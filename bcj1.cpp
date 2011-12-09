/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/8 19:48:00
 * File Name: bcj1.cpp
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
struct uset
{
    int f[1005];
    uset(){
        for(int i = 0;i < 1005;i++) f[i] = i;
    }
    int find(int x){
        while(f[x] != x) x = f[x];
        return x;
    }
    int unset(int a,int b)
    {
        if( find(a) == find(b) )return 0;
        f[find(a)] = find(b);
        return 1;
    }
};
int main() {
    int cs;
    int n,m;
    cin>>cs;
    while(cs--)
    {
        cin>>n>>m;
        uset set;
        int a,b;
        for(int i = 0 ;i < m;i++){
            cin>>a>>b;
            set.unset(a,b);
        }
       int ans = 0;
      for(int i = 1;i <= n;i++)
         if( set.f[i] == i) ans++;
     cout<<ans<<endl;
    } 
    return 0;
}

