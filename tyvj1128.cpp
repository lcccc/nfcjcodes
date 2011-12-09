/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/21 12:36:29
 * File Name: tyvj1128.cpp
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
void f(int x)
{
    int b =0; 
    int n = x;
    if(x == 0) cout<<0<<endl;
    else{
    if( x / 10000000){
        b = 1;
        if( x/100000000/10)
            cout<<x/100000000/10<<"shi";
        if( x/100000000%10)
            cout<<x/100000000%10;
        cout<<"yi";
    }
    else if(b)cout<<0;
    x %= 100000000;
    
    if( x / 10000 )
    {
        b = 1;
        if( x/10000/1000)
            cout<<x/10000/1000<<"qian";
        if( x/10000/100%10)
            cout<<x/10000/100%10<<"bai";
        if( x/10000/10%10)
            cout<<x/10000/10%10<<"shi";
        if( x/10000%10)
            cout<<x/10000%10;
        cout<<"wan";
    }
    else if(b)cout<<0;
    x %= 10000;
    if(x)
    {
        b =1;
        if(x/1000)
            cout<<x/1000<<"qian";
        if(x/100%10)
            cout<<x/100%10<<"bai";
        if(x/10%10)
            cout<<x/10%10<<"shi";
        if(x%10)
            cout<<x%10;
    }
    cout<<endl;
    }
}
int main() {
    long long n;
    while(cin>>n)
    f(n);
    return 0;
}

