/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/5 12:15:50
 * File Name: 851.cpp
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
string s;
int main() {
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s.size()>10)
        {
            cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
        }
        else cout<<s<<endl;
    }
    return 0;
}

