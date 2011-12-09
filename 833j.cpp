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
        bool
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

int main() 
{
    while (true)
    {
        for (int i=0; i<4; i++)
          if (scanf("%d%d", &org.a[i][0], &org.a[i][1])==EOF) return 0;
        
        for (int i=0; i<4; i++)
            for (int j=i+1; j<4; j++)
            {
                           
            }
 
    }
    return 0;
}

