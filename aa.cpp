/*
 * Author: FreePascal
 * Created Time:  2011/12/4 12:33:30
 * File Name: 
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
#include <time.h>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int main() {
    int cas = 100;
    freopen("a.in", "w", stdout);
    srand(time(NULL));
    while(cas--) {
        int a = rand() % 1000, b = rand() % 1000;
        printf("%d %d\n", a, b);
    }
    return 0;
}

