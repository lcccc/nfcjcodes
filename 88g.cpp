/*
 * Team : FreePascal
 * Created Time:  2011年08月08日 星期一 15时35分24秒
 * File Name: 88g.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;
#define SZ(v) ((int)(v).size())
char op[15][15];
int p[15];
int ans[15];
int sum[15];
int t,n;
bool check()
{
 //   int b = 1;
    for(int i = 1;i <= n;i++)
        for(int j = i;j <=n;j++)
        {
            int tm = accumulate(ans+i,ans+j+1,0);
            if( tm > 0 && op[i][j]!='+') return false;
            if( tm == 0 && op[i][j]!='0') return false;
            if( tm < 0 && op[i][j]!='-') return false;
        }
    return true;
}
void output()
{
    for(int i = 1; i <= n;i++)
        cout<<ans[i]<< ((i==n)?"\n":" ");
}

#define sgn(p)   ( ((p)>-(p)) - ((p)<-(p)) )
const char *sign = "-0+";
bool check(int x)
{
        for (int i=1; i<=x; i++)
        {
            int s = sum[x] - sum[i-1];
            int g = sgn(s)+1;
            if ( sign[g]!=op[i][x])
                return false;
        }
        return true;
}

int v[51][51][301];
int dfs(int x)
{
    if( x >  n) {
        output();
        return 1;
    }
    else 
        static int table [] = {-10, 10, -9, 9, -8, 8, -7, 7, -6, 6, -5, 5, -4, 4, -3, 3, -2, 2, -1, 1, 0};
        if (op[x][x] == '0') 
        {
            ans[x] = 0;
            sum[x] = sum[x-1];
            if (dfs(x+1)) return true;
        }
        else  if (op[x][x] == '-')            
            for (int i=-10; i<0; i++)
            {
                 ans[x] = i;
                 sum[x] = sum[x-1]+i;
                 if (!check(x)) {continue;}
                 if (dfs(x+1)) return 1;
            }            
        else 
            for (int i=10; i>0; i--)
            {
                 ans[x] = i;
                 sum[x] = sum[x-1]+i;
                 if (!check(x)) {continue;}
                 if (dfs(x+1)) return 1;
            }            

    
    return 0;
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
        memset(v, -1, sizeof(v));
        int tot = 0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                op[i][j] = s[tot++];
        sum[0] = 0;
        dfs(1);
    }
        
    return 0;
}

