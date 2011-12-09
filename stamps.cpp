/*
ID:lc757692
TASK:stamps
LANG:C++



 * Author: Nfcj
 * Created Time:  2011年07月24日 星期日 19时30分36秒
 * File Name: stamps.cpp
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
int n,k;
int f[2000001],val[51];
int main() {
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i <= k;i++)
    {
        int a;
        scanf("%d",&a);
        val[i]=a;
    }
    sort(val+1,val+k+1);
    for(int i=1;i <= 2000000;i++)f[i]=2000001;
    f[0]=0;
    int i=1;
    while(1){
       int min=2000001;
      for(int j = 1; j <= k;j++)
      {
         if(val[j]>i)break;
         if(f[i-val[j]] < min)min = f[i-val[j]];
        }
      f[i]=min+1;
      if(f[i] > n) break;
      i++;
    } 
    printf("%d\n",i-1);
    return 0;
}

