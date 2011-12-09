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
    int a[2][4];
    void print() const
    {
         for (int i=0; i<4; i++)
            printf("%d %d\n", a[0][i], a[1][i]);
    }
    
}org;


int countmax(int c[])
{
    int ret=0;
    for (int i=0; i<4; i++)
    {
        int ans = 1;
        for (int j=i+1; j<4; j++)
           if (c[i] == c[j]) ans++;
        ret = max(ans, ret);
    }
    return ret;
}

int countmin(int c[])
{
    int ret=9999;
    for (int i=0; i<4; i++)
    {
        int ans = 1;
        for (int j=i+1; j<4; j++)
           if (c[i] == c[j]) ans++;
        ret = min(ans, ret);
    }
    return ret;
}

void wrap_inc(int &a, int b=1, int c=20)
{
    a++;
    if (a>c) a=b;
}

int classfy(int a[], int b[])
{
    b[0] = b[1] = b[2] = b[3]=0;
    int cls=0;
    for (int i=0; i<4; i++)
    {
        if (b[i] == 0) b[i] = cls++;
        for (int j=i+1; j<4; j++)  
        {
            if (a[i] == a[j]) b[j] = b[i];   
        }
    }   
}

int main()
{
    while (true)
    {
        for (int i=0; i<4; i++)
          if (scanf("%d%d", &org.a[0][i], &org.a[1][i])==EOF) return 0;
        int f1 = countmax(org.a[0]), f2 = countmax(org.a[1]);
        int var;
        int b = 0;
        if (f1 < f2)
            var = f2, b=1;
        else
            var = f1;
        switch(var)
        {
            case 4:
                wrap_inc(org.a[b][2]); wrap_inc(org.a[b][3]); org.print(); break;
            case 3:
                                
                
                
            case 2:
                
                org.print();break;
            case 1:
                org.a[0][2] = org.a[0][0] ;       org.a[1][2] = org.a[1][1];
                org.a[0][3] = org.a[0][1] ;       org.a[1][3] = org.a[1][0];
                org.print();break;
        }    
    }
    return 0;
}


