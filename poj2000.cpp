#include<iostream>
#include<algorithm>
using namespace std;
int f(int x){
int k=1,ans=0,i;
for( i=1;;){
ans+=k*k;
k++;
if(i+k>x)break;
i+=k;
}
ans+=(x-i)*k;
return ans;
}
main(){
int x;

while(cin>>x){
if(x==0)break;
cout<<x<<' '<<f(x)<<endl;
}
return 0;

}
