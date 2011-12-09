/*
 * Author: Nfcj
 * Created Time:  2011年07月15日 星期五 13时03分56秒
 * File Name: milk3.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define SZ(v) ((int)(v).size())
 struct nd{
        int m[4];
    };
int m[4],M[4];
int per[21];
int init(){
    memset(per,0,sizeof(per));
    cin>>M[1]>>M[2]>>M[3];
    m[3]=M[3];
    m[1]=m[2]=0;
    per[m[3]]=1;
}
int dao(nd nd,int x,int y){
    if(nd.m[x]==0 || nd.m[y]==M[y])return 0;
    else {
        if( nd.m[x]+nd.m[y]<=M[y])
        {
            nd.m[y]+=m[x];
            nd.m[x]=0;
        }
        else
        {
            nd.m[x]-=M[y]-nd.m[y];
            nd.m[y]=M[y];
        }
    }
    return 1;
}
int bfs(){
    map<nd,int> has;
    queue<nd> que;
    nd tm;
    for(int i=0;i<4;i++)tm.m[i]=m[i];
    que.push(tm);
    has[tm]=1;
    while(que.size()!=0){
        nd tm,tm2;
        tm=que.front();
        que.pop();
        tm2=tm;
        //for(int i = 1;i < 4;i ++)m[i]=tm.m[i];
            if(dao(tm2,1,2))
            {
                if(has[tm2]==0){
                    que.push(tm2);
                    per[tm2.m[3]]=1;
                    has[tm2]=1;
                }
            }
            if(dao(tm2,1,3))
            {
                if(has[tm2]==0){
                    que.push(tm2);
                    per[tm2.m[3]]=1;
                    has[tm2]=1;
                }
            }
            if(dao(tm2,2,1))
            {
                if(has[tm2]==0){
                    que.push(tm2);
                    per[tm2.m[3]]=1;
                    has[tm2]=1;
                }
            }
            if(dao(tm2,2,3))
            {
                if(has[tm2]==0){
                    que.push(tm2);
                    per[tm2.m[3]]=1;
                    has[tm2]=1;
                }
            }
            if(dao(tm2,3,1))
            {
                if(has[tm2]==0){
                    que.push(tm2);
                    per[tm2.m[3]]=1;
                    has[tm2]=1;
                }
            }
            if(dao(tm2,3,2))
            {
                if(has[tm2]==0){
                    que.push(tm2);
                    per[tm2.m[3]]=1;
                    has[tm2]=1;
                }
            }
    }
}
int ouit(){
    for(int i=0;i<=20;i++)
        if(per[i])cout<<i<<' ';
}
            
int main() {
    init();
    bfs();
    ouit();
    return 0;
}

