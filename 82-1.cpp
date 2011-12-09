/*
 * Author: Nfcj
 * Created Time:  2011年08月02日 星期二 09时36分35秒
 * File Name: 82-1.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define SZ(v) ((int)(v).size())
vector<string> f;
int n;
int main() {
   while(scanf("%d",&n)!= EOF){
    f.clear();
   for(int i = 0;i < n;i ++)
   {
   char tm[55];
   scanf("%s",&tm);
   f.push_back(string(tm));
   }
  sort(f.begin(),f.end());
 int ans = 0;
for(int i=0;i<f.size()-1;i++)
{
  int j = 0;
  for(j=0;j<min(f[i].size(),f[i+1].size());j++)
     if(f[i][j]!=f[i+1][j]) break;
     if( j> ans) ans = j;
}
cout<<ans<<endl;
}
    return 0;
}

