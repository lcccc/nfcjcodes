/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 14:40:00
 * File Name: tyvj1598.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int n;
vector<string> f;
string s1;
int main() {
    int tag[205];
    memset(tag,false,sizeof tag);
    cin>>n;
    getline(cin,s1);
    for(int i = 0;i < n;i++)
    {
        getline(cin,s1);
        //cout<<s1<<endl;
        f.push_back(s1);
    }
    int x = 1,cnt = 0,hx;
    while(1){
        tag[x] = 1;
        if(cnt > 100000) {cout<<-1<<endl;return 0;}
        cnt++;
       stringstream sin(f[x-1]);
       sin>>s1;
       //cout<<s1<<endl;
       if( s1 == "go"){
           string tmp;
          sin>>tmp;
          for(int i = 0;i <tmp.size();i++)
              if( tmp[i]>'9' || tmp[i] <'0') x++; 
              else {
                  stringstream nin(tmp);
                  nin>>x;
              }
          //cout<<x<<endl;
          if(x > n || x < 1)break; 
          }
       else x++;
       if( x > n) break;
    } 
    int ans = 0;
   for(int i = 1;i <= 200;i++)
      if( tag[i] ) ans++;
  cout<<ans<<endl; 
    return 0;
}

