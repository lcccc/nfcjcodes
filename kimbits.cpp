 
/*
ID:lc757692
LANG:C++
TASK:kimbits
*/
 
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
 
int dp[33][33];
 
int digui(int N,int L)
{
	if (N==0 || L==0)
	{
		return 1;
	}
	if (dp[N][L]!=0)
	{
		return dp[N][L];
	}
	dp[N][L]=digui(N-1,L)+digui(N-1,L-1);
	return dp[N][L];
}
 
int main()
{
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	unsigned int N,L,I;
	int i,j,num=0;
	unsigned int t=0;
	cin>>N>>L>>I;
	I-=1;
	for(t=N;t>0;--t)
	{
		if (I && digui(t-1,L)<=I)
		{
			cout<<1;
			I-=digui(t-1,L);
			L-=1;
		}
		else
		{
			cout<<0;
		}
	}
	cout<<endl;
	return 0;
}
