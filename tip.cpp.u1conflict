/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/24 19:39:56
 * File Name: tip.cpp
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
    char n;
    for(int i = '!';i<='Z';i++)
    {
        n = i;
        if(n < 128)
            n+=128;
        else if(n>127) n-=128;
        n=255-n;
        printf("%c %02x\n",i,n);
    }
    return 0;
}

