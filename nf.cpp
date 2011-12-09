#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
int n;
vector<int> a;
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
	int t,Case=1;
	cin>>t;
	while(t--){
	    a.clear();
		cin>>n;
		int tm;
		for(int i=0;i<n;i++)
		{
			cin>>tm;
			a.push_back(tm);
		}
		tm=a[0];
		for(int i=1;i<n;i++)
			tm=tm ^ a[i];
		if(tm){
			cout<<"Case #"<<Case++<<": NO"<<endl;
		}
		else{
			sort(a.begin(),a.end());
			cout<<"min"<<a[0]<<endl;
			int sum=0;
			for(int i=1;i<n;i++)
				sum+=a[i];
			cout<<"Case #"<<Case++<<": "<<sum<<endl;
		}
	}
}

