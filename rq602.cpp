/*
 * Author: FreePascal
 * Created Time:  2011/10/11 11:43:52
 * File Name: rq602.cpp
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
int num2(int x)
{
    int ans = 0;
    while( x > 0 )
    {
        if( x % 10 == 2)ans++;
        x  /= 10;
    }
    return ans;
}
int query(int l,int r)
{
    long long ans  = 0;
    for(int i = l;i <= r;i ++)
        ans+=num2(i);
    return ans;
}
int main() {
    int l,r;
    cin>>l>>r;
    cout<<query(l,r)<<endl;
    return 0;
}

