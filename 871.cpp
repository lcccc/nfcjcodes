/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 19时02分20秒
 * File Name: 871.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

int main() {
    int n;
    int score = 10;
    cin>>n;
    if( n <= 10) cout<<0<<endl;
    else 
    {
        int want = n - score;
        if( want < 10 ) cout<<4<<endl;
        if( want == 10) cout<<15<<endl;
        if( want == 11) cout<<4<<endl;
        if( want > 11) cout<<0<<endl;
    }
    return 0;
}

