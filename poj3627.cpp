/*
 * Author: FreePascal
 * Created Time:  2011/11/2 14:27:21
 * File Name: poj3627.cpp
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
int hi[20005],n,b;
int main() {
    scanf("%d%d",&n,&b);
    for(int i = 0;i < n;i ++)
        scanf("%d",&hi[i]);
    sort(hi,hi+n);
    reverse(hi,hi+n);
    int curh = 0,curn = 0;
    while(curh < b)
        curh +=hi[curn++];
    cout<<curn<<endl;
        
    return 0;
}

