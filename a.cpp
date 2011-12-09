<<<<<<< HEAD
/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 12时34分38秒
 * File Name: 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "sstream"
using namespace std;
#define SZ(v) ((int)(v).size())
int a[2048000];
int main() {
    int T;
    scanf("%d\n", &T);
    while (T--)
    {
        static char s[2048000];
        gets(s);
        stringstream str(s);
        string c;
        int tot = 0;
        while (str>>c)
            a[tot++] = c.size();
        int ans = !!tot;
        
        int   k = 1;
        for (int i=1; i<tot; i++)
            if (a[i] == a[i-1]) k++, ans=max(ans, k);
            else k=1,ans = max(ans,k);
        printf("%d\n", ans);
    }
    return 0
}

=======
#include<stdio.h>
#include<stdlib.h>

int main(){
   int a1[100],a2[100];
   int k,tot = 0;
   for(int i = 0;i < 4;i ++) scanf("%d",&a1[i]);
   for(int i = 0;i < 4;i ++) scanf("%d",&a2[i]);
   int i = 0,j = 0;
   for(int k = 0;k < 8;k ++)
   {
       if( a1[i] < a2[j] && i < 4) printf("%d ",a1[i++]);
       else printf("%d ",a2[j++]);
   }
}
        
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
