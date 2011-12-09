/*
 * Author: FreePascal
 * Created Time:  2011/10/30 14:07:02
 * File Name: poj3080.cpp
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
string f(vector<string> dic)
{
    int len = 0;
    string ans = "";
    for(int i = 1;i <= 60;i ++)
        if(i > len){
        for(int st = 0;st < 60 - i +1;st++)
        {
            string t = dic[0].substr(st,i);
            //out(t);
            int b= 1;
            for(int k = 1;k < dic.size();k ++)
                if( dic[k].find(t)==-1){ b = 0;break;}
            if(b)ans = t,len = t.size();
        }
        }
       return ans;
        
} 
int main() {
    int cs;
    cin>>cs;
    while(cs--)
    {
       int n;
       cin>>n;
    vector<string> dic;
   for(int i = 0;i < n;i++)
   {
      string s;
     cin>>s;
    dic.push_back(s);
   }
   string ans = f(dic);
   if(ans.size() < 3) cout<<"no significant commonalities"<<endl;
   else cout<<ans<<endl;
   //cout<<f(dic)<<endl;
    }
    return 0;
}

