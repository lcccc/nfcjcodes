/*
 * Author: FreePascal
 * Created Time:  2011/10/7 0:26:52
 * File Name: lorem.cpp
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

int main() {
    ifstream cin("lorem.txt");
    map<string,int> dic;
    string w;
    while(cin>>w)
    {
        dic[w]++;
    }
    map<string,int>::iterator p;
    for(p = dic.begin();p != dic.end(); p++)
        if(p->second == 1 ) 
            cout<<p->first<<endl;
    return 0;
}

