/*
 * Author: FreePascal
 * Created Time:  2011/10/30 13:28:00
 * File Name: poj2253.cpp
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
struct zb{
    int x;
    int y;
} f[300];
#define MAXN 205
#define inf 100000000
void dijkstra(int n,double mat[][MAXN],int s,double* min,int* pre){
    int v[MAXN],i,j,k;
    for(i = 0;i < n;i ++)
        min[i] = inf,v[i] = 0,pre[i] = -1;
    for(min[s] = 0,j = 0;j < n;j++){
        for(k = -1,i = 0;i < n;i ++)
            if(!v[i] && (k==-1||min[i] < min[k]))
                k = i;
        for(v[k] = 1,i = 0;i < n;i ++)
            if(!v[i]&&min[k] + mat[k][i] < min[i])
                min[i] = min[pre[i] =k] + mat[k][i];
    }
}
double dis(int u,int v){
   return sqrt((f[u].x - f[v].x)*(f[u].x - f[v].x) + (f[u].y - f[v].y)*(f[u].y-f[v].y));  
}
int main() {
    int n;
    while(cin>>n){
    for(int i = 0;i < n;i ++)
        cin>>f[i].x>>f[i].y;
    double mat[MAXN][MAXN];
    for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++)
                mat[i][j] = dis(i,j);
    double min[MAXN];
    int pre[MAXN];
    dijkstra(n,mat,0,min,pre);
    //cout<<min[1]<<endl;
    
    int k = 1;
    double ans = inf;
    while( pre[k]!=-1){
        if( dis(pre[k],k) < ans) ans = dis(pre[k],k);
        k = pre[k];
    }
    cout<<ans<<endl;
    }
    return 0;
}

