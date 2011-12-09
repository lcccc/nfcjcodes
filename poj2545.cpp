/*
 * Author: FreePascal
 * Created Time:  2011/10/12 18:03:49
 * File Name: poj2545.cpp
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
long long *a;
int len ,l,l1,l2,l3,ll[3];
int main() {
    int n,k,i;
    long long min;
    while(cin>>ll[0]>>ll[1]>>ll[2]>>k)
    {
        a = new long long[k+1];
        sort(ll,ll+3);
        a[0] = 1;
        len = 1;
        l1 = l2 = l3 = 0;
        while(len <= k)
        {
            min = a[l1] * ll[0];
            l = 1;
            if(a[l2] * ll[1] < min) min = a[l2]*ll[1],l = 2;
            if(a[l3] * ll[2] < min) min = a[l3]*ll[2],l = 3;
            if( a[len - 1] != min)
                a[len++] = min;
            if(l == 1) l1++;
            if(l == 2) l2++;
            if(l == 3) l3++;
        }
        cout<<a[k]<<endl;
        delete []a;
    }
    return 0;
}

