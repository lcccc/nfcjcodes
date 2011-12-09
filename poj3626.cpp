/*
 * Author: FreePascal
 * Created Time:  2011/11/2 14:35:56
 * File Name: poj3626.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int isPud[1012][1012];
int isVis[1012][1012];
bool Can(int x,int y)
{
    return (isVis[x+500][y+500]== 0) && (x < 501) && (x > -501) && (y < 501) && (y > -501) && (!isPud[x + 500][y + 500]);
}
int X,Y,N;
struct status{
    int x,y,step;
};
int main() {
    memset(isPud,0,sizeof isPud);
    memset(isVis,0,sizeof isVis);
    scanf("%d%d%d",&X,&Y,&N);
    //out(X),out(Y),out(N);
    while(N--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        //out(x),out(y);
        isPud[x + 500][y + 500] = 1;
    }
    queue<status> Q;
    status tm ;
    tm.x = 0;tm.y = 0;
    isVis[tm.x + 500][tm.y + 500] = 1;
    tm.step = 0;
    Q.push(tm);
    while(Q.size() > 0)
    {
        status tm;
        tm = Q.front();
        Q.pop();
        //out(Q.size());
        //cout<<tm.x << ' '<< tm.y <<endl; 
        //getchar();
        if(tm.x == X && tm.y == Y)
        {
            cout<<tm.step <<endl;
            return 0;
        }
        status ext;
        for(int i = 0;i < 4;i ++)
        {
            ext.x = tm.x + dx[i];
            ext.y = tm.y + dy[i];
            ext.step = tm.step + 1;
            
            if(Can(ext.x,ext.y)){
                Q.push(ext);
                isVis[ext.x + 500][ext.y + 500] = 1;
        }
        }
    }
    return 0;
}

