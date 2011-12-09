#include <cstring>
#include <cstdio>
#define maxn 20003
const int oo=100000;
int n, ans;
int k;
int a[maxn], b[maxn], link[maxn];
int f[maxn], loc[maxn];
int p[maxn], q[maxn];

void solve(int k)
{
    int h=1;
    int t=1;
    f[1]=oo;
    loc[1]=-oo;
    for (int i=1; i<=n; i++)
    {
        while ((h<=t) && (f[t]<link[i])) t--;
        t++; f[t]=link[i]; loc[t]=i;
        while ((h<t) && (loc[h]<i-k+1)) h++;
        p[i]=f[h];
    }

    h=1; t=1;
    f[1]=-oo;
    loc[1]=-oo;
    for (int i=1; i<=n; i++)
    {
        while ((h<=t) && (f[t]>link[i])) t--;
        t++; f[t]=link[i]; loc[t]=i;
        while ((h<t) && (loc[h]<i-k+1)) h++;
        q[i]=f[h];
    }

    for (int i=k; i<=n; i++)
        if (p[i]-q[i]+1==k) ans++;

}
void prepare()
{

    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=n; i++) scanf("%d", &b[i]);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (a[i]==b[j])
            {
                link[i]=j;
                break;
            }
    ans=1;
    for (k=2; k<n; k++)
        solve(k);
    printf("%d\n\n\n", ans);

}
int main()
{    
    scanf("%d", &n);
    while (n!=0)
    {
        prepare();
        scanf("%d", &n);

    }
    return 0;

}

