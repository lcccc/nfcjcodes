/*
 * Author: FreePascal
 * Created Time:  2011/10/30 15:27:34
 * File Name: poj3852.cpp
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
vector<string> dic;
bool stringld(){
    //out("stringld");
    for(int i = 0;i < dic.size();i ++)
        if( dic[i] == "") return false;
    for(int i = 0;i < dic.size();i ++)
        for(int j = i+1;j < dic.size();j++)
            if(dic[i] == dic[j]) return false;
    for(int i = 0;i < dic.size();i ++)
        dic[i] = dic[i].substr(1);
    return true;
}
string s;
int main() {
    int n;
    while(cin>>n && n)
    {
        dic.clear();
        for(int i = 0;i < n;i ++)
        {
           cin>>s;dic.push_back(s);
        }
       int ans = 0;
      while(stringld() ) ans++;
     cout<<ans-1<<endl;
    } 
    return 0;
}

