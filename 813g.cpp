/*
 * Team : FreePascal
 * Created Time:  2011年08月13日 星期六 17时15分03秒
 * File Name: 813g.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "cmath"
using namespace std;
#define SZ(v) ((int)(v).size())

int T;
int N;
long long x, y;
struct Point{
    int x, y;
};

Point Get(long long r, int N)
{
       static Point org   [] = {{0,0}, {0,1}, {1,1}, {1,0}}; 
       if (N==1) {
            return org[r];
       }
           Point p;
           long long y = x/4;
           if ( r < y) 
           {
               Point z = Get(r, N-1);
               p.x  = z.y ;
               p.y  = z.x ; 
            }
            else if ( r < 2*y)
            {
               Point z = Get(r, N-1);
               p.x     = z.x ;
               p.y     = z.y +  (1<<(N-1));
            }
            else if ( r < 3*y)
            {
               Point z = Get(r, N-1);
               p.x     = z.x + (1<<(N-1));
               p.y     = z.y + (1<<(N-1));
            }
            else 
            {
               Point z = Get(r, N-1);
               p.x     = (1<<(N-2))-z.x + (1<<(N-1));
               p.y     = (1<<(N-2))-z.y ;
            }
    return p;
}

int main() {
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%Illd%lld", &N, &x, &y);
        Point A, B;
        A = Get(x-1, N);
        B = Get(y-1, N);
        printf("%d %d\n", A.x, A.y);
        printf("%d %d\n", B.x, B.y);
        printf("%.0f\n", 10*hypot(A.x-B.x, A.y-B.y));
    }
    return 0;
}
