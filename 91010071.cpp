/*
 * Author: FreePascal
 * Created Time:  2011/9/10 13:52:41
 * File Name: 9101007.cpp
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
#define each(i,s,t) __typeof(s) i=s, i##ed=t; i!=i##ed; i++
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef long long i64;
int N;
i64 a[100010];
i64 s[200010];
int Q;

int lowbit(int x) { return x & -x; }
void add(int x, i64 v)       { while (x<=N) { a[x]+=v; x += lowbit(x); } }
int query(int x, i64 sum=0)  { while (x)    { sum +=a[x]; x-=lowbit(x);} return sum;} 

int modify(int x) {   
    i64 k = query(x) - query(x-1);
    i64 a = (i64)sqrt(k + 1e-6);
    add(x, a-k);
}

int main() 
{

    while ( scanf("%d",&N) != EOF )
    {
           for (each(i, 0, N)){
                i64 u;
                scanf("%I64d", &u);  
                add(i+1, u);
            }
           scanf("%d", &Q);
           static int ncase = 0;
           printf("Case #%d:\n", ++ncase);
           for (each(i, 0, Q))
           {
               int q, u, v;
               scanf("%d%d%d", &q, &u, &v);
               if (q == 0){
                    for (int i=u; i<=v; i++)
                        modify(i);   
               }else{
                    printf("%I64d\n", query(v) - query(u-1));   
               }
           }
           puts("");
    }
    return 0;
}

