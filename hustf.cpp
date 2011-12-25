#include<iostream>
#include<algorithm>
using namespace std;
int oneof(unsigned int x){
int tot = 0;
for(int i = 0;i < 32;i ++)
{
	tot += x & 1;
	x >>= 1;
}
return tot;
}
unsigned int nextkbit(unsigned int x)
{
	int bt = oneof(x);
	int ans = x+1;
	while(oneof(ans) != bt) ans++;
	return ans;
}
int main(){
unsigned int t,cs = 1,x;
cin>>t;
while(cin>>x)
{
cout<<"Case #"<<cs++<<":\n";
cout<<nextkbit(x)<<endl;
}
return 0;
}
