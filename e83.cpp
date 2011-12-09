/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/3 13:13:58
 * File Name: e83.cpp
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 1000;
char st[maxn];
bool home;
int CS,get,lose,hg,hl,ag,al;

int main() {
    scanf("%d",&CS);
    while (CS > 0, CS--){
        scanf("%s%s%s",st,st,st);
        scanf("%s",st);
        if (st[0] == 'h') home = true;
        else home = false;
        scanf("%s%s",st,st);
        scanf("%d",&get);
        scanf("%s%s%s",st,st,st);
        scanf("%d",&lose);
        scanf("%s",st);
        if (home){
            hg = get; hl = lose;
            al = 0;
            int tmp;
            for (ag = 0; ag <= 30; ag++){
                tmp = get + ag;
                if (tmp < lose) continue;
                if (tmp == lose){
                    if (ag <= hl) continue;
                    else break;
                }
                if (tmp > lose) break;
            }
            printf("%d ",ag);
            lose = lose + 30;
            al = 30;
            for (ag = 30; ag >= 0; ag--){
                tmp = get + ag;
                if (tmp > lose) continue;
                if (tmp == lose)
                    if (ag >= hl) continue;
                    else break;
                if (tmp < lose) break;
            }
            printf("%d\n",ag);
        }
        else {
            hg = 0; hl = 0;
            ag = get; al = lose;
            int tmp;
            for (hg = 0; hg <= 30; hg++){
                tmp = get + hg;
                if (tmp < lose) continue;
                if (tmp == lose){
                    if (ag <= hl) continue;
                    else break;
                }
                if (tmp > lose) break;
            }
            printf("%d ",hg);
            lose = lose + 30;
            hl = 30;
            for (hg = 30; hg >= 0; hg--){
                tmp = get + hg;
                if (tmp > lose) continue;
                if (tmp == lose)
                    if (ag >= hl) continue;
                    else break;
                if (tmp < lose) break;
            }
            printf("%d\n",hg);
        }
    }
    return 0;
}

