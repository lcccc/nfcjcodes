/*
ID:lc757692
LANG:C++
TASK:maze1
*/
#include<cstdio>
using namespace std;
char map[201][80];
long queue[16000][3],jishu[16000];
long H,W,tou,wei,mm;
int main()
{
    FILE *in,*out;
    in=fopen("maze1.in","r");
    out=fopen("maze1.out","w");
    fscanf(in,"%ld %ld\n",&W,&H);
    for(long i=0;i<=2*H;i++)
        for(long j=0;j<=2*W+1;j++){
            fscanf(in,"%c",&map[i][j]);
            if(map[i][j]==' ' && (i==0||i==2*H||j==0||j==2*W)){
                queue[wei][0]=i;queue[wei++][1]=j;
            }
            else if(map[i][j]!=' ') map[i][j]='+';
        }
    jishu[0]=1,jishu[1]=1;
    long k=0;
    while(tou!=wei)
    {
        long x=queue[tou][0],y=queue[tou][1],now=jishu[tou],t=queue[tou][2];
        map[x][y]=now;
        k++;
        tou++;
        if (now>mm)
            mm=now;
        if(map[x-1][y]!=' ' && map[x][y-1]!=' ' && map[x+1][y]!=' ' && map[x][y+1]!=' ' )
           continue;
        if(x>0 && map[x-1][y]==' '){
            map[x-1][y]=now+1;queue[wei][0]=x-1;queue[wei][1]=y;jishu[wei++]=now+1;
        }
        if(y<2*W && map[x][y+1]==' '){
            map[x][y+1]=now+1;queue[wei][0]=x;queue[wei][1]=y+1;jishu[wei++]=now+1;
        }
        if(x<2*H && map[x+1][y]==' '){
            map[x+1][y]=now+1;queue[wei][0]=x+1;queue[wei][1]=y;jishu[wei++]=now+1;
        }
        if(y>0 && map[x][y-1]==' '){
            map[x][y-1]=now+1;queue[wei][0]=x;queue[wei][1]=y-1;jishu[wei++]=now+1;
        }
    }
    fprintf(out,"%ld\n",(mm)/2);
    return 0;
}
