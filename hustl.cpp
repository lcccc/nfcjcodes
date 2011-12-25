#include<iostream>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<cstdio>
using namespace std;
int main(){
int t,cs = 1;
cin>>t;
int n,xs,xe;
while(cin>>n>>xs>>xe)
{
	int ai[15],bi[15];
	for(int i = 0;i < n;i ++)
	cin>>ai[i]>>bi[i];
	double ans = 0;
	for(int i = 0;i < n;i ++)
		if(bi[i] != -1)
		ans += ((ai[i]+.0)/(bi[i] + 1)) * pow(xe,bi[i] + 1.0);
		else
		ans += ai[i] * log(xe);
	for(int i = 0;i < n;i ++)
		if(bi[i] != -1)
		ans -= ((ai[i]+.0)/(bi[i] + 1)) * pow(xs,bi[i] + 1.0);
		else
		ans -= ai[i] * log(xs);
	//cout<<ans<<endl;
	printf("Case #%d: %.3f\n",cs++,ans);
}
return 0;
}
