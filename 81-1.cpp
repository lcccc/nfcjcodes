/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/1 19:43:28
 * File Name: 81-1.cpp
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
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int main() {
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    if( s == t) printf("YES\n");
    else printf("NO\n");
return 0;
}

