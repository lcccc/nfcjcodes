/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 14时47分34秒
 * File Name: 8161005.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

int factor[1300][10010];
int pr[1300];
int primindex[10010];
typedef long long i64;

int pnumber (int N, int p)
{
    int ans = 0;
    while (N)
        ans += N/p, N/=p;
    return ans;
}

int fact(int N, int p)
{
    int a   = N/p, b = N%p;
    int ret = factor[primindex[p]][b];
    if (a % 2 == 1)
        return -ret;
    else
        return ret;
}

int extend_euc(int a, int b, int &x, int &y)
{
    int d, t;
    if (b==0)
        return x=1, y=0, a;
    return d = extend_euc(b, a%b, x, y), t=x, x=y, y=t-a/b*x, d;
}

int divide(int a, int b, int p)
{
    int x, y;
    extend_euc(b, p, x, y);
    x%=p;
    if (x<0) x+=p;
    return ((long long)a*x)%p;
}

void dowork(int N, int K, int P)
{  // (n+1)! / (k+1)! / (n-k)!
   static int ncase = 0;
   printf("Case #%d: ", ++ncase);
   int min = N-K;
   int a = pnumber(N+1, P);
   int b = pnumber(K, P) + pnumber(N-K+1, P);
   if (a>b) {
       printf("%d\n", ((min+P)%P+P)%P);
       return;
   }
   int ans = divide(divide(fact(N+1, P), fact(K, P), P), fact(N-K+1, P) ,P);
   printf("%d\n", ((min+ans)%P+P)%P);
}

int main() {
    int prime = -1;
    for (int i=2; i<=10000; i++)
    {
        prime++;
        int q = prime;
        for (int j=2; j<=i/j; j++)
            if (i%j==0)
            {
                prime--;
                break;
            }
        if (q == prime)
        {
            int thisprime = pr[q] = i;
            primindex[thisprime] = q;
            factor[q][0] = 1;
            for (int j=1; j<thisprime; j++)
               factor[q][j] = factor[q][j-1] * j % thisprime;
        }        
    }
    int n, k, p;
    while (scanf("%d%d%d", &n, &k, &p)!=EOF)
        dowork(n, k, p);
    return 0;
}

