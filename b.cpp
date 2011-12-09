/*
 * Team : FreePascal
 * Created Time:  2011年08月07日 星期日 13时06分51秒
 * File Name: 
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

const int maxn = 200 + 100;
const int maxm = 300000 + 100;
int a[maxn],x,CS;
struct node{
    int data,pre,len,reminder;
}q[maxn];

void dfs(int k){
    if (k == 1) return;
    dfs(q[k].pre);
    printf("%d",q[k].data);
}
void bfs(){
    int head,tail,reminder,len;
    head = 0; tail = 1; q[1].data = 0; q[1].pre = 0; q[1].reminder = 0; q[1].len = 0;
    while (head < tail){
        head++; reminder = q[head].reminder; len = q[head].len + 1;
        if (len > 200) break;
        printf("%d %d %d %d\n",head,q[head].data,q[head].len,reminder);
        if (q[head].data == 8 || q[head].data == 0){
            tail++;
            q[tail].data = 8; q[tail].pre = head; q[tail].reminder = (reminder * 10 + 8) % x; q[tail].len = len;
            if (q[tail].reminder == 0) break;
            tail++;
            q[tail].data = 6; q[tail].pre = head; q[tail].reminder = (reminder * 10 + 6) % x; q[tail].len = len;
            if (q[tail].reminder == 0) break;
        }
        if (q[head].data == 6){
            tail++;
            printf("%d %d %d %d\n",tail,q[tail].reminder,q[tail].len,q[tail].pre);
            q[tail].data = 6; q[tail].pre = head; q[tail].reminder = (reminder * 10 + 6) % x; q[tail].len = len;
            //printf("%d\n",tail);
            if (q[tail].reminder == 0) break;
        }
        //printf("%d %d %d\n",head,q[head].len,reminder);

    }
    printf("len = %d\n",len);
    if (len > 200) printf("-1");
    else dfs(tail);
}
int main() {
    freopen("b.in","r",stdin);
    scanf("%d",&CS);
    while (CS--){
        scanf("%d",&x);
        printf("x = %d\n",x);
        bfs();
        printf("\n");
    }
    return 0;
}

