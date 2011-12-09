/*
 * Author: Nfcj
 * Created Time:  2011年07月21日 星期四 12时48分20秒
 * File Name: 7218.cpp
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
struct nd{
    int a,b;
    long long c;
    char op;
};
vector<nd> f;
int cs,n;
bool mycmp(nd n1,nd n2){
   
    if(n1.c>n2.c)return true;
    if(n2.c==n1.c)return n1.op>n2.op;
    return false;
}
int main() {
  // cin>>cs;
    scanf("%d",&cs);
  for(int i=0;i<cs;i++)
  {
     f.clear();
    scanf("%d",&n);
   for(int j=0;j<n;j++)
      {
         nd tm;
         scanf("%d%d",&tm.a,&tm.b);
       tm.c=(long long)tm.a+(long long)tm.b;
       if(tm.a==tm.b)tm.op='=';
       if(tm.a < tm.b)tm.op='<';
       if(tm.a > tm.b)tm.op='>';
       f.push_back(tm);
      }
    sort(f.begin(),f.end(),mycmp); 
    for(int j=0;j<f.size();j++)
    
       // cout<<f[i].a<<f[i].b<<f[i].c<<endl;
       // cout<<f[i].a<<'+'<<f[i].b<<"=[";
        //if(f[i].a>f[i].b)cout<<'>';
       // if(f[i].a==f[i].b)cout<<'=';
       // if(f[i].a<f[i].b)cout<<'<';
       // cout<<f[i].c<<']'<<endl;
        printf("%d+%d=[%c%I64d]\n",f[j].a,f[j].b,f[j].op,f[j].c);
    
   // if(i!=cs-1)
        printf("\n");
  }
    return 0;
}

