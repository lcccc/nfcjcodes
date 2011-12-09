/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/27 13:31:08
 * File Name: 8271.cpp
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
LL f(int x)
{
    LL f[50];
    f[0] = 1;
    f[1] = 1; 
    for(int i = 2;i <= x;i++)
        f[i] = f[i-1] + f[i-2];
    return f[x];
}
int main() {
    int a,b;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<f(b-a)<<endl;
    }
    return 0;
}

