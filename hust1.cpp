/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/7/30 19:39:32
 * File Name: hust1.cpp
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

int main() {
    LL ans = 0,cs,n;
    scanf("%d",&cs);
    while(cs--)
    {
        scanf("%d",&n);
        vector<int> f;
        vector<int> ff;
        for(int i = 0;i < n;i++)
        {
            int tm;
            scanf("%d",&tm);
            f.push_back(tm);
            ff.push_back(tm);
        }
        ans = 0;
        sort(ff.begin(),ff.end());
        for(int i = 0;i < ff.size();i++)
            if( f[i] != ff[i] )
            {
                ans++;
                //swap(f[find(f.begin()+i,f.end(),ff[i])-f.begin()],f[i]);
                for(int k = i;k<f.size();k++)
                    if(f[k] == ff[i])
                    {
                        swap( f[i],f[k]);
                        break;
                    }
            }
        
        printf("%d\n",ans);
    }
    return 0;
}

