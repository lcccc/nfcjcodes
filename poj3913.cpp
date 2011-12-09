/*
 * Author: FreePascal
 * Created Time:  2011/10/30 15:04:33
 * File Name: poj3913.cpp
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
int brd[35],f[35],n;
bool isord(int a,int b,int c)
{
    if( a>=b && b>=c || a<=b && b <= c) return true;
    return false;
}
int main() {
    int n;
    cin>>n;
    cout<<"Gnomes:"<<endl;
    int a,b,c;
    while(n--){
        cin>>a>>b>>c;
        puts(isord(a,b,c)?"Ordered":"Unordered");
    }
    return 0;
}

