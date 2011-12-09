/*
 * Author: FreePascal
 * Created Time:  2011/10/30 15:17:28
 * File Name: poj3994.cpp
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

int main() {
    int t = 1,n0,n1,n2,n3,n4;
    while(cin>>n0 && n0)
    {
        n1 = 3 * n0;
        n2 = (n1+1) / 2;
        n3 = n2 * 3;
        n4 = n3 / 9;
        printf("%d. %s %d\n",t++, n1 % 2?"odd":"even",n4);
    }
    return 0;
}

