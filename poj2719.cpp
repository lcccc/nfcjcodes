#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int f(string s){
    int re=0,x=1;
    int v[]={0,1,2,3,3,4,5,6,7,8,9};
    for(int i=s.size()-1;i>=0;i--){
            re+=v[s[i]-'0']*x;
            x*=9;
            }
    return re;
}
main()
{
      string s;
      while(1){
               cin>>s;
               if(s=="0")break;
               cout<<s<<": "<<f(s)<<endl;
               }
      return 0;
      }
