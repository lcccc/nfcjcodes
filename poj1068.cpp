#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int cs;
main(){
       cin>>cs;
       while(cs--){
                   int n,k,nz=0;
                   string s="";
                   cin>>n;
                   for(int i=0;i<n;i++){
                           cin>>k;
                           for(int j=0;j<k-nz;j++)s+="(";
                           s+=")";
                           nz=k;
                           }
                //   cout<<s<<endl;
                int pn=0;
                for(int i=0;i<s.size();i++){
                        if(s[i]=='(' )continue;
                        int ans=1,stus=0;
                        for(int j=i-1;j>=0;j--){
                        if(s[j]=='(' && stus==0){
                                                 pn++;
                                                 if(pn!=n)
                                              cout<<ans<<' ';
                                              else cout<<ans<<endl;
                                              
                                              break;
                                              }
                        if(s[j]==')'){
                                      ans++;
                                      stus++;
                                      }
                       if(s[j]=='(')stus--;
                                      }
}
}
}
