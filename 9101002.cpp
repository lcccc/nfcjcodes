/*
 * Author: FreePascal
 * Created Time:  2011/9/10 12:39:54
 * File Name: 9101002.cpp
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
#define each(i, s, t) \
    __typeof (s) i = s; i != t; i++
    
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

//void *k = freopen("9101002.out", "w", stdout);

int N, M;
map < int, multiset<int> >  p1;
map < int, multiset<int> >  p2;

int main() 
{
    while (scanf("%d%d", &N, &M)!=EOF && (N||M))
    {
        p1.clear();
        p2.clear();
        for(each(i, 0, N))
        {
            int u, v;
            scanf("%d%d", &u, &v);
            p1[u].insert(v);
            p2[v].insert(u);   
        }
        for(each(i, 0, M))
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u == 0) {
                multiset <int> &s = p1[v];
                printf("%d\n", s.size());
                for (each(j, s.begin(), s.end()))
                    while (p2[*j].find(v) != p2[*j].end()) p2[*j].erase(v);
                p1.erase(v);
            }  else {
                multiset <int> &s = p2[v];
                printf("%d\n", s.size());
                for (each(j, s.begin(), s.end()))
                    while (p1[*j].find(v) != p1[*j].end()) p1[*j].erase(v);
                p2.erase(v);
            } 
        }
        puts("");
    }
    return 0;
}

