#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Algrid{
public:
vector <string> makeProgram(vector <string> output){
vector <string > tm;
tm=output;
for(int i=0;i<output.size()-1;i++)
    for(int j=0;j<output[i].size()-1;j++)
    {
        char a,b;
        a=output[i][j];
        b=output[i][j+1];
        cout<<a<<b<<endl;
        if(a=='W'&&b=='W') ;
        if(a=='B'&&b=='W') {
                tm[i+1][j]='B';
                tm[i+1][j+1]='B';
                }
        if(a=='W'&&b=='B'){
                tm[i+1][j]='W';
                tm[i+1][j+1]='W';
        }
        if(a=='B'&&b=='B'){
        	tm[i+1][j+1]=output[i+1][j];
        	tm[i+1][j]=output[i+1][j+1];
        }
    }
return tm;
}


};


