#include <iostream>
#include<vector>
const int N=10002;
using namespace std;
int low[N],dfn[N],instack[N],belong[N],stap[N];
vector<int>qs[N];
int ief,top,cnt;
void targan(int i)
{
 int k;
 dfn[i]=low[i]=++ief;
 stap[++top]=i;
 instack[i]=true;
 for(int j=0;j<qs[i].size();j++)
 {
    k=qs[i][j];
    if(!dfn[k])
    {
     targan(k);
     if(low[i]>low[k])
     low[i]=low[k];
    }
    else if(instack[k]&&dfn[k]<low[i])
    low[i]=dfn[k];
 }
    if(low[i]==dfn[i])
    {
     cnt++;
     do
     {
      k=stap[top--];
      instack[k]=false;
      belong[k]=cnt;
     }while(i!=k);
    }
 
}
int main()
{
      int n,m,i,a,b,t;
      while(scanf("%d%d",&n,&m)!=EOF)
      {
       if(n==0&&m==0)break;
       for(i=1;i<=n;i++)
       qs[i].clear();
       while(m--)
       {
          scanf("%d%d",&a,&b);
          qs[a].push_back(b);
       }
       memset(dfn,0,sizeof(dfn));
       top=ief=cnt=t=0;
       targan(1);
       for(i=2;i<=n;i++)
       {
          if(!dfn[i])
          {t=1;break;}
       }
       if(t)printf("No\n");
       else{
          for(i=2;i<=n;i++)
          if(belong[i]!=belong[1])
          {t=1;break;}
          if(t)printf("No\n");
          else printf("Yes\n");
       }
      }
      return 0;
}

