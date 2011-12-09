#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main(){
int t;
cin>>t;
while(t--){
vector<int> f;
int n,k;
cin>>n;
for(int i=0;i<n;i++){
cin>>k;
f.push_back(k);
}
sort(f.begin(),f.end());
for(int i=0;i<n-1;i++)cout<<f[i]<<' ';
cout<<f[n-1]<<endl;
}
}
