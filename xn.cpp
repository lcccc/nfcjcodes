/**************************************************
#		Author Xue Nan
#		Email: xuenan199@gmail.com
#
#		Last modified: 2011-05-07 20:31
#
#		Filename: C.small.cpp
#		Description:
**************************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector <int> a;
int main(int argc,char *argv[])
{
   // ifstream cin("input.txt");
   // ofstream cout("output2.txt");
	int Tcase,Case=0;
	cin>>Tcase;
	while(Tcase--)
	{
		Case++;
		scanf("%d",&n);
		int x;
		a.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			a.push_back(x);
		}
		bool flag=true;
		x=a[0];
		for(int i=1;i<n;i++)
			x=x^a[i];
		if(x)
		{
			printf("Case #%d: NO\n",Case);
			continue;
		}
		sort(a.begin(),a.end());
		int ans=0;
		for(int i=1;i<n;i++)
			ans+=a[i];
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
