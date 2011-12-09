#include<stdio.h>
int main(){
 int m,ch[100],j;
    double t;
 while(scanf("%d",&m)!=EOF){
 for(j=0;j<m;j++)
  scanf("%d",&ch[j]);
 for(j=0;j<m;j++){
  int i,a=0,s=-1;
  double sum=0;
 for(i=0;i<ch[j];i++){
  a=a+1;
  s=(-1)*s;
  t=(1.00/a)*s;
  sum=sum+t;
 }
 printf("%.2f\n",sum);
 }
}
}
