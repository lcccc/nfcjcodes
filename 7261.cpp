/*
 * Author: Nfcj
 * Created Time:  2011年07月26日 星期二 13时23分07秒
 * File Name: 7261.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;
#define SZ(v) ((int)(v).size())
int n,m;
map<pair<int,int>,int> mp;
int val[5000+1],tag[5000+1],p[5000+1];
int main() {
    while(scanf("%d%d",&n,&m)==2){
           for(int i = 1;i <= n;i++)
           {
              scanf("%d",&val[i]);
              p[i] = val[i];
              tag[i] = 0;
           }
           for(int i = 1;i <= n;i++)
               val[i]*=-1;
          for(int i = 0;i < m;i++)
          {
             int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
           mp[pair<int,int>(a,b)]=c;
           val[a]+=c;
           val[b]+=c;
          }
         int ct =1; 
    while(1&&ct<10){
        int b=1,k=1;
        for(int i=1;i <= n;i++)
            if(val[i] < 0) {
                b = 0;
                k = i;
                break;
            }
        if(b == 0 )
        {
            val[k] = 0;
            tag[k] = 1;
            for(int i = 1; i <= n;i++)
            {
                if(i != k && !tag[i] )
                {
                    if( mp[pair<int,int>(i,k)]){ val[i] -=mp[pair<int,int>(i,k)];continue;} 
                    if( mp[pair<int,int>(k,i)]){ val[i] -=mp[pair<int,int>(k,i)];}
                 }
                }
            }  
            
            
        
        else break;
        ct++;
    }
    int sum = 0;
    for(int i = 1;i <= n;i++)
            if(!tag[i])
              {
                sum-= p[i];
              }
    map<pair<int,int>,int>::iterator lp;
    for(lp =mp.begin();lp!=mp.end();lp++)
        if( !tag[(*lp).first.first] && !tag[(*lp).first.second])
            sum+=(*lp).second;    
    printf("%d\n",sum);
    }
    return 0;
}

