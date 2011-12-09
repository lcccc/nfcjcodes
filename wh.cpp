/*
 * Author: FreePascal
 * Created Time:  2011/11/3 14:41:35
 * File Name: wh.cpp
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
struct px {
    int x,y;
};
int mycmp(px a,px b)
{
    return a.x < b.x;
}
px f[10];
int main() {
    int n;
    for(int i = 0;i < 5;i ++)
        cin>>f[i].x>>f[i].y;
    sort(f,f+5,mycmp);
    for(int i = 0;i < 5;i++)
        cout<<f[i].x<<' '<<f[i].y<<endl;
    return 0;
}

