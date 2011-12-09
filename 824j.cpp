/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/24 12:44:03
 * File Name: 824j.cpp
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
LL gcd(LL a,LL b)
{
    if( b == 0) return a;
    else return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/__gcd(a,b)*b;
}
vector<LL> fac;
inline LL f(LL x){
    LL ans = 0;
    fac.clear();
    for(LL i = 1;i <= sqrt(x);i++)
        if(x % i == 0) 
        {
            fac.push_back(i);
            if( i != x/i)
            fac.push_back(x / i);
        }
    sort(fac.begin(),fac.end());
   for(int i = 0;i<fac.size();i++)
   {
       for(int j = i;j < fac.size() ;j++)
       {
           if(fac[i]*fac[j]<x)continue;
           if(lcm(fac[i],fac[j]) == x){ans++;
           }
       }
   }
   return ans;
}
int main() {
    LL l,k;
    map<LL,LL> db;
    while(scanf("%lld",&l) != EOF)
    {
        if(l <= 0) return 0;
        if(db[l] == 0)
        {
        k = f(l);
        db[l] = k;
        printf("%lld\n",k);
        }
        else printf("%lld\n",db[l]);
    }
    return 0;
}

