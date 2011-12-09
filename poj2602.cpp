/*
 * Author: FreePascal
 * Created Time:  2011/9/4 22:02:38
 * File Name: poj2602.cpp
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
const int maxlen = 1000005;
int a[maxlen], b[maxlen], n;
int main() {
    scanf("%d",&n);
    for(int i = n;i >0;i--)
       scanf("%d%d",&a[i],&b[i]);
    int y = 0;
    for(int i = 1;i <= n;i++)
    {
       a[i+1]  += (a[i] + b[i]) / 10;
        a[i] = (a[i] + b[i]) % 10; 
    }
    for(int i = n;i >= 1;i--)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}

