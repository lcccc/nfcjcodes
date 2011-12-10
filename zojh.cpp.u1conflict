/*
 * Author: FreePascal
 * Created Time:  2011/10/29 14:51:03
 * File Name: zojh.cpp
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
const long long MOD = 1000000007;
long long mult_exp(long long a,long long x){
   long long b,ans;
  ans = 1;
 while( x > 0){
    if( x & 1) ans = ans*a % MOD;
    a =  a*a % MOD;
    x = x >> 1;
 }
return ans;
}
int main() {
    long long n,k;
    while(cin>>n>>k){
        if(k == 1) cout<<1<<endl;
        else
        cout<<mult_exp(k+1,n)<<endl;
    }
    return 0;
}

