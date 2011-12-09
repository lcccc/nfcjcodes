#include<stdio.h> 
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int MAX=100005;
const int INF=0x0fffffff;
struct node{
       int end,len;
};
int n,p,c;
vector<node> adj[MAX];
bool in[MAX]={0};
int d[MAX],nm[MAX];
int SPFA(int i)
{
    memset(in,0,sizeof in);
    for(int k=1; k<=p; k++)d[k]=INF;
    queue<int> Q;
    Q.push(i); 
    in[i]=true;
    d[i]=0;
    while(!Q.empty())
    {
          int x=Q.front(); Q.pop();
          in[x]=false;
          for(int j=0; j<adj[x].size(); j++)
                  if(d[x]+adj[x][j].len < d[ adj[x][j].end ])
                  {
                   d[adj[x][j].end]=d[x]+adj[x][j].len;   
                   if(!in[adj[x][j].end])
                                        { 
                                        Q.push(adj[x][j].end);
                                        in[adj[x][j].end ]=true; 
                                        }                      
                  }
    }
 
    int ans=0;
 
    for(int j=1; j<=p; j++)
    {
            if(d[j]==INF)return -1; 
            else  ans+=d[j]*nm[j]; 
    }
    return ans;
}
 
 
int main()
{
    srand(time(NULL));
    while(scanf("%d",&p)!=EOF){
    for(int i=1; i<=p; i++)
            scanf("%d",&nm[i]);
 
    for(int i=1,s,t,value; i<p; i++)
    {
            scanf("%d%d%d",&s,&t,&value);
            node tm;
            tm.end = t; tm.len = value;
            adj[s].push_back(tm);
            tm.end = s; tm.len = value;
            adj[t].push_back(tm);
    }
 
    int  tt,min=INF;
 
    for(int i=1; i<=200 ; i++)
    {
            tt=SPFA(rand()%p+1); 
            if(tt<min&&tt!=-1) min=tt;
    }
    printf("%d\n",min);
    }
    return 0;
}
