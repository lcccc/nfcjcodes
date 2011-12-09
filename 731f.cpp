/*
 * Author: Nfcj
 * Created Time:  2011年07月31日 星期日 13时17分40秒
 * File Name: 731f.cpp
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
#define LL long long 
int n,m,q;
bool map[1005][1005];
int f[1005],p[1005];
int main() {
    while(scanf("%d",&n))
    {
        memset(map,0,sizeof map);
        for(int i=1;i<=n;i++)
            scanf("%d",&p[i]);
        scanf("%d",&m);
        for(iint i=1;i<=m;i++);
        {
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b] = 1;
        }
        scanf("%d",&q);
        LL ans = 0;
       for(int cs = 0;cs < q; cs++)
       {
          memset(f,0,sizeof f);
          f[1] = p[1];
         for(int i = 2; i<= n;i++)
         {
             
    return 0;
}

