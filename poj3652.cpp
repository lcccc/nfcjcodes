#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int BORDER = (1<<20)-1;
const int MAXSIZE = 37;
const int MAXN = 1250;
const int INF = 0x7ffffff;
#define CLR(x,y) memset(x,y,sizeof(x))
#define ADD(x) x=((x+1)&BORDER)
#define IN(x) scanf("%d",&x)
#define OUT(x) printf("%d\n",x)
#define MIN(m,v) (m)<(v)?(m):(v)
#define MAX(m,v) (m)>(v)?(m):(v)
#define ABS(x) (x>0?x:-x)
    
int high_use,A,B,C,S;
int visit[(1<<20)-1];
bitset<32> mask;

int init()
{
    high_use = -1;
    CLR(visit,0);
    return 0;
}
int work(int a,int b,int c,int s)
{
    int mmax = s;
    visit[s] = 1;
    int cur = (s*a + b)%c;
    mask.set();
    while(true)
    {
        mmax = MAX(mmax,cur);
        mask &= (~(cur^s));
        cur = (cur*a+b)%c;
        if(visit[cur])
            break;
        else
            visit[cur] = 1;
    }
    for(int i = 15; i >= 0; --i)
        if(mmax >= (1<<i))
        {
            high_use = i;
            break;
        }
    return 0;
}
int output()
{
    int i,j;
    for(i = 15; i > high_use; --i)
        printf("0");
    for(i = high_use; i >= 0; --i)
        if(mask.test(i))
        {
            if(S&(1<<i))
                printf("1");
            else
                printf("0");
        }
        else
            printf("?");
    printf("\n");
    return 0;
}
int main()
{
    while(IN(A))
    {
        if(!A)
            break;
        scanf("%d%d%d",&B,&C,&S);
        init();
        work(A,B,C,S);
        output();
    }
    return 0;
}

