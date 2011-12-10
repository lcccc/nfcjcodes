/*
ID:lc757692 
PROB: zerosum
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int n,m;
void dfs(int step,int sum,int num,string s){
  string s1=s;
  if(step==n){if(sum+num==0)fout<<s<<endl;return;}
  if(num>0)dfs(step+1,sum,num*10+step+1,s+" "+char(step+1+48));
  else dfs(step+1,sum,num*10-step-1,s+" "+char(step+1+48));
  dfs(step+1,sum+num,step+1,s+"+"+char(step+1+48));
  dfs(step+1,sum+num,-1*step-1,s+"-"+char(step+1+48));
}
void solve(){
  fin>>n;
  dfs(1,0,1,"1");
}
int main(){
  solve();
  return(0);
}
