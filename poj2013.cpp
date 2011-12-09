#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
main()
{
    int cs=1,n;
    while(cin>>n)
    {
        if(n==0)break;
        vector<string> f;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            f.push_back(s);
        }
        int i;
        cout<<"SET "<<cs++<<endl;
        for( i=0; i<f.size(); i+=2)
        {
            cout<<f[i]<<endl;
            f[i]="";
        }
        for(int i=f.size()-1; i>0; i--)
        {
            if(f[i]!="")cout<<f[i]<<endl;
        }
    }
    return  0;
}
