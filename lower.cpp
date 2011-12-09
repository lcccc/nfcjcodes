/*
 * Author: FreePascal
 * Created Time:  2011/12/5 23:27:35
 * File Name: lower.cpp
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

int main() {
    string s = "mQmPtphqGrboHhmgaqVhCdwTwignlQvjIopDqVpgaNrwkAzVcnkHyNiPdSmgJmgrPiMjpnjdbuPucHnouwfKuPcybromnmbvfxJqRnnOvWsceZeYzRyqnkaaFsffjenxoIhqHnIzorlOdwZoxYmAuNwNnRpp";
    map<char,int> ans;
    int tot = 0;
    for(int i = 0;i < s.size();i ++)
        if( s[i] <= 'z' && s[i] >= 'a') tot++;
    //for(char a = 'a' ; a <= 'z'; a++)
        //if(ans[a]) tot++;
    
    cout<<tot<<endl;
    return 0;
}

