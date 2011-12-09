/*
 * Team : FreePascal
 * Created Time:  2011年08月19日 星期五 15时41分10秒
 * File Name: 819d.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define SZ(v) ((int)(v).size())


   int ch[1001][2];
   bool isLeaf[1001];
   int subleaf[1001];
   int weight[1001];
int values[1001];
int leaves[100];
long long ht[131072];
long long iht[131072];
bool used[100];
int ntot;
int N;
int B;
double ans = 0;
double alns;
vector <int> G[20];

void getSub(int p)
{
    if (isLeaf[p]) {subleaf[p] = 1; return ;}
    getSub(ch[p][0]);   
    getSub(ch[p][1]);
    subleaf[p] = subleaf[ch[p][0]]+subleaf[ch[p][1]];
}

int ones(int p)
{
    int ans = 0;
    while(p>0) { ans++; p^=(p&-p); }
    return ans;
}

int abso(int a)
{
    return a<0?-a:a;   
}

long long tree_dp(int rt, int state)
{
    if (isLeaf[rt]) return 0; 
    if (subleaf[rt] == 2) {
            int w1 = state & (-state);
            int w2 = state ^ w1;
            return 10000000*((abso(ht[w1]-ht[w2])*iht[state])&2147483647);
    }
    int L = subleaf[ch[rt][0]];
    int R = subleaf[ch[rt][1]];
    int l = ch[rt][0];
    int r = ch[rt][1];
    long long ans = (-1uLL)>>1;
    if (G[L].size()<G[R].size())
    {
        for (vector<int>::iterator  it=G[L].begin(), ed=G[L].end(); it!=ed; it++)
         {
            int w1 = *it;;
            if ((state & w1) != w1) continue;
            int w2 = state ^ w1;
            ans = min(ans, tree_dp(l, w1) + tree_dp(r, w2) + 
                          10000000 * ((abso(ht[w1]-ht[w2])*iht[state])&2147483647)); 
        }
    }else{
         for (vector<int>::iterator  it=G[R].begin(), ed=G[R].end(); it!=ed; it++)
         {
            int w2 = *it;;
            if ((state & w2) != w2) continue;
            int w1 = state ^ w2;
            ans = min(ans, tree_dp(l, w1) + tree_dp(r, w2) + 
                          10000000 *((abso(ht[w1]-ht[w2])*iht[state])&2147483647)); 
        }
    }
    return ans;
}

long long inverse(int i)
{
    return 2147483647LL / i;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--)
    {
      scanf("%d", &B);
      ntot = 0;
      for (int i=1; i<=B; i++)
      {
              scanf("%d%d", &ch[i][0], &ch[i][1]);
              if ((isLeaf[i]= (ch[i][0]==-1 && ch[i][1]==-1)))
                leaves[ntot++]=i;
      }
      
      for (int i=0; i<=ntot; i++)
          G[i].clear();
      for (int i=1; i<(1<<ntot); i++)
          G[ones(i)].push_back(i);
      
      getSub(1);
      scanf("%d", &N);
      for (int i=0; i<N; i++)
          scanf("%d", &values[i]);      
      
      for (int i=1; i<(1<<ntot); i++)
      {
          ht[i]=0;
          for (int j=0; j<N; j++)
            if (i&(1<<j)) ht[i] = ht[i^(1<<j)]+values[j];
          iht[i] = inverse(ht[i]);
          G[ones(i)].push_back(i);
      }
      
      
      printf("%.3lf\n", tree_dp(1, (1<<ntot)-1)/2147483647*0.00005);
    }
    return 0;
}

