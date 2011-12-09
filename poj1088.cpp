#include<iostream>
#include<algorithm>
using namespace std;
int nd[102][102],nf[102][102],r,c,max_i,max_j;
void init(){
memset(nd,0,sizeof nd);
memset(nf,0,sizeof nf);

int max=0;
cin>>r>>c;
for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++){
    cin>>nd[i][j];
    if(nd[i][j]>max){
    max_i=i;
    max_j=j;
    max=nd[i][j];
    }
    nf[i][j]=-1;
    }
}
int dp(int x,int y){
    if(nf[x][y]!=-1) return nf[x][y];
    nf[x][y]=0;
   //cout<<"x "<<x<<"y "<<y<<endl;
   // cout<<nf[x][y]<<' '<<nd[x][y]<<endl;
    //system("pause");
   // dp(x-1,y);
   // dp(x+1,y);
   // dp(x,y-1);
   // dp(x,y+1);
    int max=0;
    if(nd[x][y]>nd[x-1][y]&&dp(x-1,y)>max)max=nf[x-1][y];
    if(nd[x][y]>nd[x+1][y]&&dp(x+1,y)>max)max=nf[x+1][y];
    if(nd[x][y]>nd[x][y-1]&&dp(x,y-1)>max)max=nf[x][y-1];
    if(nd[x][y]>nd[x][y+1]&&dp(x,y+1)>max)max=nf[x][y+1];
    nf[x][y]=max+1;
    return nf[x][y];
}
int main(){
init();
for(int i=1;i<=r;i++)
for(int j=1;j<=c;j++)
dp(i,j);
int max=0;
for(int i=1;i<=r;i++)
for(int j=1;j<=c;j++)
if(nf[i][j]>max)max=nf[i][j];
cout<<max<<endl;
}
