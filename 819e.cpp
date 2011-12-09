/*
 * Team : FreePascal
 * Created Time:  2011年08月19日 星期五 12时38分34秒
 * File Name: 819e.cpp
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

const int maxn = 100 + 100;
int n,k,reminder[maxn],shang[maxn];
int main() {
    while (scanf("%d%d",&n,&k) != EOF){
        int ans = 0;
        while (n > 1){
            memset(reminder,-1,sizeof(reminder));
            int x = 1; int j = 0;
            while (true){
                //j++;
                x = x * 10;
                shang[j] = x / n;
                x = x % n;
                j++;
                if (reminder[x] != -1) break;
                reminder[x] = j;
            }
            x = x % n;
            //if (n == 6)
                //for (int i = 0; i < j; i++) printf("%d\n",shang[i]);
            
            if (x == 0) {
                reminder[x] = 0;
                j--;
            }
            
            //printf("n = %d\n",n);
            //printf("%d %d\n",x,reminder[x]);
            //for (int i = reminder[x]; i < j; i++) printf("%d",shang[i]);
            //printf("\n");
            for (int i = 0; i < reminder[x]; i++)
                if (shang[i] == k) ans++;
            for (int i = reminder[x]; i < j; i++)
                if (shang[i] == k) ans++;
            //printf("%d %d\n",n,ans);
            n--;
        }
        printf("%d\n",ans);
    }
    return 0;
}

