/*
 * Author: FreePascal
 * Created Time:  2011/10/29 21:15:12
 * File Name: cf125b.cpp
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
string s;
int main() {
    int k = 0,len = 0;
    cin>>s;
    while(k < s.size()){
    if( s[k] == '<' && s[k+1] != '/' )
    {
       for(int i = 0;i < len;i ++) cout<<' ';
       cout<<s.substr(k,3)<<endl;
       k+=3;
       len +=2;
    }
    else{
        len -=2;
       for(int i = 0;i < len;i ++) cout<<' ';
       cout<<s.substr(k,4)<<endl;
       k+=4;
    } 
    }
    return 0;
}

