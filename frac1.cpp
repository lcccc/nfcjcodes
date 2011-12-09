/*
ID:lc757692
TASK:frac1
LANG:C++


 * Author: Nfcj
 * Created Time:  2011年07月16日 星期六 17时45分51秒
 * File Name: frac1.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
inline string NumberToString(int n);

int main() {
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    
    int n;
    cin>>n;
    map<float,string> fractions;
    fractions[0] = "0/1";
    fractions[1] = "1/1";
    for(float fm = n;fm > 1.0; fm--)
        for(float fz = 1.0;fz<fm;fz++)
        {
            float frac = fz / fm;
            string frac_s;
            frac_s+=NumberToString(fz);
            frac_s.push_back('/');
            frac_s+=NumberToString(fm);
            fractions[frac] = frac_s;
        }
        for(map<float,string>::iterator iter=fractions.begin();iter!=fractions.end();iter++)
            cout<<iter->second<<endl;
        return 0;
    }
inline string NumberToString(int n){
    string num;
    while(n){
        num.insert(num.begin(),n%10+'0');
        n/=10;
    }
    return num;
}
