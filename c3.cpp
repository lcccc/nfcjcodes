/*
 * Author: FreePascal
 * Created Time:  2011/10/27 15:12:08
 * File Name: c3.cpp
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
#include <fstream>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int n,k,ans = 0,t;
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin>>n>>k;
    while(n--){
        cin>>t;
        if( t >= 3*k ) ans += t - 3*k;
        else ans += t % k;
    }
    cout<<ans<<endl;
    return 0;
}

