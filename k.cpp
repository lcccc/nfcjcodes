/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 13时17分00秒
 * File Name: k.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())
int visited[102][102],n,m,b[102][102];
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
string cmd;
int ans;
void init(){
    cin>>n>>m;
    memset(visited,0,sizeof visited);
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            b[i][j]=int(c-'0');
        }
    cin>>cmd;
}
void _main(){
    int len=cmd.size();
    int px,py,dir;
    px=0;py=0;
    dir=0;
    ans=0;
    for(int i=0;i<len;i++)
    {
        switch(cmd[i]){
            case 'L': dir--;dir%=4;break;
            case 'R': dir++;dir%=4;break;
            case 'M': 
                      px+=x[dir];
                      py+=y[dir];
                      if(dir==0){
                          if(!visited[px][py]){
                              ans+= b[px][py];
                              visited[px][py]=1;
                          }
                          else {
                              ans+=b[px][py]/2;
                          }
                          if(!visited[px+1][py]){
                              ans+=b[px+1][py];
                              visited[px+1][py]=1;
                          }
                          else {
                              ans+=b[px+1][py]/2;
                          }
                      }
                      if(dir==2){
                          if(!visited[px][py+1]){
                              ans+= b[px][py+1];
                              visited[px][py+1]=1;
                          }
                          else {
                              ans+=b[px][py+1]/2;
                          }
                          if(!visited[px+1][py+1]){
                              ans+=b[px+1][py+1];
                              visited[px+1][py+1]=1;
                          }
                          else {
                              ans+=b[px+1][py+1]/2;
                          }
                      }
                      if(dir==1){
                          if(!visited[px][py]){
                              ans+=b[px][py];
                              visited[px][py]=1;
                          }
                          else ans+=b[px][py]/2;
                          if(!visited[px][py+1]){
                              ans+=b[px][py+1];
                              visited[px][py+1]=1;
                          }
                          else {
                              ans+=b[px][py+1]/2;
                          }
                      }
                      if(dir==3){
                          if(!visited[px+1][py]){
                              ans+=b[px+1][py];
                              visited[px+1][py]=1;
                          }
                          else ans+=b[px+1][py]/2;
                          if(!visited[px+1][py+1]){
                              ans+=b[px+1][py+1];
                              visited[px+1][py+1]=1;
                          }
                          else {
                              ans+=b[px+1][py+1]/2;
                          }
                      }
                      break;
        }
    }
}
int ouit(){
    cout<<ans<<endl;
    return 0;
}
int main() {
    init();
    _main();
    ouit();
    return 0;
}

