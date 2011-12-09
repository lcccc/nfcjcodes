/*
 * Author: FreePascal
 * Created Time:  2011/11/12 20:00:21
 * File Name: rq650.cpp
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
int f(int x){
    int ans = sqrt(2*x);
    ans = - 1;
    while( ans*(ans+1) <= 2*x)  ans++;
    return ans - 1;
}
int main() {
    //cout<<f(3)<<endl;
    long long n,ans = 0;
    while(cin>>n){
        ans = 0;
        while(n > 0){
            ans += f(n);
            //out(n);
            n -= f(n)*(f(n)+1) / 2;
            //out(f(n));
            //out(ans);
        }
    cout<<ans<<endl;
    }
    return 0;
}

