#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int cs;
    cin>>cs;
    for(int Cs=1; Cs<=cs; Cs++)
    {
        int n;
        vector<int> f;
        int min=10000000,sum=0,xr;
        cin>>n;
        f.clear();
        for(int i=0; i<n; i++)
        {
            int tm;
            cin>>tm;
            if(tm<min)min=tm;
            f.push_back(tm);
            sum+=tm;
            cout<<"sum is "<<sum<<endl;
            if(i==0)xr=tm;
            else xr=tm xor xr;
        }
        cout<<"min is "<<min<<endl;
        cout<<"sum is "<<sum<<endl;
        if(xr!=0)
        {
            cout<<"Case #"<<Cs<<": NO"<<endl;
        }
        else
        {
            cout<<"Case #"<<Cs<<": "<<sum-min<<endl;
        }
    }
}
