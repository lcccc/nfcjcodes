/*
 * Team : FreePascal
 * Created Time:  2011年08月09日 星期二 13时42分10秒
 * File Name: 89e.cpp
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
#define fr(i,a,b,c,d,e,f,g,h) for(int i a; i b; i c) d; for (int i e;i f;i g) h
const int N = 1100110;
char s[2*N];
int n, sa[2*N], rank[N*2], height[N*2];
int wa[2*N], wb[2*N], wv[2*N], w[2*N];
#define fr(i,a,b,c,d,e,f,g,h) for(int i a; i b; i c) d; for (int i e;i f;i g) h
#define rdxsrt(td, ts, tdi, tsi)  fr(i,=0,<m,++,w[i]=0,=0,<n,++,w[td[tdi]=ts[tsi]]++);\
                                  fr(i,=1,<m,++,w[i]+=w[i-1],=n-1,>=0,--,sa[--w[td[tdi]]]=tsi);

void da (int n, int m)
{
    int *x=wa,*y=wb;
    rdxsrt(x, s, i, i);
    for(int j=1; ;j*=2)
    {
        int q=0;
        fr(i, =n-j, <n, ++, y[q++]=i, =0, <n, ++, if (sa[i]>=j) y[q++]=sa[i]-j);
        rdxsrt(wv, x, i, y[i]);
        swap(x,y),x[sa[0]]=0;
        int p=1;
        #define eql(sa1,sa2,l,ts) (ts[sa1]==ts[sa2]&&ts[sa1+l]==ts[sa2+l])
        for(int i=1; i<n; i++) x[sa[i]]=(eql(sa[i-1], sa[i], j, y)?p-1:p++);
        if (p>=n) break;
        m=p;
    }
}
    
void cal(int n)
{
    char *r = s;
    int k = 0;
    height[rank[0]]=0;
    fr(i, =1, <n+1, ++, rank[sa[i]]=i, =0, <n, ++,) { if (k) k--; int j=sa[rank[i]-1]; while(r[i+k]==r[j+k]) k++; height[rank[i]]=k;}
}

int main() 
{
    while (gets(s))
    {
        if (!strncmp(s, "END", 4)) break;
        
        int n = strlen(s);
        int m = n;
        reverse(s, s+m);
        for (int i=0; i<n; i++)
            s[n+i+1] = s[i];
        reverse(s, s+m);
        s[m]='0';
        s[m+m+1]=0;
        n = n+n+2;
        memset(sa, 0, min((n+10)*sizeof(int), sizeof(sa)));
        da(n, 256);
        cal(n-1);
        int ans = 0;
        for (int i=0; i<n-1; i++)
        {
            //printf("%s %d\n", s+sa[i], height[i+1]);
            if (ans < height[i+1])
            {
                if (sa[i] < m && sa[i+1] > m
                ||  sa[i] > m && sa[i+1] < m)
                    ans = height[i+1];
            }
        }
        static int ncase = 0;
        printf("Case %d: %d\n", ++ncase, ans);
    }
    return 0;
}

