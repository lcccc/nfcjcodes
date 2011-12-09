/*
 * Author: FreePascal
 * Created Time:  2011/9/3 12:38:54
 * File Name: 931004.cpp
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

int L, N, M;
int stones[500010];


bool check(int p)
{
    int q = 0, m = M;
    do
    {
        if (stones[q]+p>=L) return true;
        int k = lower_bound(&stones[q], &stones[N+2], stones[q]+p)-stones;
        if (stones[k]>stones[q]+p) k--;
        q = k;
    } while (--m);   
    return false;
}

int main() 
{
    while (scanf("%d%d%d", &L, &N, &M)!=EOF)
    {
        stones[0] = 0;
        for (int i=1; i<=N; i++) scanf("%d", &stones[i]);    
        stones[N+1] = L;
        sort(stones+1, stones+N+1);
        int l=1, r=L+1; 
        int ans;
        while (l <= r)
        {     
            int mid = (l+r)/2;
            if (check(mid)) {
                r = mid-1;
                ans = mid;
            }
            else l = mid + 1;
        } 
        printf("%d\n", ans);
    }
    return 0;
}

