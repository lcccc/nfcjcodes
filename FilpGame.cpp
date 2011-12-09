/*
 * Author: FreePascal
 * Created Time:  2011/11/15 20:02:18
 * File Name: FilpGame.cpp
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
int st;
int num_one(int x){
    int ans = 0,k = 1;
    for(int i = 0;i < 16;i ++)
    {
       if( x & 1) ans++; 
       x >>= 1;
    }
    return ans;
}
int make(int st){
    int ans = maxint;
    for(int i = 0;i < 16;i ++)
    {
        if( num_one(i) < ans)
        {
            int cst = st;
            
        }
    }
}
int main() {
    unsigned n;
    while(cin>>n){
        cout<< num_one(n)<<endl;
    }
    return 0;
}

