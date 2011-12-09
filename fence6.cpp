/*
TASK:fence6
ID:lc757692
LANG:C++
*/
 
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
 
int n;
int len[101];
bool linked[101][101];
bool bad[101][101][101];
int map[101][101];
int l[101][101];
int list[101];
int res=99999999;
 
int main()
{
ifstream cin("fence6.in");
ofstream cout("fence6.out");
 
memset(linked,0,sizeof(linked));
memset(bad,0,sizeof(bad));
memset(map,0xe,sizeof(map));
memset(l,0xe,sizeof(l));
 
cin>>n;
for(int i=1;i<=n;i++)
 {
 int t1,t2,t3,t4;
 cin>>t1>>t2>>t3>>t4;
 len[t1]=t2;
 list[0]=0;
 for(int j=1;j<=t3;j++)
  {
  cin>>list[++list[0]];
  linked[t1][list[list[0]]]=1;
  }
 for(int j=1;j<=list[0];j++)
  for(int k=1;k<=list[0];k++)
   bad[t1][list[j]][list[k]]=1;
   list[0]=0;
 for(int j=1;j<=t4;j++)
  {
  cin>>list[++list[0]];
  linked[t1][list[list[0]]]=1;
  }
 for(int j=1;j<=list[0];j++)
  for(int k=1;k<=list[0];k++)
   bad[t1][list[j]][list[k]]=1;
}
for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 if(linked[i][j])
 {
 l[i][j]=len[i]+len[j];
 map[i][j]=len[i]+len[j];
 }
 for(int k=1;k<=n;k++)
 {
 for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 {
 if(!bad[k][i][j])
 res=min(res,l[i][j]+map[j][k]+map[k][i]);
 }
 for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 if(l[i][j] > l[j][k]+l[k][i])
 l[i][j] = l[j][k]+l[k][i];
 }
cout<<res/2<<endl;
 
return 0;
}

