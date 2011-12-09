/*
 * Author: FreePascal
 * Created Time:  2011/10/27 23:01:35
 * File Name: cd1221.cpp
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
int ln[1005];
bool isluck(int i){
    while( i > 0 )
    {
        if( i % 10 != 4 && i % 10 != 7) return false;
        i /= 10;
    }
    return true;
}
void init(){
    memset(ln,0,sizeof ln);
    for(int i = 1;i <= 1000;i ++)
        if( isluck(i) ) ln[i] =1;
        else {
            for(int j = 1;j < i ;j ++)
                if( ln[j] && i % j == 0) ln[i] = 1;
        }
}
int main() {
    init();
    int n;
    for(int i = 1;i <= 1000;i ++)
        if(ln[i]) cout<<i<<endl;
    cin>>n;
    if( ln[n] ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

