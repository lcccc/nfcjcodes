/*
 * Author: FreePascal
 * Created Time:  2011/10/27 23:15:27
 * File Name: cd1222.cpp
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
bool isluck(string s)
{
    for(int i = 0;i < s.size();i ++)
        if( s[i] != '4' && s[i] != '7') return false;
    return true;
}
int count(string s,string ts){
   int ans = 0;
   string ss;
   for(int i = 0;i <= s.size(); i ++)
   {
      ss = s.substr(i,ts.size());
     if( ss == ts) ans++;
   }
  return ans;
} 
string f(string s)
{
    int max = 0;
    string ans = "-1";
    map<string,int> cnt;
    for(int i = 0;i < s.size();i ++)
        for(int j = 1;j < s.size() - i + 1;j ++)
        {
            string ts = s.substr(i,j);
            //cout<<ts<<endl;
            if( isluck(ts) )
            {
                int k = count(s,ts);
                if(k == max && ts < ans) ans = ts;
                else if( k > max) { max = k;ans = ts;};
            }
        }
    return ans;
}
int main() {
    string s;
    while(cin>>s)
        cout<<f(s)<<endl;
    return 0;
}

