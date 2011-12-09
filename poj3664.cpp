/*
 * Author: FreePascal
 * Created Time:  2011/11/2 13:29:57
 * File Name: poj3664.cpp
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
struct cow{
    int va,vb,id;
};
cow tc;
vector<cow> cows;
int n,k;
bool mycmp1(cow c1,cow c2)
{
    return c1.va > c2.va;
}
bool mycmp2(cow c1,cow c2)
{
    return c1.vb > c2.vb;
}
int main() {
    //cin>>n>>k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++)
    {
        //cin>>tc.va>>tc.vb;
        scanf("%d%d", &(tc.va),&(tc.vb));
        tc.id = i;
        cows.push_back(tc);
    }
    sort(cows.begin(),cows.end(),mycmp1);
    sort(cows.begin(),cows.begin() + k,mycmp2);
    cout<<cows[0].id + 1<<endl;
    return 0;
}

