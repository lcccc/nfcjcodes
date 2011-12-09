#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> f;
int n,s,k;

main(){
cin>>n>>s;
for(int i=0;i<n;i++){
cin>>k;
f.push_back(k);
}

sort(f.begin(),f.end());
long long ans=0;
for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
        if(f[i]+f[j]<=s)ans++;
        else break;

cout<<ans<<endl;
}
