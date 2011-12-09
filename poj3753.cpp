/*
 * Author: FreePascal
 * Created Time:  2011/10/30 15:45:39
 * File Name: poj3753.cpp
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
int safecopy(string s,string key)
{
    if(key == "NULL") {cout<<"0 NULL"<<endl;return 0;}
    int k  = s.find(key);
    if(k == -1) k = s.size();
    if(k==0) cout<<k<<' '<<"NULL\n";
    else cout<<k<<' '<<s.substr(0,k)<<endl;
    return k;
}
int main() {
    string s,key;
    
    while(cin>>s){
    while(cin>>key && key!="END")
        safecopy(s,key);
    }
    return 0;
}

