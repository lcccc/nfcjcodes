/*
 * Author: FreePascal
 * Created Time:  2011/10/22 13:43:48
 * File Name: poj3157.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
bool isCpp(string s)
{
    if(!( s[0] >= 'a' && s[0] <= 'z')) return false;
    for(int i = 0;i < s.size();i ++)
        if(!( s[i]  <='z' && s[i] >='a' || s[i] == '_')) return false;
    if( s[s.size()-1] == '_' ) return false;
    for(int i = 1;i < s.size();i ++) 
        if(s[i] == '_' && s[i-1] == '_') return false;
    return true;
}
bool isJava(string s)
{
    if(!(s[0] >= 'a' && s[0] <= 'z' )) return false;
    for(int i = 0;i < s.size();i ++)
        //if(!( s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A')) return false;
        if(s[i] == '_') return false;
    return true;
}
string conve(string s)
{
    if( isCpp(s) && isJava(s))
        return s;
    if( isCpp(s) && !isJava(s))
    {
       string ans;
       for(int i = 0;i < s.size();i ++)
          if( s[i] == '_')
             s[i+1] = s[i+1] -'a' + 'A'; 
          else ans+= s[i];
       return ans;
    }
    if( !isCpp(s) && isJava(s))
    {
        string ans;
        for(int i = 0;i < s.size();i ++)
            if( s[i] <='Z' && s[i] >= 'A')
            {
                ans+='_';
                ans+= char(s[i] - 'A' + 'a');
            }   
            else ans += s[i];
        return ans;
    }
    if( !isCpp(s) && !isJava(s))
        return "Error!";
}
int main() {
    string s;
    while(cin>>s)
        cout<<conve(s)<<endl;
    return 0;
}

