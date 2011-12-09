<<<<<<< HEAD
/*
ID:lc757692
TASK:pprime
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define SZ(v) ((int)(v).size())
bool ispm(int x){
    if(x<2)return false;
    for(int i=2;i<=(int)sqrt(x);i++)
        if(x % i ==0)
            return false;
    return true;
}
int main() {
    int a,b;
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");
    cin>>a>>b;
    for(int a1=0;a1<10;a1++)
            if(a1>=a&&a1<=b&&ispm(a1))cout<<a1<<endl;
    if(a<=11&&b>=11)
            cout<<11<<endl;
        for(int a1=1;a1<10;a1+=2)
            for(int a2=0;a2<10;a2++)
            {
                int tm=a1*100+a2*10+a1;
                if(tm>=a&&tm<=b&&ispm(tm))
                    cout<<tm<<endl;
            }
    
        for(int a1=1;a1<10;a1+=2)
            for(int a2=0;a2<10;a2++)
                for(int a3=0;a3<10;a3++)
                {
                    int tm=a1*10000+a2*1000+a3*100+a2*10+a1;
                    if(tm>=a&&tm<=b&&ispm(tm))
                        cout<<tm<<endl;
                }
         for(int a1=1;a1<10;a1+=2)
            for(int a2=0;a2<10;a2++)
                for(int a3=0;a3<10;a3++)
                    for(int a4=0;a4<10;a4++)
                {
                    int tm=a1*1000000+a2*100000+a3*10000+a4*1000+a3*100+a2*10+a1;
                    if(tm>=a&&tm<=b&&ispm(tm))
                        cout<<tm<<endl;
                }
    return 0;
}


=======
#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
using namespace std;
bool ishw(int x){
     string s;
     if(x==2)return 1;
     else {
          if(x%10==2)return 0;
     while(x>0){
                s+=char(x%10+int('0'));
                x/=10;
                }
    // cout<<"s  "<<s<<endl;
     int b,e;
     b=0;e=s.size()-1;
     
     while(s[b]==s[e]){
                       b++;
                       e--;
                       }
     if(e<=b)return true;
     else return false;
     }
     }
bool ispm(int x){
     //int b=1;
     for(int i=2;i<=(int)sqrt(x);i++)
             if(x%i==0)return false;
     return true;
     }
main(){
       ifstream cin("pprime.in");
       ofstream cout("pprime.out");
       int a,b;
       cin>>a>>b;
       for(int i=a;i<=b;i++)
       {
               if(ishw(i)&&ispm(i))
               cout<<i<<endl;
               }
               system("pause");
               }
>>>>>>> 9b0a3453e70ac5912d1f39dd7564411a287657dd
