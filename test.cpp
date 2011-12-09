#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class MagicalGirlLevelOneDivTwo{
public:
double theMinDistance(int d,int x,int y)
{
		int px,py;
		double len = 250005.;
		for(px = -500;px<=500;px++)
		  for(py = -500;py<=500;py++)
		  if( abs(px-x) <=d && abs(py-y) <= d)
		  {
		  		if( sqrt(px*px + py*py) < len)
		  		  len = sqrt(px*px + py*py);
		  		  }
	return len;
	}
	};
int main()
{
}
