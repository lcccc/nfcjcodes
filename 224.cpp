/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/12 20:31:51
 * File Name: 224.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int f(int x)
{
    int ans = 0;
    for(int i = 1; i <= x;i ++)
       if( x % i == 0 ) ans++;
    return ans;
}
int main() {
    //ofstream cout("output.txt");
    freopen("output.txt","w",stdout);
    int tot = 0;
    for(int i = 1; i <= 20000; i ++)
       if( f(i) > tot ){
           tot = f(i);
           printf("%d\n",i);
       }
    return 0;
}

