/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 12时36分52秒
 * File Name: 8a4.cpp
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
const int modulo = 1000000007;


long long extgcd(long long a, long long b, long long &x, long long &y)
{
    long long t ,d;
    if (b==0) return x=1, y=0, a;
    else   return d = extgcd(b, a%b, x, y), t=x, x=y, y=(t-a/b*y)%modulo, d;
}

long long inv(long long a, long long p)
{
    long long x, y;
    extgcd(a, p, x, y);
    if (x>=0)
    return x;
    else   
    return (x%p+p)%p;
}


int getans(long long M, long long  N)
{
    static long long P[30010];
    if (N==1) return M%modulo;
    P[0]=1;
    for (int i=1; i<=N; i++) P[i] = P[i-1]*M % modulo;
    long long count = (N%2 ==1) ? (N * P[N/2+1]) : (N/2 * (P[N/2]+P[N/2+1]));
    count %= modulo;
    for (int i=1; i<=N; i++)
        count = (count + P[__gcd((long long)i, N)]) % modulo;
    count = count * inv(2*N, modulo);
    return count % modulo;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, M;
        scanf("%d%d", &M, &N);
        static int ncase = 0;


        printf("Case #%d: %d\n", ++ncase, getans(M,  N));
    }
    return 0;
}

