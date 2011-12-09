/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 14:13:34
 * File Name: 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct State{
    int a[4][2];
    bool judge(int *a, int *b, int *c, int *d)
    {
        if (a[0] == b[0] && a[1]==b[1] 
         || c[0] == d[0] && c[1]==d[1]) return false;
        if (a[0] == b[0] && b[0] == c[0] && c[0] == d[0]
        ||  a[1] == b[1] && b[1] == c[1] && c[1] == d[1]) return false;
        return  (a[0] == b[0] || a[1]==b[1]) && (c[0] == d[0] || c[1] == d[1]);
    }
    bool check()
    {
        int d[]={0,1,2,3};
        for (int i=0; i<4; i++)
            for (int j=i+1; j<4; j++)
                if (a[i][0] == a[j][0] && a[i][1] == a[j][1]) return false;
        for (int i=0; i<24; i++)
        {
            if (judge(a[d[0]], a[d[1]], a[d[2]], a[d[3]]) &&
                judge(a[d[2]], a[d[3]], a[d[0]], a[d[1]]))return true;
            next_permutation(d, d+4);
        }
        return false;
    }
    
    void doMove(int i, int j, int dim)
    {
        a[i][dim] = a[j][dim];   
    }
    
    void print() const
    {
         for (int i=0; i<4; i++)
            printf("%d %d\n", a[i][0], a[i][1]);
    }
    
}org;

bool move1()
{
    State o;
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (i!=j)
            {
                o=org;
                o.doMove(i, j, 0);
                if (o.check()) {o.print(); return true;}
                o=org;
                o.doMove(i, j, 1);
                if (o.check()) {o.print(); return true;}
            }
    return false;
}

bool move2()
{
   State o;
   for (int i=0; i<4; i++)
       for (int j=i+1; j<4; j++)
           for (int k=0; k<4; k++)
               for (int l=k+1; l<4; l++)
                    for (int dim1 = 0; dim1<2; dim1++)
                        for (int dim2=0; dim2<2; dim2++)
                        {
                            o = org;
                            o.doMove(i, j, dim1);
                            o.doMove(k, l, dim2);
                            if (o.check()){o.print();return true;}
                        }   
   return false;
} 



void move3()
{
        State o=org;
        o.a[2][0]++; if (o.a[2][0] > 20) o.a[2][0]=1;
        o.a[2][1]++; if (o.a[2][1] > 20) o.a[2][1]=1;
        o.a[3][0]++; if (o.a[3][0] > 20) o.a[3][0]=1;
        o.a[3][1]++; if (o.a[3][1] > 20) o.a[3][1]=1;
        if (o.check()) {o.print();}
}

int main() 
{
    freopen("83j.out", "w", stdout);
    while (true)
    {
        for (int i=0; i<4; i++)
          if (scanf("%d%d", &org.a[i][0], &org.a[i][1])==EOF) return 0;
        for (int i=0; i<4; i++)
            printf(" %d %d", org.a[i][0], org.a[i][1]);
        printf("\n");
        if (org.check())
           org.print();
       else
        {
           if (!move1())
           if (!move2())
               move3();
        }
    }
    return 0;
}

