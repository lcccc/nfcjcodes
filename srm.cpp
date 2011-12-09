#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;
class ComparerInator{
public:
int makeProgram(vector<int> a,vector<int>b,vector<int> wanted){
    int b=1;
    for(int i=0;i<a.size();i++)
    if(a[i]!=wanted[i]){b=0;break;}
    if(b==1){
    return 1;
    }
    b=1;
    for(int i=0;i<a.size();i++)
    if(b[i]!=wanted[i]){b=0;break;}
    if(b){return 1;
    }
    for(int i=0;i<a.size();i++)
    if(wanted[i]!=min(a[i],b[i])){b=0;break;}
    if(b)return 7;
    for(int i=0;i<a.size();i++)
    if(wanted[i]!=max(a[i],b[i])){b=0;break;}
    if(b)return 7;
    return -1;
}
};
