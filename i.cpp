/*
 * Author: Nfcj
 * Created Time:  2011年07月17日 星期日 16时35分06秒
 * File Name: i.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#define SZ(v) ((int)(v).size())
vector<string> data;
int dfs(int bg,int ed,int k)
{
    
    if(bg == ed)
    {   
        //if(bg-1>=0&&data[bg-1][k-1]==data[bg][k-1] || bg+1<data.size()&&data[bg+1][k-1]==data[bg][k-1])
        //    cout<<"<li>"<<endl;
        if(k!=0)
            cout<<"<li>"<<endl;
        for(int i=k;i<=data[bg].size();i++)
            cout<<data[bg][i];
        cout<<endl;
        if(k!=0)
            cout<<"</li>"<<endl;
        //if(bg-1>=0&&data[bg-1][k-1]==data[bg][k-1] || bg+1<data.size()&&data[bg+1][k-1]==data[bg][k-1])
        //    cout<<"</li>"<<endl;
        return 0;
    }
    int pos;
    /*
       if(data[bg][k]!='#'&&data[bg][k]!='*'){
          if(k!=0)
        cout<<"</li>"<<endl;
        for(int i=k;i<data[bg].size();i++)
            cout<<data[bg][i];
        cout<<endl;
          if(k!=0)
        cout<<"</li>"<<endl;
        dfs(bg+1,ed,k);
       return 0;
       
    }
  */ 
    for(pos=bg+1;pos<=ed;pos++)
        if(data[pos][k]!=data[bg][k])
            break;
    pos--;
    if(data[bg][k]=='#')cout<<"<ol>"<<endl;
    else cout<<"<ul>"<<endl;
    if(k!=0)cout<<"<li>"<<endl;
        dfs(bg,pos,k+1);
    if(k!=0)cout<<"</li>"<<endl;
    if(data[bg][k]=='#')cout<<"</ol>"<<endl;
    else cout<<"</ul>"<<endl;
    dfs(pos+1,ed,k);
}
int main() {
    ifstream cin("input.txt");
    string s;
    while(cin>>s){
        data.push_back(s);
    }
    dfs(0,data.size()-1,0);
    return 0;
}

