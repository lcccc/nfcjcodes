/*
 * Author: FreePascal
 * Created Time:  2011-8-22 13:38:08
 * File Name: b.cpp
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
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 500 + 100;
int n,m;
map<string,int> a[7];
string st[maxn],s[maxn];
int ans;

bool work(int p){
    vector<int> visit;
    bool can[maxn];
    visit.clear();
    visit.push_back(0);
    for (int j = 0; j < m; j++){
        visit.push_back(a[p][st[j]]);
        out(a[p][st[j]]);
    }
    sort(visit.begin(),visit.end());
    for (int i = 2; i < visit.size(); i++)
        if (visit[i - 1] + 30 > visit[i]) return false;
    memset(can,true,sizeof(can));
    int sum = 0;
    for (int i = 0; i < visit.size(); i++){
        for (int j = 0; j < n; j++){
            int q,min = maxint;
            for (int k = 0; k < n; k++)
                if (can[k] && j != k && min > a[p][s[k]] && a[p][s[k]] + 30 <= visit[i] && visit[i - 1] + 30 <= a[p][s[k]]){
                    min = a[p][s[k]];
                    q = k;
                }
            if (min == maxint) break;
            can[q] = false;
            sum++;
        }
    }
    ans += sum;
    return true;
}

int main() {
    while (scanf("%d",&n) != EOF){
        if (n == 0) break;
        for (int i = 0; i < 7; i++) a[i].clear();
        for (int i = 0; i < n; i++){
            int x,y;
            char tmp[30];
            scanf("%s%d%d",tmp,&x,&y);
            s[i] = tmp;
            a[x][s[i]] = y;
        }
        char tmp[40];
        scanf("%d",&m);
        for (int i = 0; i < m; i++){
            scanf("%s",tmp);
            st[i] = tmp;
        }
        bool flag = true;
        ans = 0;
        for (int i = 0; i < 7; i++){
            flag &= work(i);
            if (!flag) break;
        }
        if (!flag) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}


