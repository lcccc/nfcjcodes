/*
 * Author: Nfcj
 * Created Time:  2011年08月05日 星期五 21时13分56秒
 * File Name: 85-6.cpp
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
int f(int x){
    int ans = 0;
    while( x>0)
    if( x%2 ) ans++,x--;
    else x /= 2;
    return ans;
}
int main() {
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        cin>>n;
        cout<<f(n)<<endl;
    }
    return 0;
}

