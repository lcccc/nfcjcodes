/*
ID:lc757692
TASK:butter
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月28日 星期四 13时58分43秒
 * File Name: butter.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
#define SZ(v) ((int)(v).size())
struct  node{
    int end,len;
};
vector<node> v[805];
int n,p,c,ct[805];
int in[805],dis[805];
int spfa(int x)
{
    for(int i = 1;i <= p;i++) dis[i] = 10000000;
    dis[x] = 0;
    memset(in,0,sizeof in);
    queue<int> Q;
    Q.push(x);
    while(!Q.empty())
    {
        int s = Q.front();
        Q.pop();
        in[s] = 0;
        for(int i=0;i<v[s].size();i++)
            if(dis[s] + v[s][i].len < dis[v[s][i].end])
            {
               dis[v[s][i].end] = dis[s] + v[s][i].len;
                 if(!in[v[s][i].end])
                {
                   Q.push(v[s][i].end);
                   in[v[s][i].end]=1;
                }
            }
    }

    int ans=0;
        for(int i=1;i<=p;i++)
           ans+=  ct[i]*dis[i];
       return ans;
    } 
int main() {
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    scanf("%d%d%d",&n,&p,&c);
    memset(ct,0,sizeof ct);
    for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            ct[t]++;
        }
    for(int i=1;i<=c;i++)
    {
        int s,t,val;
        scanf("%d%d%d",&s,&t,&val);
        node tm;
        tm.end = t;tm.len = val; v[s].push_back(tm);
        tm.end = s;tm.len = val; v[t].push_back(tm);
    }
    int tt=0,ans = 1<<30;
    
    for(int i=1;i<=p;i++)
    {
        tt = spfa(i);
     if(tt < ans) ans = tt;
    } 
    printf("%d\n",ans);
    return 0;
}

