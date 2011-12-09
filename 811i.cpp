/*
 * Team : FreePascal
 * Created Time:  2011年08月11日 星期四 15时22分01秒
 * File Name: 811i.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

char G[12][12];
int ans;
int varval[256];
int order[81];

#define select(m) \
                     a[Y] ^= m, b[X] ^= m, c[k] ^= m;\
                    if (Y==8) \
                        dfs(X+1, 0, a, b, c);\
                    else\
                        dfs(X, Y+1, a, b, c);\
                    a[Y] ^= m, b[X] ^= m, c[k] ^= m;

void dfs(int X, int Y, int a[9], int b[9], int c[9])
{
    if (X==9) {ans++; return;}   
    switch (G[X][Y])
    {
        case '0':
        {
            int m = 2;
            int k = X/3*3+Y/3;
            for (int i=1; i<=9; i++)
            {
                if ( !(a[Y] & m) && !(b[X] & m) && !(c[k] & m))
                {
                    select(m);
                }
                m<<=1;
            }   
        }
        break;
        case 'e':
        {
            int m = 4;
            int k = X/3*3+Y/3;
            for (int i=2; i<=8; i+=2)
            {
                if ( !(a[Y] & m) && !(b[X] & m) && !(c[k] & m))
                {
                    select(m);
                }
                m<<=2;
            }
        }
        break;
        case 'o':   
        {
            int m = 2;
            int k = X/3*3+Y/3;
            for (int i=1; i<=9; i+=2)
            {
                if ( !(a[Y] & m) && !(b[X] & m) && !(c[k] & m))
                {
                   select(m);
                }
                m<<=2;
            }
        }
        break;
        case '1':        case '2':        case '3':        case '4':
        case '5':        case '6':        case '7':        case '8':
        case '9': 
                    if (Y==8) 
                        dfs(X+1, 0, a, b, c);
                    else
                        dfs(X, Y+1, a, b, c);
        break;
        default:
        {
            char g = G[X][Y];
            int k = X/3*3+Y/3;
            if (varval[(int)g] != -1)
            {
                int m =  (1<<varval[(int)g]);
                if ( !(a[Y] & m) && !(b[X] & m) && !(c[k] & m))
                {
                   select(m);
                }
            }
            else
            {
                int m = 2;
                for (int i=1; i<=9; i++)
                {
                    if ( !(a[Y] & m) && !(b[X] & m) && !(c[k] & m))
                    {
                        varval[(int)g] = i;
                        select(m);
                        varval[(int)g] = -1;
                    }
                    m<<=1;
                }   
            }
        }
        break;
    }
}



int a[9], b[9], c[9];
int var[256];
int varnum2[256];
int ve[2];


int main() 
{
    int T;
    scanf("%d", &T);    
    while (T--)
    {
            for (int i=0; i<9; i++) scanf("%s", G[i]);
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            memset(c, 0, sizeof(c));
            memset(var, 0, sizeof(var));
            memset(varval, -1, sizeof(varval));

            for (int i=0; i<9; i++)
                for (int j=0; j<9; j++)
                {
                    if (G[i][j] <= '9' && G[i][j] >= '1')
                    {
                        int k = G[i][j] - '0';
                        a[j] |= (1<<k);
                        b[i] |= (1<<k);
                        c[i/3*3+j/3] |= (1<<k);
                    }   
                }
            //for (int i=0; i<81; i++) order[i] = i;
            //sort(order, order+81, cmp);
            ans = 0;
            dfs(0, 0,  a, b, c);
            printf("%d\n", ans);
            
    }
    return 0;
}

