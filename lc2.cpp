#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct nd{
       int id;
       int c;
       };
bool mycmp(nd n1,nd n2){
     return n1.c<=n2.c;
     }
int main(){
    int n;
    vector<nd> f;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            nd tm;
            cin>>tm.c;
            tm.id=i+1;
            f.push_back(tm);
            }
    sort(f.begin(),f.end(),mycmp);
    int dif=0,nowv;
    dif=1;
    nowv=f[0].c;
    for(int i=1;i<n;i++)
            if(f[i].c!=nowv){
                           dif++;
                           nowv=f[i].c;
                           }
    long long sum=0;
    for(int i=0;i<n;i++)sum+=f[i].c;
    if( dif==1 )
        cout<<"Exemplary pages."<<endl;
    if( dif >3 || (sum+0.0) / f.size()*f.size()!=sum)
        cout<<"Unrecoverable configuration."<<endl;
    if( dif == 3 || dif == 2)
        if(f[0].c+f[f.size()-1].c==2*sum / f.size() )
        cout<<f[1].c-f[0].c<<" ml. from cup #"<<f[0].id<<" to cup #"<<f[f.size()-1].id<<".\n"<<endl;
        else cout<<"Unrecoverable configuration."<<endl;
   cin>>n;
   return 0;
}
