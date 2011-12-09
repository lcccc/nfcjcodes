/*
ID:lc757692
TASK:agrinet
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月20日 星期三 20时18分47秒
 * File Name: arginet.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())
int INF=100001;
int map[105][105];
int mincost=0;
int set[105],n,dis[105];
int main() {
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
        {
           scanf("%d",&map[i][j]);
          if(map[i][j] == 0)map[i][j]=INF;
        }
    for(int i=0;i<105;i++)
       dis[i]=INF;
   memset(set,0,sizeof set); 
   //dijsk
   
   set[0]=1;
   for(int i=1;i<n;i++)
       dis[i]=map[0][i];
   
   for(int i=1;i<n;i++)
   {
       int min=INF,id=i;
       for(int j=1;j<n;j++)
           if( dis[j]<min && !set[j]) {
               min = dis[j];
               id = j;
           }
   // cout<<id<<endl;
    mincost+=min;
   set[id]=1; 
        for(int j = 0; j < n; j++)
         if(!set[j]&&map[id][j]<dis[j])
                dis[j] =  map[id][j];
   }   
   printf("%d\n",mincost);
    return 0;
}

