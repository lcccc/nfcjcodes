/*
 * Author: lbs4570
 * Created Time:  2011-8-1 12:47:57
 * File Name: e.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int len(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int ans,n,x[1005],y[1005],p[1005],maxi = 0,k = 1,visited[1005],dis[1005][1005];
void dfs(int i)
{
    //cout<<i<<endl;
    ans+= p[i];
    visited[i] = 1;
    for(int j = 1;j<=n;j++)
        if( visited[j] == 0 &&dis[i][j] <=900 )
           dfs(j);
} 
int main() {
    while(scanf("%d",&n) != EOF)
    {
        //scanf("%d",&n);
        if( n == 0) break;
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(p,0,sizeof p);
        for(int i=1;i<= n;i++)
            scanf("%d%d%d",&x[i],&y[i],&p[i]);
        maxi = 0;
        k = 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j] = len(x[i],y[i],x[j],y[j]);
        memset(visited,0,sizeof visited);
        for(int i=1;i<=n;i++)
        {
            if (visited[i] == 0){
            ans=0;
            dfs(i);
            if(ans > maxi) { maxi = ans;k = i;}
            }
        }
        printf("%d %d\n",k,maxi);
    }
    return 0;
}

