/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/1 19:56:34
 * File Name: 81-3.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int main() {
    string s,t;
    cin>>s;
    //)
    //{
        //s.insert(s.find("at"));
        //s.erase(s.find("at"),2);
    //}
    //while(s.find(
    if( s.find("at",1)  != s.size()-2 )
    {
        s.insert(s.find("at",1),"@");
        s.erase(s.find("at",1),2);
    }
   while(s.find("dot",1) != s.size()-3 && s.find("dot",1) != string::npos)
       
   {
      s.insert(s.find("dot",1),".");
      s.erase(s.find("dot",1),3);
   }
  cout<<s<<endl; 
    return 0;
}

