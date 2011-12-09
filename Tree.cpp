/*
 * Author: Nfcj
 * Created Time:  2011年07月24日 星期日 12时38分10秒
 * File Name: Tree.cpp
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
int n,m,val[10003];
vector<int> vttm;
int main() {
    while((scanf("%d",&n))==1){
        memset(val,0,sizeof val);
        vector<vector<int> > f(n+2);
        scanf("%d",&val[0]);
        for(int i=1;i<n;i++)
        {
            int pre,v;
            scanf("%d%d",&pre,&v);
            val[i]=v;
            f[pre].push_back(i);
        }
        scanf("%d",&m);
        for(int cs=0;cs<m;cs++)
        {
            int nd;
            scanf("%d",&nd);
            vttm.clear();
            queue<int> qi;
            qi.push(nd);
            while(!qi.empty()){
                int tm=qi.front();
                qi.pop();
                vttm.push_back(val[tm]);
                for(int i=0;i<f[tm].size();i++)
                    qi.push(f[tm][i]);
            }
            if(vttm.size()<3)printf("-1\n");
            else {
                sort(vttm.begin(),vttm.end());
                reverse(vttm.begin(),vttm.end());
                printf("%d %d %d\n",vttm[0],vttm[1],vttm[2]);
            }
        }
    }
    return 0;
}

