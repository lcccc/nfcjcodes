/*
 * Author: FreePascal
 * Created Time:  2011/10/22 12:56:09
 * File Name: poj3518.cpp
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
int pm[100000];
bool ispm(int x){
    for(int i = 2;i <= trunc(sqrt(x)); i ++)
        if(! ( x % i) ) return false;
    return true;
}
void init(){
    int tot = 0;
    for(int i = 2; i <=1299709;i ++)
       if(ispm(i)) pm[tot++] = i;
} 
int f(int x)
{
    if(ispm(x)) return 0;
    for(int i = 0;i < 100000;i ++)
        if(pm[i] < x && pm[i+1] > x)
            return pm[i+1] -pm[i];
}
int main() {
    init();
    int n;
    while(cin>>n && n)
        cout<<f(n)<<endl;
    return 0;
}

