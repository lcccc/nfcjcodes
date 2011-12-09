/*
 * Author: FreePascal
 * Created Time:  2011/10/27 15:12:02
 * File Name: c2.cpp
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

int main() {
    return 0;
}

    int n,k;
    int f[1005];
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        cin>>f[i];
    k --;
    while(!f[k]) k++,k%=n;
    cout<<k+1<<endl;
    return 0;
}

