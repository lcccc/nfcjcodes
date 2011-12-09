/*
 * Author: Nfcj
 * Created Time:  2011年07月27日 星期三 12时59分40秒
 * File Name: 727b.cpp
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
int f[100001],c[100001],n;

int lowbit(int t)
{
    return t&(t ^ (t-1));
}

int sum(int end)
{
    int ans = 0;
    while( end > 0)
    {
        ans += c[end];
        end -= lowbit(end);
    }
    return ans;
}

void plusx(int pos,int num)
{
    while(pos <= n)
    {
        c[pos] += num;
        pos += lowbit(pos);
    }
}


int find(int x)
{
    int left=1,right=n,mid;
    while(left<right)
    {
          mid=(left+right)>>1;
          if(sum(mid)>=x)right=mid; 
          else left=mid+1;         
          }
    return right;    
    }        
int main() {
    while(scanf("%d",&n)!=EOF)
    {
        for( int i=1; i<=n ;i++)
        {
            scanf("%d",&f[i]);
            plusx(i,f[i]);
        }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        char op;
        int a,b;
        scanf("%c",&op);
        scanf("%c",&op);
        if(op == 'p') {
            scanf("%d%d",&a,&b);
            plusx(a,b-f[i]);
            f[i] = b;
        }
        else {
           scanf("%d",&a);
             printf("%d\n",find(a));
             } 
        }
    }
    
    return 0;
}

