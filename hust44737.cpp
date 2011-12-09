#include<iostream>
#include<vector>
using namespace std;
main(){
       int cs,n;
       cin>>cs;
       vector<int> f;
       for(int i=0;i<cs;i++)
       {
               cin>>n;
               for(int i=0;i<n;i++)
               {
        int tm;
        cin>>tm;
        f.push_back(tm);
        }
        int ans = 0;
        for(int i= 0;i<f.size()-1;i++)
        {
                                      int min = 100000,k = i;
                                      for(int j = i+1; j <f.size(); j++)
                                      if( f[j] < min )
                                      {
                                          min = f[j];
                                          k = j;
                                      }
        if(  k != i)
        {
             cout<<k<<endl;
             ans ++;
             swap(f[k],f[i]);
        }
        }
        cout<<ans<<endl;
        }
}
               
