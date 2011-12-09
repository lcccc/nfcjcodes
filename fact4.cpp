/*
ID:lc757692
LANG:C++
TASK:fact4
*/
#include <stdio.h>
#include <iostream>
using namespace std;
 
 
int main()
{
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	long n,i,t=1;
	cin>>n;
	for (i=1;i<=n;++i)
	{
		t*=i;
		while (t%10==0)
		{
			t/=10;
		}
		t=t%100000;
	}
	cout<<t%10<<endl;	
}
