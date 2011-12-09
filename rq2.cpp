/*
 * Author: FreePascal
 * Created Time:  2011/10/11 0:51:12
 * File Name: rq2.cpp
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
int ans,n,k,j;
int main() {
    scanf("%d%d",&k,&n);
    ans = 0;
    n -= 2;
    j = 1;
    while(n>0)
    {
       if( n % 2 ) ans += k*j;
       n/=2;
       j*=k;
    } 
    cout<<ans<<endl;
    return 0;
}

