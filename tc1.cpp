#include<string>
#include<algorithm>
using namespace std;
class Chivalry {
public:
	string getOrder(string first,string second)
	{
	string ans;
	while(!first.size() && !second.size())
	{
		if(first[0] == 'w' || first[0] == 'm' && second[0] == 'm'){
		ans+=first[0];
		first.erase(first.begin(),first.begin()+1);
		continue;
		}
		if( first[0] =='m' && second[0] == 'w')
		{
			ans+=second[0];
			second.erase(second.begin(),second.begin()+1);
			continue;
			}
			}
		ans+=first+second;
		return ans;
		}
};

