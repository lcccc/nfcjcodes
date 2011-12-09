/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/16 0:48:08
 * File Name: hdu1014.cpp
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
bool f(int step,int mod)
{
    map<int,int> tag;
    tag[0] = 1;
    int next = 0,len = 1;
    next = (next  + step ) % mod;
    while(! tag[next] )
    {
        //cout<<next<<' '<<len<<endl;
        len ++;
        next = (next + step) % mod;
    }
    //cout<<len<<endl;
    if( len == mod  ) return true;
    return false;
}
int main() {
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%10d%10d",a,b);
        string res;
        f(a,b)?  res = "Good Choice\n": res = "Bad Choice\n";
        printf("    %s",res.c_str());
        printf("\n");
    }
    return 0;
}

