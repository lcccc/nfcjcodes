/*
 * Author: FreePascal
 * Created Time:  2011/9/7 19:51:27
 * File Name: hdu971.cpp
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
    int cs;
    cin>>cs;
    string s;
    for(int i = 1;i <= cs;i ++)
    {
        cin>>s;
        s = s.substr(s.find("//")+2);
        //out(s);
        int k ;
        for(k = 0;k < s.size();k++)
           if(s[k] == ':' || s[k] == '/') break; 
        //out(k);
        s = s.substr(0,k);
        printf("Case #%d: %s\n",i,s.c_str());
    }
    
    return 0;
}

