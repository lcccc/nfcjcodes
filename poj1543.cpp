/*
 * Author: FreePascal
 * Created Time:  2011/10/9 19:47:27
 * File Name: poj1543.cpp
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
int n;
int a,b,c,d;
int main() {
    scanf("%d",&n);
    for(int a = 6; a <= n;a ++)
        for(int b = 2;b <=a;b ++)
            for(int c = b;c <= a;c ++)
                for(int d = c;d <= a;d ++)
                    if( a *a *a == b *b *b + c *c*c + d *d*d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
    
    return 0;
}

