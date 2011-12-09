#include<iostream>
#include<cstring>
using namespace std;
const int nMax = 1000010;
const int mMax = 80000;
typedef __int64 LL;
 
bool p[nMax];
int pri[mMax];
int cnt, num[50];
 
void priList(){        //   ���������ģ�塣
    int i, j;
    memset(p, true, sizeof(p));
    for(i = 2; i * i < nMax; i ++)
        if(p[i]){
            for(j = i << 1; j < nMax; j += i)
                p[j] = false;
        }
    for(j = 0, i = 2; i < nMax; i ++)
        if(p[i]) pri[j ++] = i;
}
 
int mod(int Mod){      //   �ж�K��������Mod��������
    LL ans = 0;
    for(int i = cnt; i >= 0; i --)
        ans = (ans*1000000000 + num[i]) % Mod;
    return (int)ans;
}
 
int main(){
    char K[110];
    int L, i, k;
    priList();
    while(scanf("%s%d", K, &L) && L){
        memset(num, 0, sizeof(num));
        cnt = 0;
        for(k = 1, i = strlen(K)-1; i >= 0; i --, k *= 10){     //  ��K���зֽ⡣
            if(k == 1000000000){
                k = 1; cnt ++;
            }
            num[cnt] += (K[i]-'0') * k;
        }
        bool flag = false;
        for(i = 0; pri[i] < L; i ++)
            if(mod(pri[i]) == 0){
                flag = true;
                break;
            }
        if(flag) printf("BAD %d\n", pri[i]);
        else printf("GOOD\n");
    }
    return 0;
}

