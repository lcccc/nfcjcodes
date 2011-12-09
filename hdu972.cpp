/*
 * Author: FreePascal
 * Created Time:  2011/9/7 20:09:56
 * File Name: hdu972.cpp
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
vector<int> f;
int main() {
    int T,cs = 1;
    //cin>>T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,a,b;
        f.clear();
        scanf("%lld%lld%lld",&n,&a,&b);
        for(int i = 0;i < n;i++) {
            int k ;
            //cin>>k;
            scanf("%d",&k);
            f.push_back(k);
        }
        sort(f.begin(),f.end());
        long long cost = 0;
        cost += a+b;
        for(int i = 1;i < f.size();i++)
        {
            cost+= b;
            cost+= min( 2LL*a, (f[i] - f[i-1] -1)* (long long)b);
        }
        cost+= a;
        printf("Case #%d: %lld\n",cs++,cost);
    }
    return 0;
}


