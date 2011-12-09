/*
 * Author: FreePascal
 * Created Time:  2011-8-24 15:51:16
 * File Name: f.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 100000 + 100;
int n;
double f[maxn];
void dpwork(){
    f[1] = 1; f[2] = 1.5;
    double x = 0.5,base = 1.5;
    for (int i = 3; i <= 100000; i++){
        base = base + pow(0.5,i * (i - 1) / 2);
        f[i] = f[i - 2] / 2 + f[i-2] + base ;
    }
}
int main() {
    //freopen("f.out","w",stdout);
    dpwork();
    while (scanf("%d",&n) != EOF){
        if (n == 0) break;
        printf("%lf\n",f[n]);
    }
    return 0;
}

