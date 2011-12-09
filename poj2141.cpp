#include<iostream>
#include<string>
using namespace std;
string cd;
char f_ch(char c){
if(c<='z'&&c>='a')
return cd[c-'a'];
if(c<='Z'&&c>='A')
return char( cd[c-'A']+'A'-'a');
return c;
}
main(){
getline(cin,cd);
string ss;
getline(cin,ss);
for(int i=0;i<ss.size();i++)
    cout<<f_ch(ss[i]);
cout<<endl;
}
