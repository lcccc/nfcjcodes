/*
 * Team : FreePascal
 * Created Time:  2011年08月12日 星期五 12时59分41秒
 * File Name: 812a.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
#define SZ(v) ((int)(v).size())

const double eps = 1e-9;
struct point{
    double x,y;
}a,b,c;
int sgn(double x)
{
    return (x>eps) ? 1 : ( x<-eps ? -1:0);
}

double dis(point a,point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point fermentpoint1(point a,point b,point c){
    point u,v;
    double step = fabs(a.x) + fabs(a.y) + fabs(b.x) + fabs(b.y) + fabs(c.x) + fabs(c.y);
        //u.x = (a.x * p + b.x * q + c.x * r) / (p + q + r);
        //u.y = (a.y * p + b.y * q + c.y * r) / (p + q + r);
    u.x = (a.x + b.x + c.x) / 3;
    u.y = (a.y + b.y + c.y) / 3;
    while (step > 1e-12)
        for (int k = 0; k < 30; step /= 2,k++)
            for (int i = -1; i < 1; i++)
                for (int j = -1; j <= 1; j++){
                    v.x = u.x + step * i;
                    v.y = u.y + step * j;
                    double dua,dub,duc,dva,dvb,dvc;
                    dua = dis(u,a); dub = dis(u,b); duc = dis(u,c);
                    dva = dis(v,a); dvb = dis(v,b); dvc = dis(v,c);
/*
                        double maxu,maxv;
                        maxu = max(dua,max(dub,duc));
                        maxv = max(dva,max(dvb,dvc));
                        if (2 * (dua + dub + duc) - maxu > 2 * (dva + dvb + dvc) - maxv) u = v;
*/
                    if (dua + dub + duc > dva + dvb + dvc) u = v;
                }
    return u;
}





point fermentpoint(point a,point b,point c){
    point u,v;
    double step = (fabs(a.x) + fabs(a.y) + fabs(b.x) + fabs(b.y) + fabs(c.x) + fabs(c.y))*100;
    //double step = 2 * (fabs(a.x) + fabs(a.y)) + fabs(b.x) + fabs(b.y) + fabs(c.x) + fabs(c.y);
    int cnt = 0;
    while (true){
        cnt++;
        int p,q,r;
        p = rand() % 100; q = rand() % 100; r = rand() % 100;
        if (p + q + r == 0) continue;
        u.x = (a.x * p + b.x * q + c.x * r) / (p + q + r);
        u.y = (a.y * p + b.y * q + c.y * r) / (p + q + r);
        //u.x = (a.x * 2 + b.x + c.x) / 4;
        //u.y = (a.y * 2 + b.y + c.y) / 4;
        //u = fermentpoint1(a,b,c);
        if (cnt > 100000) break;
        while (step > 1e-25)
            for (int k = 0; k < 100; step /= 2,k++)
                for (int i = -1; i < 1; i++)
                    for (int j = -1; j <= 1; j++){
                        v.x = u.x + step * i;
                        v.y = u.y + step * j;
                        double dua,dub,duc,dva,dvb,dvc;
                        dua = dis(u,a); dub = dis(u,b); duc = dis(u,c);
                        dva = dis(v,a); dvb = dis(v,b); dvc = dis(v,c);
/*
                        double maxu,maxv;
                        maxu = max(dua,max(dub,duc));
                        maxv = max(dva,max(dvb,dvc));
                        if (2 * (dua + dub + duc) - maxu > 2 * (dva + dvb + dvc) - maxv) u = v;
*/
                        if (2 * (dua + dub + duc) - dua > 2 * (dva + dvb + dvc) - dva) u = v;
                    }
        //return u;
    }
    return u;
}
int main() {
    int cs = 0;
    while (scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y) != EOF){
        if (sgn(a.x + 1) == 0 && sgn(a.y + 1) == 0 && sgn(b.x + 1) == 0 && sgn(b.y + 1) == 0 && sgn(c.x + 1) == 0 && sgn(c.y + 1) == 0) break;
        srand(time(0));
        printf("Case %d: ",++cs);
        double da,db,dc; point u;
        u = fermentpoint(a,b,c);
        da = dis(u,a); db = dis(u,b); dc = dis(u,c);
        double ans = 2 * (da + db + dc) - max(da,max(db,dc));
        u = fermentpoint(b,c,a);
        da = dis(u,a); db = dis(u,b); dc = dis(u,c);
        ans = min(ans,2 * (da + db + dc) - max(da,max(db,dc)));
        u = fermentpoint(c,a,b);
        da = dis(u,a); db = dis(u,b); dc = dis(u,c);
        ans = min(ans,2 * (da + db + dc) - max(da,max(db,dc)));
        printf("%.8lf\n",ans);
    }
    return 0;
}

