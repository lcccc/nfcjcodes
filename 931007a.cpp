/*
 * Author: FreePascal
 * Created Time:  2011/9/3 16:24:45
 * File Name: 931007a.cpp
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

int ax[1010];
int ay[1010];
int nx[1010];
int ny[1010];
int sx[1010];
int sy[1010];
int totx, toty;
map <int, int> mx;
map <int, int> my;

int tree[1010][1010];

void inittree()
{
    for (int i=0; i<=totx+1; i++)
     for (int j=0; j<=toty+1; j++)
         tree[i][j]=0;
}

#define lowbit(a)   ( (a) & (-(a)) )
void add(int x, int y)
{
    while (x <= totx+1)
    {
        int ky=y;
        while (ky <= toty+1)
        {
            ++tree[x][ky];          
            ky += lowbit(ky);  
        }
        x += lowbit(x);
    }
}

int query(int x, int y)
{
    if (x <= 0 || y <= 0) return 0;
    int sum = 0;
    while (x > 0)
    {
        int ky = y;
        while (ky > 0)
        {
               sum += tree[x][ky];
               ky -= lowbit(ky);
        }     
        x -= lowbit(x);
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2)
{
    return query(x2, y2)+query(x1-1, y1-1)-query(x1-1, y2)-query(x2, y1-1);    
}


template <typename T, typename CR>
T unupper_bound(T a, T b, const CR &c)
{
    T p = lower_bound(a, b, c);
    if (p < a)
        return a;
    if (p == b)
        return p-1;
    if (*p == c)
        return p;
    else
        return p-1;
}

int main() 
{
//    freopen("931007a.out", "w", stdout);
    int N, R;
    while (scanf("%d%d", &N, &R)!=EOF)
    {
        for (int i=0; i<N; i++)
            scanf("%d%d", &ax[i], &ay[i]);
        /* 
        memcpy(nx, ax, sizeof(int)*N);
        memcpy(ny, ay, sizeof(int)*N);
        totx = toty = N;
        #define discret(x)\
            sort(n##x, n##x+tot##x);\
            tot##x = unique(n##x, n##x+tot##x) - n##x;\
            for (int i=0; i<tot##x; i++)\
                m##x[ n##x[i] ] = i+1,\
                s##x[ i ] = unupper_bound(&n##x[i], &n##x[tot##x], n##x[i]+R)-n##x+1;
//        for (int i=0; i<=totx; i++)           printf("%d %d\n", nx[i], sx[i]);
//        for (int i=0; i<=totx; i++)           printf("%d %d\n", ny[i], sy[i]);
        
        discret(x);
        discret(y);
        
        inittree();
        for (int i=0; i<N; i++)
            add(mx[ax[i]], my[ay[i]]);
        
        int ans = 0;
        for (int i=0; i<=totx; i++)
            for (int j=0; j<=toty; j++)
                ans = max(ans, query(nx[i], nx[j], sx[i],  sx[j]));            
        printf("%d\n", ans);
        */
        int ans = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                int x =ax[i];
                int y =ay[j];
                int cnt=0;
                for (int k=0; k<N; k++)
                {
                    if (x+R >= ax[k] && y+R >= ay[k])
                        cnt++;   
                }
                ans = max(ans, cnt);
            }
        printf("%d\n", ans);
    }
    return 0;
}

