/*
 * Author: Nfcj
 * Created Time:  2011年07月15日 星期五 11时06分13秒
 * File Name: sourcecode0715.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
int m,n,s[100001],dis[100001],map[100001];
int init(){
    int a,b,l;
    memset(s,0,sizeof s);
    memset(map,-1,sizeof map);
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>l;
        map[a][b]=l;
    }
    s[1]=1;
    for(int i=1;i<=m;i++)dis[i]=map[1][i];
}
int spfa(){
    int count=0;
    queue<int> list;
    list.push(1);
    while(list.size()>0&&count<=1000000){
        int u;
        u=list.top();
        list.pop();
        for(int i=1;i<=m;i++){
            if(map[u][i]!=-1&&dis[u]+map[u][i]<dis[i]){
                list.push(i);
                dis[i]=dis[u]+map[u][i];
            }
        }
        count++;
    }
}
int ouit(){
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<' ';
    cout<<endl;
}
int main() {
    init();
    spfa();
    ouit();
    return 0;
}

