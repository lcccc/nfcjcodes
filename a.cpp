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
        
