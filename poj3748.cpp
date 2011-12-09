/*
 * Author: FreePascal
 * Created Time:  2011/10/30 16:02:12
 * File Name: poj3748.cpp
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
unsigned int r,x,y;
void set0(int k)
{
    r = (r & ~( 1 << k));
}
void set1(int k)
{
    r = r | (1 << k );
}
int main() {
    scanf("%x,%d,%d",&r,&x,&y);
    set0(x);
    set1(y);
    set1(y-1);
    set0(y-2);
    printf("%x\n",r);
    return 0;
}

