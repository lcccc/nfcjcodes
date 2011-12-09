/*
 * Author: FreePascal
 * Created Time:  2011/9/3 13:51:22
 * File Name: 931002list.cpp
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

unsigned euler(unsigned x){
    unsigned i, res = x;
    for (int i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
        if (x % i == 0){
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
int n,ans;
double Max;
int main() {
    freopen("list.txt","w",stdout);
    Max = 0;
    n = 1000;
    printf("i x i/x max\n");
    for (int i = 2; i < n; i++){
        int x = euler(i);
        if ((double)i / x > Max){
            Max = (double)i / x;
            //out(Max);
            ans = i;
        }
        printf("%d %d %d %d\n",i,x,i / x,ans);
    }
    return 0;
}

