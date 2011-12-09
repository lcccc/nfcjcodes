/*
 * Author: Nfcj
 * Created Time:  2011年07月20日 星期三 14时52分01秒
 * File Name: 720i.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define SZ(v) ((int)(v).size())
int n,f[55][55];
int stringtonum(string s){
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans*=10;
        ans+=  s[i]-'0';
    }
    return ans;
}
void _input(){

     for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) 
        {
            string s;
            cin>>s;
            if(s == "*")f[i][j] = -1;
            else f[i][j]= stringtonum(s);
         //   pz[f[i][j]]=1;
        }
   
}
void _main(){
    //1
   int b=1;
  for(int b=1;b<=100;b++){ 
      b=0;
    for(int i=n;i>1;i--)
        for(int j=1;j<i;j++)
            if( f[i][j] != -1 && f[i][j+1] != -1  && f[i][j]!=-1)
            {
                b=1;
                f[i-1][j]=f[i][j]+f[i][j+1];
               // pz[f[i-1][j]]=1;
            }
    //
    for(int i=1;i<n;i++)
        for(int j=1;j<=i;j++)
        {
            if(f[i][j]!=-1)
            {
                if(f[i+1][j]==-1 && f[i+1][j+1]!=-1
                        && f[i][j]-f[i+1][j+1]<f[i][j]
                        && f[i][j]-f[i+1][j+1]>=0)
                { f[i+1][j]=f[i][j]-f[i+1][j+1];b=1;}
                if(f[i+1][j]!=-1 && f[i+1][j+1]==-1 &&
                        f[i][j]-f[i+1][j]<f[i][j]
                        && f[i][j]-f[i+1][j]>=0)
                {   f[i+1][j+1]=f[i][j]-f[i+1][j];b=1;}
            }
        }
}
}
void _output(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            if(f[i][j]==-1)cout<<"* ";
            else cout<<f[i][j]<<' ';
        cout<<endl;
    }
}
int main() {
      while(cin>>n){
      if(n==0)break;
     _input();
     _main();
     _output();
      }
    return 0;
}

