/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/15 23:19:25
 * File Name: hdu1108.cpp
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
int gcd(int a,int b)
{
    if( b == 0) return a;
    else return gcd(b,a%b);
}
int gcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main() {
    int a,b;
    while(cin>>a>>b)
        cout<<gcm(a,b)<<endl;
    
    return 0;
}

