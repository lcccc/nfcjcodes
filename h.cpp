/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 12时43分45秒
 * File Name: h.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define SZ(v) ((int)(v).size())
string plural(string s)
{
    string ans;
    //1
    char ch;
    if(s[s.size()-1]=='x'||s[s.size()-1]=='s'||s[s.size()-1]=='o'){
        ans=s+"es";
        return ans;
    }
    string tm;
    tm=s.substr(s.size()-2,s.size());
    if(tm=="ch")
    {    ans=s+"es";return ans;}
    
        
    //2
        if(  s[s.size()-1]=='f') {s[s.size()-1]='v';ans=s+"es";return ans;}
        if(s[s.size()-1]=='e'&&s[s.size()-2]=='f'){
            s[s.size()-2]='v';
            ans=s+"s";
            return ans;
        }
    //3
        if(s[s.size()-1]=='y'){
            s[s.size()-1]='i';
            ans=s+"es";
            return ans;
        }
        return s+"s";
}
        
int main() {
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        cout<<plural(s)<<endl;
    }
    return 0;
}

