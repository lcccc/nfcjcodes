/*
 * Author: FreePascal
 * Created Time:  2011/11/26 13:56:21
 * File Name: cf131a.cpp
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
bool isCaps(string s){
    s = s.substr(1);
    for(int i = 0;i < s.size();i ++)
        if( s[i] >'Z' || s[i] < 'A') return false;
    return true;
}
string f(string s){
    if(!isCaps(s))return s;
    else {
        for(int i = 0;i < s.size();i ++)
            if(s[i] <='z' && s[i] >='a')
                s[i] += 'A' -'a';
            else s[i] += 'a' - 'A';
    return s;
    }
}       
int main() {
    string s;
    while(cin>>s){
        cout<<f(s)<<endl;
    }
    return 0;
}

