/*
 * Author: Nfcj
 * Created Time:  2011年07月16日 星期六 12时07分39秒
 * File Name: bupt199.cpp
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
int Q,n,pd,pn,t,t1[1001],t2[1001];
/*
int maxP(){
    int maxans=0;
    int sp;
    for(sp=1;sp<t;sp++)
    {
        int tans=0;
        while(sp<t1+t2){
            if(sp<=t1)
                tans+=pd;
            else
                tans+=pn;
            sp+=t;
        }
    if(tans>maxans)maxans=tans;
    }
    return maxans;
    }
    int maxans=0;
    int sp;
    for(sp=1;sp<=t;sp++)
    {
        int x1=(t1-sp)/t;
        int x2=(t1+t2-sp-1)/t-x1;
        if(sp<=t1)x1++;
        if(sp>t1&&sp<t1+t2)x2++;
        if(x1*pd+x2*pn>maxans)maxans=x1*pd+x2*pn;
    }
    */
int main() {
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d%d",&n,&t,&pd,&pn);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&t1[i],&t2[i]);
        }
        int bans=0;
        for(int sp=1;sp<=t;sp++)
        {
            bans=0;
            int bsp=sp;
            for(int i=0;i<n;i++){
                int x1=(t1[i]-bsp)/t;
                int x2=(t1[i]+t2[i]-bsp-1)/t-x1;
                if(sp<=t1[i])x1++;
                if(sp>t1[i]&&sp<t1[i]+t2[i])x2++;
                //if(x1*pd+x2*pn>maxans)maxans=x1*pd+x2*pn;
                bans+=x1*pd+x2*pn;
                bsp=t- (t1[i]+t2[i]-sp)%t;
            }
            if(bans>ans)ans=bans;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}

