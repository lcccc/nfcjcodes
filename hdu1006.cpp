/*
 * ID: lc757692
 * LANG:C++
 * TASK:
 * Created Time:  2011/8/15 23:41:40
 * File Name: hdu1006.cpp
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
double angs(int m);
double angm(int m);
double angh(int m);
int main() {
    int d;
    while(scanf("%d",&d)!=EOF)
    {
        if(d == -1) break;
        double ag[3];
        int timehappy = 0;
        for(int i = 0;i<60*60*24;i++)
        {
            ag[0] = angs(i);
            ag[1] = angm(i);
            ag[2] = angh(i);
            sort(ag,ag+3);
            if(ag[1]-ag[0] >= d && ag[1]-ag[0] <=360.0-d &&
               ag[2]-ag[1] >= d && ag[2]-ag[1] <= 360.0-d &&
               ag[0]-ag[2]+360 >= d && ag[0] - ag[2] <= d)
               //cout<<i<<' '<<angs(i)<<' '<<angm(i)<<' '<<angh(i)<<endl,getchar(), timehappy++;
        timehappy++;
        }
        //cout<<(timehappy+0.0)/(24*36)<<endl;
        printf("%.3f",(timehappy+0.0)/(24*36));
    }
    return 0;
}
double angs(int m)
{
    m %=60;
    return m/60.0*360;
}
double angm(int m)
{
    m %=3600;
    return m/3600.0*360;
}
double angh(int m)
{
    return m/(3600*24.0)*360;
}
