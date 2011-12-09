#include<iostream>
using namespace std;
main(){
       int f[1000002];
       int n,b,g,min,max,maxwork,maxfree;
       cin>>n;
       min=INT_MAX;
       max=INT_MIN;
       maxwork=0;
       maxfree=0;
       for(int i=0;i<n;i++){
               cin>>b>>g;
               for(int j=b+1;j<=g;j++)
                       f[j]=1;
               if(b<min)min=b;
               if(g>max)max=g;
               }
               int t=0;
       for(int i=min;i<=max;i++){
               if(f[i]){
                        t++;
                        }
               else {
                    if(t>maxwork)maxwork=t;
                    t=0;
                    }
                    }
               t=0;
       for(int i=min;i<=max;i++){
               if(f[i]==0){
                           t++;
                           }
               else {
                    if(t>maxfree)maxfree=t;
                    t=0;
                    }
                    }
       cout<<maxwork<<' '<<maxfree<<endl;
       return 1;
       }
       
                           
