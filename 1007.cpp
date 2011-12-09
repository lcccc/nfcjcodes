/*
 * Team : FreePascal
 * Created Time:  2011年08月10日 星期三 14时35分21秒
 * File Name: 1007.cpp
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
int t,n,m;
vector< vector<int> > f1(10001),f2(10001);
int main() {
    scanf("%d",&t);
    int cs = 1;
    while(t--)
        {
            ////////////
            cout<<"Case #"<<cs++<<": ";
            f1.clear();
            f2.clear();
            int n1,n2;
            scanf("%d%d",&n1,&m);
            //memset(f1,0,sizeof f1);
//            vector<int> tm;
 //           fill(f1.begin(),f1.end(),tm);
           // memset(f2,0,sizeof 0);
            for(int i = 0;i < m;i++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                f1[a].push_back(b);
                f1[b].push_back(a);
            }
            
            scanf("%d%d",&n2,&m);
            //memset(f2,0,sizeof f2);
  //          fill(f2.begin(),f2.end(),tm);
            for(int i = 0;i < m;i++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                f2[a].push_back(b);
                f2[b].push_back(a);
            }
            if(n1 != n2) {
                printf("NO\n");
                continue;
            }
            int b = 1;
            for(int i = 1;i<= n1;i++)
            {
               if(!( f1[i][0] == f2[i][0] && f1[i][1] == f2[i][1]  
                || f1[i][0] == f2[i][1] && f1[i][1] == f2[i][0]))
               { 
                   b = 0;
                   //cout<<i<<endl;
                   //cout<<f1[i][0]<<' '<<f1[i][1]<<endl;
                   //cout<<f2[i][0]<<' '<<f2[i][1]<<endl;
                   break;
               }
            }
            if(b) printf("YES\n");
            else printf("NO\n");
        }
                   
    return 0;
}

