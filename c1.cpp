/*
 * Author: FreePascal
 * Created Time:  2011/10/27 14:50:55
 * File Name: c1.cpp
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
#include <fstream>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
string s;
int a;
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin>>s>>a;
    if(s == "front")
    {
        if(a == 1) cout<<'L'<<endl;
        else cout<<'R'<<endl;
    }
    else 
        if(a == 1 ) cout<<"R"<<endl;
        else cout<<"L"<<endl;
    return 0;
}

