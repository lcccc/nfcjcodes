/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/4 13:21:38
 * File Name: 842.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
//#include <mp>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int dx[] = { 1,0,-1,0};
int dy[] = { 0,1,0,-1};
int r,c,tag[501][501],posx,posy,cnt,T,entx,enty,extx,exty,dn;
bool mp[251][251][4];
void move()
{
    //cout<<"X  Y:"<<posx<<' '<<posy<<endl;
    int nextx,nexty,d;
    d = dn;
    //visit[posx][posy][d] = true;
    //out(d);
    //if( mp[posx][posy][ (d-1)%4] ) dn = (d-1)%4;
    if (mp[posx][posy][(d + 3) % 4]) dn = (d + 3) % 4;
    else if( mp[posx][posy][d]) dn = d;
    else if( mp[posx][posy][(d+1)%4]) dn = (d+1) % 4;
    else dn = (d+2) % 4;
    //visit[posx][posy][dn] = true;
    //out(visit[0][2][1]);
    //out(dn);
     posx+=dx[dn];
     posy+=dy[dn];
    tag[posx][posy] = 1;
};
bool check()
{
    //int b = 1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(tag[i][j] == 0) return false;
    return true;
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while( T --)
    {
        //mp[pair<int,int>,int] mp;
        memset(mp,0,sizeof mp);
        memset(tag,0,sizeof tag);
        dn = 0;
        scanf("%d%d%d%d",&r,&c,&enty,&exty);
        for(int i = 0;i<2*r-1;i++)
            if(i%2 == 0 )
            {
                for(int j=0;j<c-1;j++)
                {
                    int k;
                    scanf("%d",&k);
                    if( k == 0) 
                    {
                        mp[i / 2][j][1] = 1;
                        mp[i / 2][j+1][3] = 1;
                    }
                }
            }
            else
            {
                for(int j=0;j<c;j++)
                {
                    int k;
                    scanf("%d",&k);
                    if( k == 0)
                    {
                        mp[i / 2][j][0] = 1;
                        mp[i / 2 + 1][j][2] = 1;
                    }
                }
            }
        //////////////////////////////////////
       
        //out(mp[0][2][0]);
        entx = 0;
        extx = r-1;
        ///first search
        posx = entx;
        posy = enty;
        //*
        int cnt = 0;
        memset(visit,0,sizeof(visit));
        //out(extx);
        //out(exty);
        while(!( posx==extx && posy == exty)){
            move();
            cnt++;
            if (cnt > 30000) break;
        }
        //*/
        //move(posx,posy,dn);
        //second search
        //cout<<"a"<<endl;
       posx = extx;
       posy = exty;
       //memset(visit,0,sizeof(visit));
       dn = 2;
      while(!( posx==entx && posy == enty)){
         move();
         cnt++;
         if (cnt > 30000) break;
      }
      //cout<<"OK"<<endl;
      if(check()) puts("YES");
      else puts("NO");
    } 
    return 0;
}

