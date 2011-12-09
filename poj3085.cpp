/*
 * Author: FreePascal
 * Created Time:  2011/11/5 20:40:18
 * File Name: poj3085.cpp
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
void f(int x)
{
    printf(" %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
            x / 25,x % 25 / 10,x % 25 % 10 / 5,x % 25 % 10 % 5);
}
int main() {
    int cs,t = 1;
    cin>>cs;
    while(cin>>cs)
    {
        printf("%d",t++);
        f(cs);
    }
    return 0;
}

