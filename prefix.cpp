/*
ID:lc757692
LANG:C++
TASK:prefix

 * Author: Nfcj
 * Created Time:  2011年07月19日 星期二 09时20分16秒
 * File Name: prefix.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
map<string,int> dict;
int f[200001],maxdiclen=0;
string ss;
int _input(){
    ifstream cin("prefix.in");
    string word;
    while(cin>>word)
    {
        if(word==".")break;
        dict[word]=1;
        if(word.size()>maxdiclen)maxdiclen=word.size();
    }
    while(cin>>word){
        ss+=word;
    }
   // cout<<ss.size()<<endl;
    return 0;
}
int  _main(){
    memset(f,0,sizeof f);
    f[0]=1; 
    for(int i=1;i<=ss.size();i++)
        for(int j=1;j<=maxdiclen&&i-j>=0;j++)
        {
            if(f[i-j]){
            string stm;
            stm=ss.substr(i-j,j);
                if(dict[stm]){
                    f[i]=1;
                    break;
                }
            }
        }
}
int _output(){
    ofstream cout("prefix.out");
    int bpr=0;
    for(int i=ss.size();i>=0;i--)
        if(f[i]){
            cout<<i<<endl;
            break;
        }
}
int main() {
    _input();
    _main();
    _output();
    
    return 0;
}

