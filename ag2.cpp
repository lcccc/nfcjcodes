/*
ID:lc757692
TASK:agrinet
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define INF 2147483646
using namespace std;
int n,edge,t=0,ans=0;
int p[10005],r[10005];
int u[10005],v[10005],w[10005];
int cmp(const int i, const int j){return w[i] < w[j];}
int find(int x) {return p[x] == x?x:p[x] = find(p[x]);}
int kruscal()
{
 int ans = 0;
 for(int i = 0; i < t; i++) p[i] = i;
 for(int i = 0; i < t; i++) r[i] = i;
 sort(r,r+t,cmp);//下标间接排序 
 for(int i = 0; i < t; i++)
 {
  int e = r[i];int x = find(u[e]);int y = find(v[e]);
  if(x!=y) {ans += w[e];p[x]=y;}        
 }    
 return ans;
}
int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
    {
     cin >> edge;
     //if(edge == 0) edge = INF;
     u[t] = i;v[t] = j;w[t] = edge;
     t++;
    }   
    cout << kruscal() << endl;
}
