/*
 * Team : FreePascal
 * Created Time:  2011年08月13日 星期六 14时33分06秒
 * File Name: 813k.cpp
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
struct point{ double x,y;int id;};
bool mult(point sp,point ep,point op)
{
    return ( sp.x - op.x )*(ep.y - op.y) >= (ep.x - op.x)*(sp.y - op.y);
}
bool operator < (const point &l,const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[],int n, int pos[])
{
    int i ,len ,k = 0,top = 1;
    sort(pnt,pnt+n);
    if( n == 0 ) return 0; pos[0] = 0;
    if( n == 1 ) return 1; pos[1] = 1;
    if( n == 2 ) return 2; pos[2] = 2;
    for(i = 2; i < n;i++){
        while(top && mult(pnt[i],pnt[pos[top]],pnt[pos[top-1]]))
            top--;
        pos[++top] = i;
       // pos[top] = i;
    }
    len  =  top;pos[++top] = n - 2;
    for( i = n-3;i >= 0;i--){
        while(top!=len && mult(pnt[i],pnt[pos[top]],pnt[pos[top-1]])) top--;
        pos[++top] = i;
        //pos[top] = i;
    }
    return top;
}
int main() {
    point pnt[40],res[40];
    int pos[40];
    int cs,p,q,n;
    cin>>cs;
    while(cs--)
    {
       cin>>p>>q>>n;
      for(int i = 0;i < n;i++)
         cin>>pnt[i].x>>pnt[i].y,
            pnt[i].id=i;
      
     int tot = graham(pnt,n,pos);
     //for(int i = 0;i < tot;i++)
         //cout<<pnt[pos[i]].id<<","<<pnt[pos[i]].x <<","<<pnt[pos[i]].y<<endl;
     int np = 0,nq = 0;
     for(int i =1;i<=tot;i++)
        if(!(fabs(pnt[pos[i%tot]].id- pnt[pos[(i-1)%tot]].id)==1 || fabs(pnt[pos[i%tot]].id - pnt[pos[(i-1)%tot]].id) == n-1)) 
        {
            np++;
            //cout<<pnt[pos[i%tot]].id<<endl;
        }
        
     nq = n-np-1;
     //cout<<n<<endl;
     //cout<<np<<' '<<nq<<endl;
     cout<<nq*q-np*p<<endl;
    } 
    return 0;
}

