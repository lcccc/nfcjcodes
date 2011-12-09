/*
 * Author: FreePascal
 * Created Time:  2011/10/26 0:31:16
 * File Name: poj2636.cpp
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
int cs;
int main() {
    cin>>cs;
    while(cs --){
        int k,t,ans = 0;
        cin>>k;
        ans -= k;
        for(int i = 0;i < k; i ++)
        {
            cin>>t;
            ans += t;
        }
        cout<< ans +1 <<endl;
    }
    return 0;
}

