/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 17:12:07
 * File Name: 
 */
#include <iostream>
#include "numeric"

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

int K, N, pk;
struct bignum { int v[50010], b; };
int tot = 0;
struct node {int v; int ind; bool operator <(const node &b) const {return v < b.v || v==b.v && ind < b.ind;} }a[20010];
void insert(int v)
{

    a[tot].ind = tot+1;
    a[tot].v   = v;
    tot++;
}
void add(bignum &a, const bignum &b)
{
    static bignum c;
    memset(&c, 0, sizeof(c));
    int h = max(a.b, b.b)+1;
    c.v[0] = a.v[0]+b.v[0];
    c.b = h;
    for (int i=1; i<=h; i++)
        c.v[i] = c.v[i-1]/K + a.v[i] + b.v[i],
        c.v[i-1]%=K;
    while (c.v[c.b] == 0 && c.b>0) c.b--;
    int v = 0;
    for (int i=0; i<=c.b; i++)
    {
           int k = c.v[i];
           while (k>0) v+=k%pk, k/=pk;
    }
    insert(v);
    a=c;
}
bignum aa,ab;
int main() {
    while (scanf("%d%d", &K, &N)!=EOF)
    {
            pk = K;
            K=K*K;
            K=K*K;
            K=K*K;
            tot = 0;
            memset(&aa, 0, sizeof(aa));     
            memset(&ab, 0, sizeof(ab));     
            aa.v[0]=1;
            ab.v[0]=1;
            insert(1);
            insert(1);
            for (int i=2; i<=N; i++)
            {
                if (i&1)
                    add(aa,ab);  
                else
                    add(ab,aa);
            }
            sort(::a, ::a+N);
            for (int i=0; i<N; i++)
                if (i) printf(" %d", ::a[i].ind);
                else
                    printf("%d", ::a[i].ind);
            printf("\n");
    }
    return 0;
}

