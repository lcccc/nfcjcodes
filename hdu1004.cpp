#include<map>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
main(){
int n;
map<string,int> f;
while(cin>>n){
string s;
if(n==0)break;
f.clear();
for(int i=0;i<n;i++)
    {
        cin>>s;
        f[s]++;
    }
map<string,int>::iterator p;
string ans;
int max=0;
for(p=f.begin();p!=f.end();p++)
if((*p).second>max){
ans=(*p).first;
max=(*p).second;
}
cout<<ans<<endl;
}
}
