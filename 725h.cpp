/*
 * Author: Nfcj
 * Created Time:  2011年07月25日 星期一 15时26分56秒
 * File Name: 725h.cpp
 */
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

long long n;
typedef pair<long long,bool> llb;
map<llb, long long> record;

long long solve(long long a,bool three)
{
        if(a<10) return a-(a>=3&&three?1:0);
        
         long long t=a,x=1;
        while(t>=10)
         {
                 x*=10;
                 t/=10;
         }

        if(record.find(llb(a, three)) != record.end())
                return record[llb(a, three)];
         record[llb(a, three)] = 0;
         long long &rt = record[llb(a, three)];

        if(x==a)return (rt=1+solve(x-1,false));

        if(!three)
         {
              if(a/x == 1) return rt=solve(x,false) + solve(a%x, (a % x) > (x/10));
                else return rt =(a/x-1) * solve(x,false) + solve(a%x,false)+solve(x-1,true)+1;
         }
        else
         {
		if(a/x==3) return (rt=solve(x*3-1,false));
                if(a/x>3) return rt =solve(a-x,false);
                else return rt = solve(a,false);  
         }
}

int main()
{
        int t;
         cin>>t;
        while(t--)
         {
                 cin>>n;
                
                 long long down=1,up=2000000000000000000;
                while(down<up)
                 {
                         long long mid=(down+up)/2;
                         long long tmp=solve(mid,false);
                        if(tmp<n) down=mid + 1;
                        else if(tmp>n) up=mid-1;
                        else up=mid;
                 }
                 cout<<up<<endl;
         }
        return 0;
}
