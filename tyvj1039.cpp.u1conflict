/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/5 9:24:57
 * File Name: tyvj1039.cpp
 */
#include <iostream>
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
struct tree{
    int left,right;
    int minn;
};
struct tree f[300000];
int a[100005];
int build(int l,int r,int p)
{
    f[p].minn = 0x7fffffff;
    f[p].left = l;
    f[p].right = r;
    if( l != r)
    {
        int mid = (l+r) >> 1;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
    }
}
int query(int l,int r,int p)
{
    if( l == f[p].left && r == f[p].right)
        return f[p].minn;
    else{
        int mid = (f[p].left + f[p].right) /2;
        int k = maxint;
      if(r<=mid)return query(l,r,p*2);
      else if (l > mid) return query(l,r,2*p+1);
      else return min(query(l,mid,p*2),query(mid+1,r,p*2+1));
}
}
void insert(int x,int p ,int n)
{
    if( f[p].left == f[p].right) {
        f[p].minn = n;
        return;
    }
    int mid = (f[p].left + f[p].right) /2;
    if(x<=mid) insert(x,p*2,n);
    else insert(x,p*2+1,n);
    f[p].minn = min(f[p*2].minn,f[p*2+1].minn);
}
/*
int update(int l,int r,int p,int x,int n)
{
   if( x <= f[p].left && x == f[p].right) {
        f[p].minn = n;
    }
    else{
    int mid = (f[p].left + f[p].right) /2,k = maxint;
    if( x <= mid ) update(l,mid,p*2,x,n);
    if( x > mid )  update(mid+1,r,p*2+1,x,n);
}
}
*/

int main() {
    int n,m,bf = 1;
    build(1,n,1);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<= n;i++){
        scanf("%d",&a[i]);
        insert(i,1,a[i]);
    }    
    for(int i=1;i<=m;i++)
    {
        int p,a,b;
        scanf("%d%d%d",&p,&a,&b);
        if( p == 1){
            printf("%d",query(a,b,1));
            if(!bf) printf(" ");
            bf = 1;
        }
        if( p == 2) insert(a,1,b);
    }
    printf("\n");
    return 0;
}

