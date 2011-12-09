/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 09时23分45秒
 * File Name: sum7171.cpp
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
int map[6][6],f[6][6];
int ans=10000;
int search(){
    int cnt=0;
    int b_map[6][6];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            b_map[i][j]=map[i][j];
    for(int j=1;j<=4;j++)
    {
        if(f[1][j]==1){
            cnt++;
            b_map[1][j-1]=(b_map[1][j-1]+1)% 2;
            b_map[1][j]=(b_map[1][j]+1)% 2;
            b_map[1][j+1]=(b_map[1][j+1]+1)% 2;
        }
    }
    for(int i=2;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        if(b_map[i-1][j]==0){f[i][j]=1;cnt++;}
        else f[i][j]=0;
        for(int j=1;j<=4;j++)
            if(f[i][j]==1){
            b_map[i-1][j]=(b_map[i-1][j]+1)% 2;
            b_map[i+1][j]=(b_map[i+1][j]+1)% 2;
            b_map[i][j-1]=(b_map[i][j-1]+1)% 2;
            b_map[i][j]  =(b_map[i][j]+1)% 2;
            b_map[i][j+1]=(b_map[i][j+1]+1)% 2; 
            }
    }
    cout<<cnt<<endl;
    if(cnt<ans)ans=cnt;
}   
int main() {
    int flip[5][5];
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='b')map[i][j]=0;
            else map[i][j]=1;
        }
    int f[5][5];
    memset(f,0,sizeof f);
    for(f[1][1]=0;f[1][1]<=1;f[1][1]++)
        for(f[1][2]=0;f[1][2]<=1;f[1][2]++)
            for(f[1][3]=0;f[1][3]<=1;f[1][3]++)
                for(f[1][4]=0;f[1][4]<=1;f[1][4]++)
                
                    search();
    cout<<ans<<endl;    
    return 0;
}

