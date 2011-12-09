#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int map[100][100];
int visited[100];
int dis[100];
int n;
void _init(){
    memset(visited,0,sizeof(visited));
    memset(dis,INT_MAX,sizeof(dis));
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
        cin>>map[i][j];
        }
    dis[0]=0;
    for(int i=1;i<n;i++)dis[i]=map[0][i];
    visited[0]=1;
}
void _main(){
    for(int i=0;i<n;i++){
        int min=INT_MAX,k;
        for(int j=0;j<n;j++){
        if(dis[j]<min&&visited[j]==0){
        min=dis[j];
        k=j;
        }
        for(int j=0;j<n;j++){
        if(dis[k]+map[k][j]<dis[j])
            dis[j]=dis[k]+map[k][j];
            }
        }
    }
}
void _ouit(){
for(int i=0;i<n;i++)cout<<dis[i[<<' ';
cout<<endl;
}

main(){
_init();
_main();
_ouit();
}
