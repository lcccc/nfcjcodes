/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 20时54分07秒
 * File Name: 85-3.cpp
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
int n;
string s;
int main() {
    cin>>n;
    while(n--)
    {
        cin>>s;
        for(int i = 0;i < s.size();i+=2)
        {
            swap(s[i],s[i+1]);
        }
        cout<<s<<endl;
    }
    return 0;
}

