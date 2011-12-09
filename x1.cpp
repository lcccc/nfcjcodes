/*
 * Author: FreePascal
 * Created Time:  2011/10/30 12:55:19
 * File Name: x1.cpp
 */
#include <iostream>
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
long long a;
string s;
bool mycmp(int a,int b)
{
    return fabs(a) > fabs(b);
}
int main() {
    while(cin>>a && a)
    {
        vector<int> f;
        while(a--)
        {
            int k;cin>>k;f.push_back(k);
        }
        sort(f.begin(),f.end(),mycmp);
            for(int i = 0 ;i < f.size();i ++)
            {
                cout<<f[i];
                if(i != f.size()-1) cout<<' ';
                else cout<<endl;
            }
        //for(int i = 0;i < s.size();i ++) if(s[i] <='9' && s[i] >= '0') a++;
        //cout<<a<<endl;
    
    }
    return 0;
}

