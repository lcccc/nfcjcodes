/*
ID:lc757692
TASK:ttwo
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月20日 星期三 09时25分48秒
 * File Name: ttwo.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
int map[12][12];
int px_jh,py_jh,px_cow,py_cow;
int x[]={-1,0,1,0};
int y[]={0,1,0,-1};
int n=10;
int main() {
  ifstream cin("ttwo.in"); 
  ofstream cout("ttwo.out");
  memset(map,0,sizeof map);
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            char ch;
            cin>>ch;
            if( ch == 'F') {
                map[i][j]=1;
                px_jh=i;
                py_jh=j;
            }
            if(ch == 'C') {
                map[i][j]=1;
                px_cow = i;
                py_cow = j;
            }
            if(ch == '.'){
                map[i][j]=1;
            }
            if(ch == '*'){
                map[i][j]=0;
            }
        }
    int step=0,dj=0,dc=0;
    while( px_jh != px_cow || py_jh != py_cow)
    {
        if(map[px_jh+x[dj]][py_jh+y[dj]]==0 //|| px_jh+x[dj]>n || px_jh+x[dj]<1 || py_jh+y[dj]>n || py_jh + y[dj] <1
                ) {++dj;dj%=4;}
        else{
           px_jh += x[dj];py_jh+=y[dj];
        }
      // if(px_cow==8&& py_cow==1) cout<<"dc "<<dc<<endl; 
        if(map[px_cow + x[dc]][py_cow+y[dc]]==0// || py_cow+x[dc]>n || py_cow + x[dc] < 1 || py_cow + y[dc] > n || py_cow + y[dc] <1
                ){ ++dc;dc%=4;}
        else{px_cow += x[dc];py_cow += y[dc];}
      //  cout<<"jh "<<px_jh<<' '<<py_jh<<endl;
     //   cout<<"cow "<<px_cow<<' '<<py_cow<<endl;
        step++;
        if(step == 1000)break;
    }
    if(step ==1000)
        cout<<0<<endl;
    else cout<<step<<endl;
    return 0;
}

