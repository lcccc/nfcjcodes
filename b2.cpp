#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;
#define out(X) cerr << #X << ": " << (X) << endl
#define SZ(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define REP(I,N) for (int I = 0; I < (N); ++I)
#define FOR(I,L,H) for (int I = (L); I < (H); ++I)
#define for_each(I,V) for (typeof(V.begin()) I = V.begin(); I != V.end(); ++I)
#define MP(X,Y) make_pair((X),(Y))
#define PB push_back
#define ALL(X) X.begin(), X.end()
template <typename T> inline bool checkmin(T &a, const T &b)
{
    return a > b ? a = b, 1 : 0;
}
template <typename T> inline bool checkmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}
typedef long long LL;

const int MAXN = 10000 + 10;

vector<int> a[MAXN];

void cut(vector<int> a, vector<int> &b, vector<int> &c, const int &l, const int &r)
{
    b.clear();
    c.clear();
    for (int i = find(ALL(a), l) - a.begin(); ; i = (i + 1) % SZ(a))
    {
        b.PB(a[i]);
        if (a[i] == r) break;
    }
    for (int i = find(ALL(a), r) - a.begin(); ; i = (i + 1) % SZ(a))
    {
        c.PB(a[i]);
        if (a[i] == l) break;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int cnt = 1;
        a[0].clear();
        REP(i, n)
        a[0].PB(i);
        REP(i, m)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            REP(i, cnt)
            {
                if (find(ALL(a[i]), l) != a[i].end() &&
                        find(ALL(a[i]), r) != a[i].end())
                {
                    cut(a[i], a[i], a[cnt++], l, r);
                    break;
                }
            }
        }
        int ans = 0;
        REP(i, cnt)
        {
            checkmax(ans, SZ(a[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}

