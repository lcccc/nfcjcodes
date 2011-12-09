/*
 * Author: FreePascal
 * Created Time:  2011/10/25 22:58:01
 * File Name: bitset.cpp
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
int getbit(int x,int k)
{
    return  (x >> k-1) & 1;
}
int main() {
    int n,k;
    while(cin>>n>>k)
        cout<<getbit(n,k)<<endl;
    return 0;
}

