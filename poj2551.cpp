/*
 * Author: FreePascal
 * Created Time:  2011/10/12 17:14:39
 * File Name: poj2551.cpp
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
int f(int x)
{
    int n = 1,r = 1,c = 1 % x,ans = 1;
    while(c != 0)
    {
        ans ++;
        c = (c*10 +1 )% x;
    }
    return ans;
}
int main() {
    int n;
    while(scanf("%d",&n) == 1)
    {
        printf("%d\n",f(n));
    }
    return 0;
}

