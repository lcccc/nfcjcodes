/*
ID:lc757692
LANG:C++
TASK:lamps


 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 20时34分09秒
 * File Name: lamps.cpp
 */
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
int n,c,aim[7];
set<string> ans;
int init(){
    ifstream cin("lamps.in");
    cin>>n>>c;
    int wh;
    memset(aim,-1,sizeof aim);
    while(1){
        cin>>wh;
        if(wh==-1)break;
        int bwh=wh%6;
        if(bwh==0)bwh=6;
        aim[bwh]=1;
    }
    while(1){
        cin>>wh;
        if(wh==-1)break;
        int bwh=wh%6;
        if(bwh==0)bwh=6;
        aim[bwh]=0;
    }
}
int tryans(){
    for(int b1=0;b1<=1;b1++)
        for(int b2=0;b2<=1;b2++)
            for(int b3=0;b3<=1;b3++)
                for(int b4=0;b4<=1;b4++)
                {
                    if(b1+b2+b3+b4<=c){
                    int sts[7];
                    //memset(sts,1,sizeof sts);
                    for(int i=1;i<7;i++) sts[i]=1;
                    if(b1==1)
                        for(int i=1;i<7;i++)
                            sts[i]=1-sts[i];
                    if(b2==1)
                        for(int i=1;i<7;i+=2)
                            sts[i]=1-sts[i];
                    if(b3==1)
                        for(int i=2;i<7;i+=2)
                            sts[i]=1-sts[i];
                    if(b4==1)
                        for(int i=1;i<7;i+=3)
                            sts[i]=1-sts[i];
                    int b=1;
                    for(int i=1;i<7;i++)
                        if(aim[i]==-1)continue;
                        else{
                            if(sts[i]!=aim[i]){b=0;break;}
                        }
                    if(b){
                        string s;
                        for(int i=1;i<7;i++)
                            s.insert(s.end(),sts[i]+'0');
                            ans.insert(s);
                        cout<<"b1 b2 b3 b4 "<<b1<<b2<<b3<<b4<<endl;
                        cout<<"s "<<s<<endl;
                    }
                }
                }
}
int ouit(){
    ofstream cout("lamps.out");
    int bpr=0;
    set<string>::iterator lp;
    for(lp=ans.begin();lp!=ans.end();lp++)
    {
    string pans;
    pans=  *lp;
    for(int i=0;i<n;i++)
        cout<<pans[i % 6];
    cout<<endl;
    bpr=1;
    }
    if(bpr==0)cout<<"IMPOSSIBLE"<<endl;
}
int main() {
    init();
    tryans();
    ouit();
    return 0;
}

