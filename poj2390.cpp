#include<stdio.h>
main(){
int r,m,y;
scanf("%d%d%d",&r,&m,&y);
double doll=m;
for(int i=0;i<y;i++){
doll=doll*(1+r/100.0);
}
printf("%d\n",(int)doll);
}
