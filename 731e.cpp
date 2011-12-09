#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int kMaxn(107);
const int kMaxs(1007);

struct Type
{
    int v,a,b;
};

int s,n,ans,d[kMaxn][kMaxs];
Type r[kMaxn];

bool cmp(const Type &a,const Type &b)
{
    return a.b > b.b;
}

bool cmp2(const Type &a,const Type &b)
{
    return ((a.a-a.b)<(b.a-b.b) || ((a.a-a.b)==(b.a-b.b) && a.a<b.a) || (((a.a-a.b)==(b.a-b.b) && a.a==b.a && a.v>b.v)));
}
bool cmp3(const Type &a,const Type &b)
{
    return (a.b>b.b || (a.b==b.b && a.a<b.a) || (a.b==b.b && a.a==b.a && a.v>b.v));
}

void DP()
{
    memset(d,0,sizeof(d));
    for(int i=1; i<=n; i++)
        for(int j=0; j<=s; j++)
        {
            d[i][j]=d[i-1][j];
            if(j>=r[i].b && j+r[i].a-r[i].b<=s)
                d[i][j]=max(d[i][j],d[i-1][j+r[i].a-r[i].b]+r[i].v);
        }

    for(int i=0; i<=s; i++)
        if(ans<d[n][i])
            ans=d[n][i];
}

int main()
{
//freopen("data.in","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&s,&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d%d",&r[i].v,&r[i].a,&r[i].b);

        ans=0;
        sort(r+1,r+n+1,cmp);
        //DP();
        //sort(r+1,r+n+1,cmp);
        //DP();
        //sort(r+1,r+n+1,cmp);
        DP();

        printf("%d\n",ans);
    }

    return 0;
}
