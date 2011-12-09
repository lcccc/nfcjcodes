#include<iostream>
using namespace std;
main(){
int n;
while(cin>>n){
    if(n==0)break;
int ans=0,cur=0;
for(int i=1;i<=n;i++){
int k;
cin>>k;
if(k>=cur){
ans+=(k-cur)*6;
ans+=5;
cur=k;
}
else {
ans+=(cur-k)*4;
ans+=5;
cur=k;
}
}
cout<<ans<<endl;
}
}
