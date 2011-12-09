#include<stdio.h>
int main(){
    int s,d,ans;
    while(scanf("%d%d",&s,&d)!=EOF){
        if(s-4*d>0)ans=-1;//无论如何都亏
        else if(4*s-d<=0)ans=10*s-2*d;//即： ssssd,ssssd,ss
        else if(3*s-2*d<=0)ans=8*s-4*d;//即：sssdd,sssdd,ss
        else if(2*s-3*d<=0)ans=6*s-6*d;//即：ssddd,ssddd,ss
        else if(s-4*d<=0)ans=3*s-9*d;//即：  sdddd,sdddd,sd
        else ans=-1;//亏
        if(ans<0)puts("Deficit");
        else printf("%d\n",ans);
    }
    return 0;
}
