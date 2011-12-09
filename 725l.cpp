/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 13时01分32秒
 * File Name: 725l.cpp
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
struct line{
    int x1,y1,x2,y2;
    line(){}
    bool ok(line l2){
        if(  x1==l2.x1 && y1==l2.y1
            || x2==l2.x2 && y2==l2.y2
            || x1==l2.x2 && y1==l2.y2
            || x2==l2.x1 && y2==l2.y1)
        {
            if( (x2-x1)*(l2.x2-l2.x1)+(y2-y1)*(l2.y2-l2.y1)==0) return true;
        }
    return false;
    }
} lines[5002];
int n;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a1,a2,a3,a4;
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(lines[i].ok(lines[j]))
                ans++;
    printf("%d\n",ans);
    return 0;
}

