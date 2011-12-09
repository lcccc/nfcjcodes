/*
 * Author: FreePascal
 * Created Time:  2011/9/10 12:13:23
 * File Name: 9101008.cpp
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
void* k = freopen("9101008.out", "w", stdout);

int F[1001][1001];
int getAns(int n, int m)
{
        if (m<n) return 0;
        if (n==m || n==0) return 1;
        return F[n][m] != -1?
               F[n][m] :
               F[n][m] = getAns(n-1, m-1) + getAns(n, m-n);
}

int main()
{
    memset(F, -1, sizeof(F));
    int N, M;
    while ( scanf("%d%d", &N, &M)!=EOF )
    {
        int ans = 0;
        ans+=getAns(N, M+N);
        printf("%d\n", ans);
    }
    return 0;
}

