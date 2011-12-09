/*
 ID: lc757692
 LANG:C++
 TASK:heritage
 * Created Time:  2011/8/3 19:15:11
 * File Name: heritage.cpp
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
#include <fstream>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
ofstream fout("heritage.out");
ifstream fin("heritage.in");
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
string in_ord,pre_ord;
void get_post(string is,string ps){
    if( is.empty()) return;
    if(is.size() ==1){
        fout<<is;
        return;
    }
    else 
    {
        char ch = ps[0];
        int k = is.find(ch);
        //cout<<is.substr(0,k)<<endl;
        //cout<<ps.substr(1,k)<<endl;
        //cout<<is.substr(k+1,is.size()-k-1)<<endl;
        //cout<<ps.substr(k+1,ps.size()-k-1)<<endl;
        get_post(is.substr(0,k),ps.substr(1,k));
        get_post(is.substr(k+1,is.size()-k-1),ps.substr(k+1,ps.size()-k-1));
        fout<<ch;
    }
}
int main() {
    fin>>in_ord>>pre_ord;
    get_post(in_ord,pre_ord);
    fout<<endl;

    return 0;
}

