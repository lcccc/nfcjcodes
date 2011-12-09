#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
main(){
       
       string s;
       while(getline(cin,s)){
                             if(s=="#")break;
                             long long sum=0;
                             for(int i=0;i!=s.size();i++){
                                     if(s[i]==' ')continue;
                                     sum+=(s[i]-'A'+1)*(i+1); 
                                     }
                             cout<<sum<<endl;
                             }
    return 0;
}                     
