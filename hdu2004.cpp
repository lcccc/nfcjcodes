/*
 * Team : FreePascal
 * Created Time:  2011年08月16日 星期二 18时11分35秒
 * File Name: hdu2004.cpp
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
void lev(int t)
{
    if( t > 100 )cout<<"Score is error!"<<endl;
    else if(t > 89) cout<<"A"<<endl;
    else if(t > 79) cout<<"B"<<endl;
    else if(t > 69) cout<<"C"<<endl;
    else if(t > 59) cout<<"D"<<endl;
    else if(t > 0) cout<<"E"<<endl;
    else cout<<"Score is error!"<<endl;
}
int main() {
    int t;
    while(cin>>t)
    lev(t);
    return 0;
}

