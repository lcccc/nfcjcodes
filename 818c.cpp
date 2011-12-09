/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/18 20:10:19
 * File Name: 818c.cpp
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
int f(int x)
{
    int ans = 0,k = 1,cnt = 1;
    while( x > 0 )
    {
        ans+= min(x,k)*cnt;
        cnt++;
        x-=k;
        k+=k;
    }
    return ans;
}
int main() {
    int n;
    while(cin>>n)
    {
       printf("%.2lf\n", (f(n)+0.0)/n); 
        
    }
    return 0;
}

