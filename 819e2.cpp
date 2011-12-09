/*
 * Team : FreePascal
 * Created Time:  2011年08月19日 星期五 13时29分39秒
 * File Name: 819e2.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define SZ(v) ((int)(v).size())
string f(int x)
{
    int cs,bcs;
    string ans;
    cs = 1;
    bcs = x;
    map<int,int> f;
    while(!f[cs%bcs]){
        ans+=char( cs/bcs +'0');
        f[cs%bcs] = 1;
        cs = cs % bcs * 10;
    }
    if(cs!=0)
    ans+=char(cs/bcs+'0');
    ans = ans.substr(1);
    return ans;
}
int main() {
    int n,k,ans ;
    string s;
    while(cin>>n>>k){
        ans = 0;
        for(int i = 2;i<=n;i++){
        string s = f(i);
        //cout<<s<<endl;
        ans+= count(s.begin(),s.end(),char(k+'0'));
        }
        cout<<ans<<endl;
    }
    return 0;
}

