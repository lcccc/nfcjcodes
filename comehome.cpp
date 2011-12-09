/*
ID:lc757692
LANG:C++
TASK:comehome

 * Author: Nfcj
 * Created Time:  2011年07月20日 星期三 18时13分54秒
 * File Name: comehome.cpp
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
int INF = 100000;
int main() {
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int p;
    int f['z']['z'];
    for(int i = 'A';i <= 'z';i++)
        for(int j = 'A';j <= 'z';j++)
        f[i][j] = INF;
    scanf("%d\n",&p);
    for(int i=0;i<p;i++)
    {
        int val;
        char ca,cb;
        //getchar();
        scanf("%c %c %d\n",&ca,&cb,&val);
      //  cout<<ca<<' '<<cb<<' '<<val<<endl;
        if(val < f[ca][cb]){
            f[ca][cb]=val;
            f[cb][ca]=val;
    }
    }
    for(int k='A';k<='z';k++)
        for(int i='A';i<='z';i++)
            for(int j='A';j<='z';j++)
             //  cout<<k<<i<<j<<endl;
            {
               //     if(i !=j && j!=k && k!=i )
                    if(f[i][k]+f[k][j]<f[i][j])
                    {
                        f[i][j]=f[i][k]+f[k][j];
                    //    cout<<char(i)<<' '<<char(j)<<' '<<f[i][j]<<endl;
                    }
            }    
    int nmin=INF; 
    char cmax='A';
    for(char c='A';c<'Z';c++)
    {
        //cout<<f[c]['Z']<<endl;
        if(f[c]['Z']<nmin){
            nmin=f[c]['Z'];
            cmax=c;
        }
    }
    printf("%c %d\n",cmax,nmin);
    
    return 0;
}

