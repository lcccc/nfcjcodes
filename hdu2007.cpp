#include "iostream"
#include <algorithm>
using namespace std;
int main()
{
	int m,n,summ,sumn,i,temp;
	while(cin>>m>>n)
	{
		if(m>n)
            swap(m,n);
		summ=sumn=0;
		for(i=m;i<=n;i++)
            i%2? summ+=i*i*i: sumn+=i*i;
		cout<<sumn<<' '<<summ<<endl;
	}
	return 0;
}
