#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sum[50001];
int f[1000001]={1};
int main()
{
 int cas,d,n;
 int i,j;
 long long ans;
 while(scanf("%d",&cas)!=EOF)
 {
 while(cas--)
 {
  scanf("%d%d",&d,&n);
  sum[0]=0;
  for(i=1;i<=n;i++)
  {
   scanf("%d",&sum[i]);
   sum[i]=(sum[i-1]+sum[i])%d;
   //printf("%d ",sum[i]);
  }
  for(i=1;i<d;i++)
   f[i]=0;
  f[0]=1;//这里很重要，好好想想应该能知道为什么，sum[i]=0是一种特殊的情况
  for(i=1;i<=n;i++)
   f[sum[i]]++;
  ans=0;
  for(i=0;i<d;i++)
   if(f[i]>1) 
    ans+=(((long long)f[i])*(f[i]-1)/2);
  printf("%lld\n",ans);
 }
 }
 return 0;
}

