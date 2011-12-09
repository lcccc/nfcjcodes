/*
 * Author: Nfcj
 * Created Time:  2011年07月28日 星期四 15时27分17秒
 * File Name: 728c.cpp
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
typedef int LL;
 
LL modular_multi(LL x,LL y,LL mo)
{
	LL t;
	x%=mo;
	for(t=0;y;x=(x<<1)%mo,y>>=1)
		if (y&1)
			t=(t+x)%mo;
	return t;
}
 
LL modular_exp(LL num,LL t,LL mo)
{
	LL ret=1,temp=num%mo;
	for(;t;t>>=1,temp=modular_multi(temp,temp,mo))
		if (t&1)
			ret=modular_multi(ret,temp,mo);
	return ret;
}
int n,r;
vector<int> metr[11];
int main() {
   while(scanf("%d",&n)==1){
      for(int i=1;i <=n;i++)
    {
       scanf("%d",&r);
       metr[i].push_back(r);
       for(int j=1;j<=r+1;j++)
       {
          int tm;
         scanf("%d",&tm);
        metr[i].push_back(tm);
       }
    }
   int ansed=0;
   for(int i=1;i<= 999983;i++)
   {
      int    b=1;
      LL ans=0,ans2=0;
      for(int k=metr[1][0];k>=0;k--)
             ans+= metr[1][k]%9999983*modular_exp(i,k,999983);
      for(int j=2;j<=n;j++) 
      {
          ans2=0;
          for(int k=metr[j][0];k>=0;k--)
              ans2+= metr[j][k]%999983*modular_exp(i,k,999983);
          if(ans2 != ans){ b= 0;break;}
      }
    if(b) {
        printf("YES\n");
        ansed=1;
        break;
    }
   }
    if(!ansed) printf("NO\n");
   }  
    return 0;
}

