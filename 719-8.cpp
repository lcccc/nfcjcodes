/*
 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 13时57分30秒
 * File Name: 719-8.cpp
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
int cs,p,n;
struct per{
    int id;
    int c;
    int hc;
    per():hc(0){}
};
vector<per> arrp;
bool mycmp1(per p1,per p2){
    if(p1.c>p2.c)return true;
    else return false;
}
/*
bool mycmp2(per p2,per p2){
    if(p1.id<p2.id)return true;
    else return false;
}
*/
bool mycmp2(per p1,per p2){
    if(p1.id<p2.id)return true;
    else return false;
}

int main() {
    scanf("%d",&cs);
    while(cs--)
    {
        arrp.clear();
        scanf("%d%d",&p,&n);
        int bsum=0;
        for(int i=0;i<n;i++)
        {
           per tmp;
           scanf("%d",&(tmp.c));
            bsum+=tmp.c;
            tmp.id=i;
            tmp.hc=0;
          arrp.push_back(tmp);
        }  
        if(bsum < p) cout<<"IMPOSSIBLE"<<endl;
        else 
        {
            sort(arrp.begin(),arrp.end(),mycmp1);
            //for(int i=0;i<arrp.size();i++)
            //    cout<<arrp[i].id<<endl;
            int shc=p;
            int cp=n,cp2=n;
            while(shc>0){
                int nowc=ceil(shc/(cp+0.0));
                cp=cp2;
                for(int i=0;i<cp;i++)
                   if(shc>0) {
                    if(arrp[i].hc + nowc <= arrp[i].c)
                    {
                        arrp[i].hc=arrp[i].hc + nowc;
                        shc -= nowc;
                        if(ceil(shc/(cp-i-1.0)) < nowc)
                        nowc=ceil( shc/(cp-i-1.0));
                    }
                    else 
                    {
                        shc -= arrp[i].c - arrp[i].hc; 
                        arrp[i].hc = arrp[i].c;
                        cp2--;
                    }
                    }
        }
        sort(arrp.begin(),arrp.end(),mycmp2);
        for(int i=0;i<n;i++)
        {
            printf("%d",arrp[i].hc);
            if(i==n-1)printf("\n");
            else printf(" ");
        }
    }
    }
    return 0;
}

