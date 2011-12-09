/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 21时18分40秒
 * File Name: 85-7.cpp
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
string s;
int main() {
    while(cin>>s)
    {
        if( s == "#") break;
        int n;
        n = count(s.begin(),s.end(),'1');
        if( s[s.size()-1] == 'e')
        {
            if( n % 2) s[s.size()-1] = '1';
            else s[s.size()-1] = '0';
        }
        else if( n % 2) s[s.size()-1] = '0';
            else s[s.size()-1] = '1';
        cout<<s<<endl;
    }
    return 0;
}

