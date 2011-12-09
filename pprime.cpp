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
