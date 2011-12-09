#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())
int r,c,map[101][101];
int main() {
    while (scanf("%d%d",&r ,&c ) !=EOF)
    {
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&map[i][j]);
        int m;
        scanf("%d",&m);
        for(int cs=0;cs<m;cs++)
        {
            printf("Case %d\n",cs+1);
            int opty,px1,py1,px2,py2,k;
            scanf("%d",&opty);
            if( opty == 0 )
            {
                scanf("%d%d%d%d%d",&px1,&py1,&px2,&py2,&k);
                //updata
                while(py1<=py2)
                {
                    //py1++;
                    if(px1>r){ px1=1;py1++;}
                    if(px1 == px2 &&
                       py1 ==py2)
                    {
                       map[px1][py1]+=k;
                      break;
                    } 
                    map[px1][py1]+=k; 
                    px1++;
                }
            }
            if(opty == 1)
            {
                 scanf("%d%d%d%d%d",&px1,&py1,&px2,&py2,&k);
                //updata
                while(px1<=px2)
                {
                    //py1++;
                    if(py1>c){ py1=1;px1++;}
                    if(px1 == px2 &&
                       py1 == py2)
                    {
                       map[px1][py1]+=k;
                      break;
                    } 
                    map[px1][py1]+=k; 
                    py1++;
                }
            }   
            if(opty == 2)
            {
                scanf("%d%d", &px1, &py1);
                printf("%d\n",map[px1][py1]);
            }
        }
    }
    return 0;
}

