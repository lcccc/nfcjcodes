#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int pos;
    pos=s.find('.');
    if(s[pos-1]=='9')
                     cout<<"GOTO Vasilisa."<<endl;
    else {
         int x;
         x=s[pos+1]-'0';
         if(x<5)
                cout<<s.substr(0,pos)<<endl;
         else cout<<s.substr(0,pos-1)<<char(s[pos-1]+1)<<endl;
         }
    cin>>pos;
    return 0;
}
