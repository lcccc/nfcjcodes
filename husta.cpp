#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main(){
int cs;
vector<int>f ;
cin>>cs;
while(cs--){
f.clear();
int k;
cin>>k;
for(int i=0;i<k;i++){
int tm;
cin>>tm;
f.push_back(tm);
}
sort(f.begin(),f.end());
for(int i=0;i<f.size();i++)
if(i!=f.size()-1)cout<<f[i]<<' ';
else cout<<f[i]<<endl;
}
return 0;
}
