/*
ID:luansha1
LANG:C++
PROG:buylow
*/
 
#include <cstdio>
#include <cstdlib>
#define MAXN 5100
#define max(a,b) ((a)>(b)?(a):(b))
 
int n, i, j, ans=0;
int d[MAXN]={};
int f[MAXN]={};
int p[MAXN]={};
int m,li;
struct llint {
       short t[51];
       int num;
       llint() {num=1;for(li=0;li<51;li++)t[li]=0;}
       inline void operator += (const llint &k)  {
              if (num>=k.num) m=num;
              else m=k.num;
              for (li=0;li<m;li++) {
                  t[li]+=k.t[li];
                  if (t[li]>=10000) {t[li]%=10000;t[li+1]++;}
              }
              if (t[li]==1) m++;
              num=m;
       }
       inline void operator ++ ()  {t[0]++;num=1;}
} g[MAXN];
struct SUM : llint {
      inline void print() {
             printf("%d",t[num-1]);
             for (li=num-2;li>=0;li--) {
                 if (t[li]<1000) putc('0',stdout);
                 if (t[li]<100) putc('0',stdout);
                 if (t[li]<10) putc('0',stdout);
                 printf("%d",t[li]);
             }
      }
} sum;
 
int main() {
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&d[i]);
        for (j=i-1;j>=0;j--) if (d[i]==d[j]) {p[j]=i;break;}
    }
    for (i=0;i<n;i++) {
        for (j=0;j<i;j++) if (d[i]<d[j]&&f[i]<f[j]) f[i]=f[j];
        if (f[i]!=0) {for (j=0;j<i;j++) if (f[j]==f[i]&&d[i]<d[j]&&(p[j]==0||p[j]>i)) g[i]+=g[j];}
        else ++g[i];
        f[i]++;
    }
    for (i=0;i<n;i++) ans=max(ans,f[i]);
    printf("%d ",ans);
    for (i=0;i<n;i++) if (f[i]==ans&&p[i]==0) sum+=g[i];
    sum.print();
    printf("\n");
    return 0;
}

