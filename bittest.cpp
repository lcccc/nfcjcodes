/*
 * Author: FreePascal
 * Created Time:  2011/10/6 23:09:19
 * File Name: bittest.cpp
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
bool testIt(int x)
{
    return (x & (x-1)) == 0;
}
int main() {
    for(int i = 0;i < 20;i ++)
    {
        out(i);
        out(testIt(i));
                }
    return 0;
}

