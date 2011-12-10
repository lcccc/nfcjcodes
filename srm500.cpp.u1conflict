#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class MathContest{
public:
vector<int> st;
int countBlack(string ballSequence,int repetitioins){
for(int j=0;j<repetitioins;j++)
    for(int i=0;i<ballSequence.size();i++)
    if(ballSequence[i]=='B')st.push_back(1);
    else st.push_back(0);
    //for(int i=0;i<st.size();i++)cout<<st[i];cout<<endl;
    reverse(st.begin(),st.end());
//for(int i=0;i<st.size();i++)cout<<st[i];cout<<endl;
int shownum=0,num=ballSequence.size()*repetitioins;
for(int i=st.size()-1;i>=0;i--){
    if(st[i]==1){
    shownum++;
    //cout<<"shownum"<<shownum<<endl;
    st.erase(st.end()-1);
    inver();
    //for(int i=0;i<st.size();i++)cout<<st[i];cout<<endl;
    }
    else {
    st.erase(st.end()-1);
    reser();
   // for(int i=0;i<st.size();i++)cout<<st[i];cout<<endl;
    }
}
return shownum;
}
void reser(){
reverse(st.begin(),st.end());
}
void inver(){
for(int i=0;i<st.size();i++)
st[i]=1-st[i];
}
};

main(){
MathContest mc;
cout<<mc.countBlack("bbwwb",2);
}
