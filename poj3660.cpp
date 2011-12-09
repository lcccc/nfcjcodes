/*
 * Author: FreePascal
 * Created Time:  2011/11/2 13:44:29
 * File Name: poj3660.cpp
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
int f[105][105],n,m;
int main() {
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof f);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        f[u][v] = 1;
        f[v][u] = -1;
    }
    //for(int i = 1;i <= n;i++)
        //out(f[2][i]);
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n; i++)
            for(int j = 1;j <= n;j++)
                if(f[i][j]!=0 || i ==j || i == k || j==k) continue;
                else{
                    //out(i),out(k),out(j),out(f[i][j]); 
                    if( f[i][k] == 1 && f[k][j] == 1) {f[i][j] = 1;continue;}
                    if( f[i][k] == -1 && f[k][j] == -1) {f[i][j] = -1;continue;}
                } 
    int ans = 0;
    //for(int i = 1;i <= n;i++)
        //out(f[2][i]);
    for(int i = 1;i <= n;i++)
    {
        int k  = 0;
        for(int j = 1;j <= n;j++)
            if(i == j) continue;
            else k+= fabs(f[i][j]);
        if(k == n-1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

