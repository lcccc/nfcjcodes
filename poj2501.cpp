#include<cstdio>
#include<cstring>

main(){
double ss=0;
int tpre=0,tnow=0,vpre=0,vnow=0;
char cin[100];
int h,m,s;
while(gets(cin)){
    if(strstr(cin," ")==NULL){
        //puts(cin);
        sscanf(cin,"%d:%d:%d",&h,&m,&s);
        tnow=h*3600+m*60+s;
        //printf("vpre %d vnow %d tpre %d tnow %d\n",vpre,vnow,tpre,tnow);
        printf("%s %.2f km\n",cin,(ss+(tnow-tpre)/3600.0*vnow));
    }
    else
    {
        sscanf(cin,"%d:%d:%d %d",&h,&m,&s,&vnow);
       // printf("%d",s);
        tnow=h*3600+m*60+s;
        ss+=(tnow-tpre)/3600.0*vpre;
        vpre=vnow;
        tpre=tnow;
        ///printf("vpre %d vnow %d tpre %d tnow %d\n",vpre,vnow,tpre,tnow);
    }

}
}
