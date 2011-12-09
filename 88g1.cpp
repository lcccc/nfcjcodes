/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 16时43分18秒
 * File Name: 88g1.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
#define SZ(v) ((int)(v).size())

const int maxint = ~0u>>2;
const int maxn = 100 + 100;
char op[100][100];
int ops[1000];
    int t, n;
struct node{
    int v,w;
    node(int _v,int _w):
        v(_v),w(_w) {}
    node() {};
};
vector<node> e[maxn];
int d[maxn];
queue<int> q;

bool cmp(const int &a, const int &b)
{
    //sum a - sum b = op[b+1][a]
    if (a == b) return false;
    if (a < b) 
        return op[a+1][b]=='+';
    else
        return op[b+1][a]=='-';
    return false;
}

void makemap(){
    for (int i = 0; i <= n; i++) e[i].clear();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i!=j)
            {
                 if (op[i][j] == '+'){
                        e[i].push_back(node(j,1));
                }
                else if (op[i][j] == '0'){
                    e[i].push_back(node(j,0));
                }
                else {
                    e[i].push_back(node(j,-1));
                }
            }
}
void spfa(){
    bool inq[maxn];
    int u,v;
    memset(inq,0,sizeof(inq));
    for (int i = 1; i <= n; i++) d[i] = maxint;
    d[0] = 0; inq[0] = true; q.push(0);
    while (!q.empty()){
        u = q.front(); q.pop(); inq[u] = false;
        for (int i = 0; i < (int)e[u].size(); i++){
            v = e[u][i].v;
            if (abs(d[v]) < abs(d[u] + e[u][i].w)){
                d[v] = d[u] + e[u][i].w;
                if (!inq[v]){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin>>t;
    while(t--)
    {
        cin >> n;
        string s;
        getline(cin,s);
        getline(cin,s);
        //memset(v, -1, sizeof(v));
        int tot = 0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
            {
                op[i][j] = s[tot++];
               // if (op[i-1][j]=='0') op[j][i-1]='0';
               // else op[j][i-1]=op[i-1][j]^'+'^'-';
            }
        for (int i=1; i<=n; i++)
            ops[i] = i;
        ops[0]=0;
        int ans[100];
        int rank[100];
        sort(ops, ops+n+1, cmp);
        for (int i=0; i<=n; i++)
            rank[ops[i]] = i;
        int k = 0;
        for (int i=1; i<=n; i++)
        {
            k+=rank[i]-rank[i-1];
            cout << k << " "; 
        }
        cout << endl;
        int q = -10;
                
        //cout << endl;
        //bfs();                
//        makemap();
//      spfa();
        //sum[0] = 0;

        for (int i = 1; i <= n; i++) 
        {
         
        //    cout << d[i] - d[i - 1];
         //   if (i==n) cout << endl; else cout << ' ';
        }
    }
        
    return 0;
}

