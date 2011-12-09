#include<iostream>
#define REP(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=100+10;
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int B[maxn][maxn]={0};
bool pass[maxn][maxn]={0};
int Pass(int x,int y)
{
int ans=B[x][y];
if(pass[x][y]) ans/=2;
pass[x][y]=true;
return ans;
}
int value(int x,int y,int d)
{
int ans=0;
switch(d)
{
case 0:ans=Pass(x-1,y-1)+Pass(x-1,y);break;
case 1:ans=Pass(x-1,y)+Pass(x,y);break;
case 2:ans=Pass(x,y-1)+Pass(x,y);break;
case 3:ans=Pass(x-1,y-1)+Pass(x,y-1);break;
}
return ans;
}
int main()
{
int n,m;
cin>>n>>m;
REP(i,1,n)
REP(j,1,m)
{
char t;cin>>t;
B[i][j]=t-'0';
}
int d=1,x=1,y=1,ans=0;
char t;
while(cin>>t)
{
switch(t)
{
case 'M':ans+=value(x,y,d);
x+=di[d],y+=dj[d];break;
case 'L':d--;if(d<0) d=3;break;
case 'R' :d++;if(d>3) d=0;
}
}
cout<<ans<<endl;
}

