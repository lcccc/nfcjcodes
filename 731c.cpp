#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<functional>
using namespace std;
const int maxn = 100005;
int n,p,q,f,s[maxn],Min[maxn][17],Max[maxn][17],n1[100005];
long long n2[100005];
void Rmq_Init(int n)
{
	for(int i=1;i<=n;i++)
	{
		Max[i][0]=Min[i][0]=n1[i];
	}
	int m=(int)(log(n*1.0)/log(2.0));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			Max[j][i]=Max[j][i-1];
			if((j+(1<<(i-1))<=n))
			{
				Max[j][i]=max(Max[j][i],Max[j+(1<<(i-1))][i-1]);
			}
			Min[j][i]=Min[j][i-1];
			if((j+(1<<(i-1))<=n))
			{
				Min[j][i]=min(Min[j][i],Min[j+(1<<(i-1))][i-1]);
			}
		}
	}
}
int Get_Min(int l,int r)
{
	if(l>r)swap(l,r);
	int m=(int)(log((r-l+1)*1.0)/log(2.0));
	return min(Min[l][m],Min[r-(1<<m)+1][m]);
}
int Get_Max(int l,int r)
{
	if(l>r)swap(l,r);
	int m=(int)(log((r-l+1)*1.0)/log(2.0));
	return max(Max[l][m],Max[r-(1<<m)+1][m]);
}
int main()
{
	int n;//数组长度，下标从1开始
	while(scanf("%d",&n)==1)
	{
        memset(n1,0,sizeof n1);
        memset(n2,0,sizeof n2);
        scanf("%d%d%d",&p,&q,&f);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&n1[i]);
		}
		Rmq_Init(n);
	//	int l,r;
	//	while(scanf("%d%d",&l,&r)==2)
//		{
//			printf("%d %d\n",Get_Max(l,r),Get_Min(l,r));
//		}
        priority_queue<long ,vector<long long >,greater<long long> > pq;
        for(int i=n;i>=1;i--)
        {
            long long tm;
            tm = n1[i] + (long long)i*(long long)f - (long long)f*(long long)q -f;
            pq.push(tm);
            n2[i] = pq.top();
        }
        long long ans = 100000000;
        for(long long x = 1;x < n-p; x++)
        {
            long long ans2;
            ans2 = n1[x] + Get_Min(x+p+2,x+q);
            if(x+q+1<=n && n1[x]+n2[x+q+1] - (long long)x*(long long)f < ans2) ans2 = n2[x+q+1] + n1[x] - (long long)x*(long long)f;
           if(ans2 < ans) ans = ans2;
        } 
        cout<<ans<<endl;
	}
	return 0;
}
