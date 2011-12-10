/*
ID:lc757692
TASK:stall4
LANG:C++
 * Team : FreePascal
 * Created Time:  2011年08月19日 星期五 19时17分12秒
 * File Name: stall4.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())
int m,n,lin[205],use[205],map[205][205];
bool find(int x);
int maxmatch();
int main() {
    ifstream cin("stall4.in");
    ofstream cout("stall4.out");
    memset(map,0,sizeof 0);
    cin>>n>>m;
    for(int i = 0;i < n;i++)
    {
        int k,v;
        cin>>k;
        for( int j = 0;j < k;j++)
        {
            cin>>v;
            map[i][v] = 1;
        }
    }
    cout<<maxmatch()<<endl;
    //for(int i = 0;i < n;i++)
        //cout<<lin[i]<<' '<<i<<endl;
    
    
    return 0;
}
bool find(int x)
{
        for(int i = 1;i <= m;i++)
            if( map[x][i] && use[i]==0 )
            {
                use[i] = 1;
                if( lin[i] == -1 || find(lin[i]))
                {
                    //cout<<i<<endl;
                    lin[i] = x;
                    return true;
                }
            }
        return false;
}
int maxmatch(){
    int u,ret = 0;
    memset(lin,-1,sizeof lin);
    for(u = 0 ;u < n;u++){
        //if(lin[u] ==-1){
            memset(use,0,sizeof use);
            if(find(u)) 
                ret++;
        }
    return ret;
}
