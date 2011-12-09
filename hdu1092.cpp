#include<iostream>
using namespace std;
main(){
int n,m;
cin>>n;
for(int i=0;i<n;i++){
cin>>m;
int ans=0;
for(int i=0;i<m;i++){
int a;
cin>>a;
ans+=a;
}
cout<<ans<<endl;
if(i!=n-1)cout<<endl;
}
}
