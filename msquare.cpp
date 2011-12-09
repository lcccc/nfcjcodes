/*
ID:lc757692
TASK:msquare
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月26日 星期二 10时37分31秒
 * File Name: msquare.cpp
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
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
map<string,int> hh;
ofstream fout("msquare.out");
struct nd {
    int pre;
    char op;
    int ct;
    string sts;
};
 nd que[100000];
 void print(int x)
{
    if(que[x].pre!= -1){
        print(que[x].pre);
        fout<<que[x].op;
    }
}
int main() {
    ifstream cin("msquare.in");
    string bg,ed;
    bg="12345678";
    reverse(bg.begin()+4,bg.end());
    for(int i = 0;i < 8;i++)
    {
       int tm;
      cin>>tm;
      ed=ed + char(tm+'0');
    } 
    reverse(ed.begin()+4,ed.end());
  int ft,lt;
    ft=0;lt=1;
    que[0].pre = -1;
    que[0].op ='\0';
    que[0].ct = 0;
    que[0].sts = bg;
   while(ft<lt)
   { 
       nd tm;
       tm = que[ft++];
       if(tm.sts == ed) {
           //print();
           fout<<tm.ct<<endl;
           print(ft-1); 
           fout<<endl;
           break;
       }
       nd tm2;
       //A
       tm2.pre = ft - 1;
       tm2.op = 'A';
       tm2.ct = tm.ct+1;
       string s(tm.sts);
       for(int i=0;i<4;i++)
           s[i]=tm.sts[i+4];
       for(int i=4;i<8;i++)
           s[i]=tm.sts[i-4];
       tm2.sts = s;
       if( !hh[s]){
       que[lt++] = tm2;
       hh[s] = 1;
       }
       
       //B
       
         tm2.pre = ft - 1;
       tm2.op = 'B';
       tm2.ct = tm.ct+1;
        s = tm.sts;
       //swap(s[0],s[3]);
       //swap(s[4],s[7]); 
        char ch2;
        ch2 = s[3];s[3] = s[2];s[2] = s[1]; s[1] = s[0];s[0] = ch2;
        ch2 = s[7];s[7] = s[6];s[6] = s[5]; s[5] = s[4];s[4] = ch2;
       tm2.sts = s;
       if( !hh[s]){
       que[lt++] = tm2;
       hh[s] = 1;
       }
      //C
      
       tm2.pre = ft - 1;
       tm2.op = 'C';
       tm2.ct = tm.ct+1;
       s= tm.sts;
       char ch3;
       ch3 = s[1];
       s[1] = s[5];
       s[5] = s[6];
       s[6] = s[2];
       s[2] = ch3;
       tm2.sts = s;
       if( !hh[s]){
       que[lt++] = tm2;
       hh[s] = 1;
       } 
   }
    return 0;
}

