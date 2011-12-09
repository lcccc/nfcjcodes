#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
__int64 cab[10000+9];
int _n,_k;
int okay(__int64 len)
{
int i,j,k;
__int64 sum=0;
if(len==0) return 1;
for(i=0;i<_n;i++)
{
   sum+=cab[i]/len;
}
if(sum>=_k) return 1;
else return 0;
}
int main()
{
int n,k;
int i,j;
__int64 sum=0;
scanf("%d%d",&n,&k);
_n=n;_k=k;
__int64 max2=0;
for(i=0;i<n;i++)
{
   double t;
   scanf("%lf",&t);
   cab[i]=(__int64)(t*100);
   max2=cab[i]>max2?cab[i]:max2;
}
__int64 max1=sum/k;
__int64 max=max1>max2?max1:max2;
__int64 l=0,h=max;
__int64 mid,r;
while(l<h)
{
   if(h-l==1) break;
   mid=(l+h)/2;
   if(okay(mid))
   {
    l=mid;
   }
   else
   {
    h=mid;
   }
}
r=l;
if(h-l==1)
{
   if(okay(h)) r=h;
   else r=l;
}
printf("%I64d.%02I64d\n",r/100,r%100);
return 0;
}

