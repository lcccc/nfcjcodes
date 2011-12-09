/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 21时11分41秒
 * File Name: 85-5.cpp
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
string s1,s2;
int main() {
    cin>>n;
    while(n--)
    {
        cin>>s1>>s2;
        s1.insert(s1.size()/2,s2);
        cout<<s1<<endl;
    }
    return 0;
}

