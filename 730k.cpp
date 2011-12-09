/*
 * Author: Nfcj
 * Created Time:  2011年07月30日 星期六 17时16分00秒
 * File Name: 730k.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
map<pair<int,int>,int> mp;
int v[100005];
int n,capt;
int main() {
    while(1){
        int j,c;
        scanf("%d",&n);
        if (n == 0) break;
        capt = 1;
        memset(v,0,sizeof v);
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&j,&c);
            map[pair<int,int>(i,j)] = 1;
            map[pair<int,int>(j,i)] = 1;
            if( c = 1 ) capt = i;
           queue< 
            
    return 0;
}

