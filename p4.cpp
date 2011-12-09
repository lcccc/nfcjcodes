/*
 * Author: Nfcj
 * Created Time:  2011年07月15日 星期五 16时58分43秒
 * File Name: p4.cpp
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
struct nd{
    int p1,p2,p3,st;
    bool operator==(const nd &t) const{
        return p1==t.p1&&p2==t.p2&&p3==t.p3;
    }
   bool operator<(const nd &t1) const{ 
         return (p1 < t1.p1 ||(p1==t1.p1&&p2< t1.p2)||(p1==t1.p1&&p2==t1.p2&& p3<t1.p3));
     } 
};
int main() {
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    map< nd,int > has;
    queue<nd> Q;
    nd tm;
    tm.p1=a;
    tm.p2=b;
    tm.p3=c;
    tm.st=0;
    Q.push(tm);
    has[tm]++;
    while(Q.size()>0){
        nd tm;
        tm=Q.front();
        Q.pop();
        
        
        if(tm.p1==x&&tm.p2==y&&tm.p3==z){
            cout<<tm.st<<endl;
            break;
        }
        //1 2
       nd tm2=tm;
       int newpos;
      newpos=2*tm2.p2-tm2.p1;
        if((tm2.p3-newpos)*(tm2.p3-tm2.p1)>0){
           tm2.p1=newpos;
           if(!has[tm2]){
              tm2.st++;
              Q.push(tm2);
              has[tm2]++;
           }
        }
        //1 3
        tm2=tm;
      newpos=2*tm2.p3-tm2.p1;
        if((tm2.p2-newpos)*(tm2.p2-tm2.p1)>0){
           tm2.p1=newpos;
           if(!has[tm2]){
              tm2.st++;
              has[tm2]++;
              Q.push(tm2);
           }
        }
        //2 1
        tm2=tm;
      newpos=2*tm2.p1-tm2.p2;
        if((tm2.p3-newpos)*(tm2.p3-tm2.p2)>0){
           tm2.p2=newpos;
           if(!has[tm2]){
              tm2.st++;
              has[tm2]++;
              Q.push(tm2);
           }
        }
       
        //2 3
        tm2=tm;
      newpos=2*tm2.p3-tm2.p2;
        if((tm2.p1-newpos)*(tm2.p1-tm2.p2)>0){
           tm2.p2=newpos;
           if(!has[tm2]){
              tm2.st++;
              has[tm2]++;
              Q.push(tm2);
           }
        }
        //3 1
        tm2=tm;
      newpos=2*tm2.p3-tm2.p1;
        if((tm2.p2-newpos)*(tm2.p2-tm2.p3)>0){
           tm2.p3=newpos;
           if(!has[tm2]){
              tm2.st++;
              has[tm2]++;
              Q.push(tm2);
           }
        } 
         //3 2
        tm2=tm;
      newpos=2*tm2.p3-tm2.p2;
        if((tm2.p1-newpos)*(tm2.p1-tm2.p3)>0){
           tm2.p3=newpos;
           if(!has[tm2]){
              tm2.st++;has[tm2]++;
              Q.push(tm2);
           }
        }
    }
    return 0;
}

