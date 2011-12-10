/*
 * Author: FreePascal
 * Created Time:  2011/11/27 23:15:39
 * File Name: subsititute.cpp
 */
#include <iostream>
#include <fstream>
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

int main() {
    ofstream cout("dict.txt");
    string s = "ISS NVVK DIPXYWA PIT AVSUY QIAOP PWZEHVNWIEDZ. CDYT ZVM LOTK HDY AVSMHOVT HV HDOA HYFH, ZVM COSS QY IQSY HV NYH HDY ITACYW, CDOPD OA IKMGQWIHY.";
    for(int k = 1;k <= 26;k++)
    {
        for(int i = 0;i < s.size();i ++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] ++;
            if(s[i] > 'Z') s[i] = 'A';
        }
        }
        cout<<s<<endl;
    }
    return 0;
}

