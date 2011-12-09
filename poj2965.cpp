/*
 * Author: FreePascal
 * Created Time:  2011/10/27 15:36:40
 * File Name: poj2965.cpp
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
int cb[5][5];
int main() {
    for(int i = 1;i < 5; i ++)
        for(int j = 1;j < 5;j ++)
        {
            char c;
            cin>>c;
            if(c == '+')
            {
                for(int t = 1;t < 5;t++)
                { cb[i][t] ++;cb[t][j]++;
                }
                cb[i][j] --;
            }
        }
    int ans = 0;
    for(int i = 1;i < 5;i ++)
        for(int j = 1;j < 5;j ++)
            if(cb[i][j] & 1) ans ++;
    cout<<ans<<endl;
    for(int i = 1;i < 5;i ++)
        for(int j = 1;j < 5;j ++)
            if(cb[i][j] & 1) cout<<i << ' ' << j <<endl;
    return 0;
}

