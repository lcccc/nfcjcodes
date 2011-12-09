#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
main(){
       int n,d,cs=1;
       while(1){
                cin>>n>>d;
                if(n==0&&d==0)
                break;
                int x[1001],y[1001];
                double l[1000],r[1000];
                for(int i=1;i<=n;i++){
                        cin>>x[i]>>y[i];
                        l[i]=x[i]-sqrt(d*d-y[i]*y[i]);
                        r[i]=x[i]+sqrt(d*d-y[i]*y[i]);
                        }
       for(int i=1;i<n;i++)
               for(int j=i+1;j<=n;j++){
                       if(l[i]>l[j]){
                                     double tm=l[i];l[i]=l[j];l[j]=tm;
                                     tm=r[i];r[i]=r[j];r[j]=tm;
                                     }
                                     }
       double left=l[1],right=r[1],ans=1;
           for(int i=2;i<=n;i++){
                   if(l[i]<=right)
                                   left=l[i];
                    if(r[i]<=right)
                                    right=r[i];
                   if(l[i]>right){
                                  ans++;
                                  left=l[i];
                                  right=r[i];
                                  }
           }
           for(int i=1;i<=n;i++)
                    if(y[i]-d>0){
                             ans=-1;
                             break;
                        }
       cout<<"Case "<<cs<<": "<<ans<<endl;
       cs++;
       }
       return 0;
}


