#include<fstream>
#include<cstring>
#include<stdio.h>
using namespace std;
 
struct node{
       int lth,des,link;
};
 
const int MAXV=100005;
const int MAXE=29001;
int n,p,c,i;
int cow[MAXV],lc[MAXV],q[1024],inq[MAXV];
int dis[MAXV];
node heap[2*MAXV];
 
void init(){
	int t,u,ll,tmp,htop=0;
	scanf("%d%d%d",&n,&p,&c);
	i=1;
	while (i<=n){
        scanf("%d",&t);
        cow[t]++;
        i++;
    };
    for (i=1;i<=c;i++){
        scanf("%d%d%d",&t,&u,&ll);
        tmp=lc[t];htop++;lc[t]=htop;
        heap[htop].link=tmp;heap[htop].des=u;heap[htop].lth=ll;
        tmp=lc[u];htop++;lc[u]=htop;
        heap[htop].link=tmp;heap[htop].des=t;heap[htop].lth=ll;
    };
};
 
int spfa(int d){
    int tail=0,head=-1,cup,sum=0;
    q[0]=d;dis[d]=0;inq[d]=1;
    while (head!=tail) {
          head=(head+1)&1023;
          cup=lc[q[head]];
          while (cup) {
                if (dis[q[head]]+heap[cup].lth<dis[heap[cup].des]){
                    dis[heap[cup].des]=dis[q[head]]+heap[cup].lth;
                    if (!inq[heap[cup].des]) {
                        tail=(tail+1)&1023;
                        q[tail]=heap[cup].des;
                        inq[heap[cup].des]=1;
                    };
                };
                cup=heap[cup].link;
          };
          inq[q[head]]=0;
    };
    for (i=1;i<=p;i++) sum+=cow[i]*dis[i];
    return sum;
};
 
void pmain(){
     int t,sl=1<<30;
     for (int i=1;i<=p;i++) {
         memset(dis,126,sizeof(dis));
         t=spfa(i);
         if (t<sl) sl=t;
     };
     printf("%d\n",sl);
};
 
int main(){
	while(scanf("%d",&p)==1){
   	memset(cow,0,sizeof(cow));
	memset(lc,0,sizeof(lc));
	memset(inq,0,sizeof(inq));
   	int t,u,ll,tmp,htop=0;
	for(i=1;i<=p;i++)
        scanf("%d",&cow[i]);
    for(i=1;i<p;i++){
        scanf("%d%d%d",&t,&u,&ll);
        tmp=lc[t];htop++;lc[t]=htop;
        heap[htop].link=tmp;heap[htop].des=u;heap[htop].lth=ll;
        tmp=lc[u];htop++;lc[u]=htop;
        heap[htop].link=tmp;heap[htop].des=t;heap[htop].lth=ll;
    };
	pmain();
    }
    return 0;
}
