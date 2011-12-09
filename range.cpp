/*
ID:lc757692
TASK:range
LANG:C++

 * Author: Nfcj
 * Created Time:  2011年08月02日 星期二 09时56分34秒
 * File Name: range.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
int n,map[255][255],f[255][255],nm[255];
int min3(int x,int y,int z)
{
   return min(min(x,y),z); 
}
void _input(){
    freopen("range.in","r",stdin);
    memset(map,0,sizeof map);
    memset(f,0,sizeof f);
   scanf("%d",&n);
  for(int i=1; i <= n; i++)
  {
      getchar();
     for(int  j = 1;j <= n; j++)
     {
        scanf("%c",&map[i][j]);
        map[i][j] -= '0';
        f[i][j] = map[i][j]; 
     }
  }
}
void _dp()
{
    for(int i=n;i>=1;i--)
        for(int j = n;j >= 1;j--)
        {
        if(map[i][j] == 0) f[i][j] = 0;
        else f[i][j] = min3(f[i][j+1],f[i+1][j],f[i+1][j+1]) +1;
        }
}
void _output(){
    freopen("range.out","w",stdout);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            for(int k=2;k <= f[i][j];k++)
            nm[k]++;
    for(int i=2;i<=255;i++)
        if(nm[i])
            printf("%d %d\n",i,nm[i]);
    
}
int main() {
    _input();
    _dp();
    _output();
    return 0;
}

