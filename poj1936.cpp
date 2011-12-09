/*
 * Author: FreePascal
 * Created Time:  2011/10/30 14:28:47
 * File Name: poj1936.cpp
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
bool sub(string s,string t)
{
    int ps = 0,pt = 0;
    while(ps < s.size())
    {
        while(t[pt] != s[ps] && pt < t.size()) pt++;
        if( pt >= t.size()) return false;
        ps++;
        pt++;
    }
   return true;
} 
int main() {
    string s,t;
    while(cin>>s>>t) puts(sub(s,t)?"Yes":"No");
    return 0;
}

