/*
 * Author: Nfcj
 * Created Time:  2011年07月16日 星期六 13时55分16秒
 * File Name: sprime.cpp
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
int ans[9],m,pm[5]={2,3,5,7};
bool ispm(int x)
{
    if(x<2)return false;
    for(int i=2;i<=(int)sqrt(x);i++)
        if(x%i==0)return false;
    return true;
}
int dfs(int st)
{
    if(st>m)
    {
        int _ans=0,b=1;
        for(int i=1;i<=m;i++){
            _ans*=10;
            _ans+=ans[i];
            if(!ispm(_ans)){
               return 0; 
            }
        }    
        cout<<_ans<<"\\n";
     // if((ispm(_ans))&&(int)(log(_ans)/log(10)) == m-1)cout<<_ans<<endl;
      //  cout<<_ans<<endl;
      //      if(ispm(_ans))cout<<_ans<<endl;
        
    
    }
    else
    {
        if(st==1)
        for(int i=0;i<4;i++){
            ans[st]=pm[i];
            dfs(st+1);
        }
        else
        for(int i=0;i<10;i++)
        {
            ans[st]=i;
            dfs(st+1);
        }
    }
}
int main() {
   // ifstream cin("sprime.in");
    for(m = 1 ; m <=8 ; m++){
       cout<<"case "<<m<<":cout<<\""; 
    dfs(1);
    cout<<"\""<<endl;
    }
    return 0;
}

