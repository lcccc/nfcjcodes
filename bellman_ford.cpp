/*
 * Author: FreePascal
 * Created Time:  2011/10/30 11:19:51
 * File Name: bellman_ford.cpp
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
#define MAXN 200
#define inf 100000000
typedef int elem_t;
int bellman_ford(int n,elem_t mat[][MAXN],int s,elem_t* min,int* pre){
    int v[MAXN],i,j,k,tag;
    for(i = 0;i < n;i ++)
        min[i] = inf,v[i] = 0,pre[i] =  -1;
    for(min[s] = 0,j = 0;j < n;j ++){
        for(k = -1,i = 0;i < n;i++)
            if(!v[i]&&(k==-1||min[i] < min[k] ))
                k = i;
        for(v[k] = 1,i = 0;i < n;i ++)
            if(!v[i] && mat[k][i] >= 0 && min[k]+ mat[k][i] < min[i])
                min[i] = min[k] + mat[pre[i]=k][i];
    }
    for(tag = 1,j = 0;tag&&j<=n;j++)
        for(tag = i = 0;i < n;i ++)
            for(k = 0;k < n;k ++)
                if(min[k] + mat[k][i] < min[i])
                    min[i] = min[k] + mat[pre[i] = k][i],tag = 1;
    return j<=n;
}
int main() {
    return 0;
}

