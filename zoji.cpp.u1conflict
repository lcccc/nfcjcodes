/*
 * Author: Nfcj
 * Created Time:  2011年07月24日 星期日 16时39分56秒
 * File Name: zoji.cpp
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

int main() {
    return 0;
}

        vector<short> par(len+2,1);
        for(int i=0;i<n1;i++)
        {
            scanf("%d%d",&a,&b);
            for(int j=a;j<=b;j++) par[j]=0; 
        }
        for(int i=0;i<n2;i++)
        {
            scanf("%d%d",&a,&b);
            for(int j=a;j<=b;j++)
            {
                if(par[j]==0)par[j]=1;
                else par[j]=0;
            }
          //  for(int k=0;k<len;k++)
          //      cout<<par[k]<<' ';
          //  cout<<endl;
        }
        int ans=0,nowlen=0,posval=1;
        for(int i=0;i<len;i++)
        {
            if(posval){
                if(par[i]==0){
                    nowlen=1;
                    posval=0;
                }
            }
            else {
                if(par[i]==0){
                    nowlen++;
                }
                else {
                    if(nowlen>ans)ans=nowlen;
                    posval=1;
                }
            }
        }
        if(nowlen>ans)ans=nowlen;
        cout<<ans<<endl;
    }
    return 0;
}

