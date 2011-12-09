/*
 * Author: FreePascal
 * Created Time:  2011/8/31 14:37:10
 * File Name: 8331d.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
vector<string> text;
string buf,cmd;
int x = 1,y = 1;
void a(){
    y = 1;
}
void e(){
    y = text[x].size();
}
void p(){
    if(x>1) x--;
    y = 1;
}
void n(){
    if(x<text.size()) x++;
    y = 1;
}
void f(){
    if( y == text[x].size() && x == text.size()) return ;
    y++;
    if(y > text[x].size() ){
        x++;
        y = 1;
    }
    //cout<<"X Y "<<x<<' '<<y<<endl;
}
void b(){
    if(y == 1 && x == 1) return;
    y--;
    if(y<1){
        x--; 
        y = 1;
    }
}
void d(){
    if(y < text[x].size()) {
        text[x].erase(y-1,1);
    }
    else
    {
        text[x] += text[x+1];
        //text.erase(x+1);
        for(int i = x+1;i < text.size()-1;i++)
            text[i] = text[i+1];
        text.resize(text.size()-1);
    }
}
void k(){
    if(y == text[x].size()) {
        d();
        buf = "\n";
    }
    else
    {
        buf = text[x].substr(y-1);
        text[x].erase(y-1,buf.size());
        y = text[x].size();
    }
}
void cy(){
    if( buf == "") return;
    else if(buf == "\n"){
        string tm;
        tm = text[x].substr(y-1);
        text[x].erase(y-1,tm.size());
        //text.insert(x);
        text.push_back("");
        for(int i = text.size()-1;i >x;i--)
            text[i] = text[i-1];
        text[x] = tm;
        x++;
        y = 1;
    }
    else
    {
        text[x].insert(y-1,buf);
        y += buf.size();
    }
}
void init(){
    string s;
    while(getline(cin,s) && s!= "END_OF_TEXT")
        text.push_back(s);
    while(cin>>s && s!="-")
        cmd+=s;
}
void work(){
    for(int i = 0;i < cmd.size();i++)
    {
        switch(cmd[i]){
            case 'a': a();break;
            case 'e': e();break;
            case 'p': p();break;
            case 'n': n();break;
            case 'f': f();break;
            case 'b': b();break;
            case 'd': d();break;
            case 'k': k();break;
            case 'y': cy();break;
        } 
}
}
void prnt(){
    for(int i = 0;i < text.size();i ++)
        cout<<text[i]<<endl;
}

int main() {
    init();
    work();
    prnt();
    return 0;
}

