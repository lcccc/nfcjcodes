/*
 * Author: FreePascal
 * Created Time:  2011/9/10 13:13:06
 * File Name: 9101001.cpp
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
#define _t(v...) __typeof(v)
#define each(i, s, t) _t(s) i=s; i!=t; i++

const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int T;
int a[24];
int b[24];

int parity(int *a)
{
    int ans = 0;
    for (int i=0; i<24; i++)
        for (int j=0; j<i; j++)
            if (a[i] < a[j]) ans++;
    return ans%2;
}
int main() {
    scanf("%d", &T);
    while (T--)
    {
        for (each(i, &a[0], &a[24]))  scanf("%d", i);
        for (each(i, &b[0], &b[24])) scanf("%d", i);
        puts( parity(a) == parity(b) ? "Y" : "N" );
    }
    return 0;
}

