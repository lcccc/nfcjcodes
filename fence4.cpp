/*

ID: lc757692
PROG: fence4
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("fence4.in");
ofstream fout("fence4.out");
 
/*
web:	http://www.n8lm.cn
This template code is writed by Alchemist.
*/
const double EP = 0.00000001;
const int LINE_SEG = 0xff;
const int LINE_SEG_INF = 0xff + 1;
template <class T = double>
class point
{
public:
	T x;
	T y;
	point()	{};
	point(T a,T b)
	{
		x = a;
		y = b;
	}
 
	point(const point<T>& a)
	{
		x = a.x;
		y = a.y;
	}
 
	point<T>& operator = (const point<T>& p)
	{
		x = p.x;
		y = p.y;
	}
 
	friend point<T> operator - (point<T>& p1, point<T>& p2)
    {
	    point<T> p(p1.x - p2.x, p1.y - p2.y);
	    return p;
    }
 
	friend T crossProduct(point<T> p1, point<T> p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
 
	friend T direction(point<T> p1, point<T> p2, point<T> pO)
	{
		return crossProduct(p1 - pO, p2 - pO);
	}
 
	friend bool operator == (point<T>& p1, point<T>& p2)
	{
		return (abs(p1.x - p2.x) < EP  && abs(p1.y - p2.y) < EP);
	}
 
	friend T dist(point<T> p1, point<T> p2)
	{
		return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	}
 
	friend istream& operator >> (istream& input, point<T>& p)
	{
		input >> p.x;
		input >> p.y;
		return input;
	}
 
	friend ostream& operator << (ostream& output, point<T>& p)
	{
		output << p.x << ' ' << p.y;
		return output;
	}
};
 
template <class T = double>
class line
{
public:
	point<T> A;
	point<T> B;
 
	line(){};
	line(const point<T>& a,const point<T>& b):A(a),B(b) {};
	line(T a, T b, T c, T d):A(a,b),B(c,d) {};
 
	void setPoints(point<T> a, point<T> b)
	{
		A = a;
		B = b;
	}
 
	T length()
	{
		return dist(A,B);
	}
 
	friend bool intersect(line<T>& P, line<T>& Q ,int intersect_way)
	{
		if(intersect_way == LINE_SEG)
		{
			if(
			(max(Q.A.x,Q.B.x)>=min(P.A.x,P.B.x))&&
			(max(P.A.x,P.B.x)>=min(Q.A.x,Q.B.x))&&
			(max(Q.A.y,Q.B.y)>=min(P.A.y,P.B.y))&&
			(max(P.A.y,P.B.y)>=min(Q.A.y,Q.B.y))&&
			(crossProduct(P.A - Q.A , Q.B - Q.A ) * crossProduct( Q.B - Q.A , P.B - Q.A ) >= 0) &&
			(crossProduct(Q.A - P.A , P.B - P.A ) * crossProduct( P.B - P.A , Q.B - P.A ) >= 0) &&
			!(P.A == Q.A) &&
			!(P.A == Q.B) &&
			!(P.B == Q.A) &&
			!(P.B == Q.B) 
			)
				return true;
			else
				return false;
		}
		else if(intersect_way == LINE_SEG_INF)
		{
			if(
			(crossProduct(P.A - Q.A , Q.B - Q.A ) * crossProduct( Q.B - Q.A , P.B - Q.A ) > 0) &&
			!(P.A == Q.A) &&
			!(P.A == Q.B) &&
			!(P.B == Q.A) &&
			!(P.B == Q.B) 
			)
				return true;
			else
				return false;
		}
		return false;
	}
 
	friend point<T> intersection(line<T>& P, line<T>& Q)
	{
		point<T> crossPoint;
		T tempLeft,tempRight;
 
		//求x坐标
		tempLeft = (Q.B.x - Q.A.x) * (P.A.y - P.B.y) - (P.B.x - P.A.x) * (Q.A.y - Q.B.y);
		tempRight = (P.A.y - Q.A.y) * (P.B.x - P.A.x) * (Q.B.x - Q.A.x) + Q.A.x * (Q.B.y - Q.A.y) * (P.B.x - P.A.x) - P.A.x * (P.B.y - P.A.y) * (Q.B.x - Q.A.x);
    	crossPoint.x = tempRight / tempLeft;
		//求y坐标
		tempLeft = (P.A.x - P.B.x) * (Q.B.y - Q.A.y) - (P.B.y - P.A.y) * (Q.A.x - Q.B.x);
		tempRight = P.B.y * (P.A.x - P.B.x) * (Q.B.y - Q.A.y) + (Q.B.x- P.B.x) * (Q.B.y - Q.A.y) * (P.A.y - P.B.y) - Q.B.y * (Q.A.x - Q.B.x) * (P.B.y - P.A.y);
		crossPoint.y = tempRight / tempLeft;
 
		return crossPoint;
	}
 
	friend ostream& operator << (ostream& output, line<T>& l)
	{
		output << l.A << ' ' << l.B; 
		return output;
	}
 
};
 
const int MaxP = 200 + 1;
 
struct OptArea
{
	int p;
	point<double> optl;
	line<double> nearest;
}optas[MaxP*2],optasL[MaxP*2];
 
line<double> lines[MaxP];
point<double> points[MaxP];
point<double> person;
int n,optaN,optaNL;
 
void init()
{
	int i,j,x,y;
	fin >> n;
	if(n < 2)
		return;
	fin >> person;
	fin >> points[0];
	for(i=1;i<n;i++)
	{
		fin >> points[i];
		lines[i-1].setPoints(points[i-1],points[i]);
	}
	lines[n-1].setPoints(points[0],points[n-1]);
}
 
int compL(const void* p,const void* q)
{
	if(direction(((OptArea*)p)->optl, ((OptArea*)q)->optl, person) > 0)
		return 1;
	else
		return -1;
}
 
int main()
{
	int i,j;
	init();
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(intersect(lines[i],lines[j],LINE_SEG))
			{
				fout << "NOFENCE" << endl;
				return 0;
			}
		}
	for(i=0;i<n;i++)
	{
		optasL[i].optl = points[i];
	}
	qsort(optasL,n,sizeof(OptArea),compL);
	optaN = 0;
	for(i=0;i<n-1;i++)
	{
		if(abs(direction(optasL[i].optl, optasL[i+1].optl, person)) < EP)
			continue;
		else
		{
			optas[optaN] = optasL[i];
			optas[optaN ++].p = -1;
		}
	}
	optas[optaN] = optasL[n-1];
	optas[optaN ++].p = -1;
	optas[optaN] = optas[0];
	optas[optaN ++].p = -1;
 
	for(i=0;i<n;i++)
	{
		int l,r;
		point<double> t;
		point<double> lA,lB;
		if(abs(direction(lines[i].A, lines[i].B, person)) < EP)
			continue;
		if(direction(lines[i].A, lines[i].B, person) > 0)
		{
			lA = lines[i].B;
			lB = lines[i].A;
		}
		else
		{
			lA = lines[i].A;
			lB = lines[i].B;
		}
		r = l = 0;
		for(j=0;j<optaN;j++)
			if(abs(direction(lA, optas[j].optl , person)) < EP && (dist(lA, optas[j%optaN].optl) < dist(lA, person) || dist(lA, optas[j%optaN].optl) < dist(optas[j%optaN].optl, person))){
				l = j;
				break;
			}
		for(j=l;j<optaN+l;j++)
			if(abs(direction(lB, optas[j%optaN].optl , person)) < EP && (dist(lB, optas[j%optaN].optl) < dist(lB, person) || dist(lB, optas[j%optaN].optl) < dist(optas[j%optaN].optl, person)))
			{
				r = j;
				break;
			}
		//fout << i << "--- " << lines[i] << "  :  " << l << ' ' << r << endl;
 
		for(j=l;j<r;j++)
		{
			point<double> p1,p2;
			line<double> l1,l2;
			l1.setPoints(person, optas[j%optaN].optl);
			l2.setPoints(person, optas[(j+1)%optaN].optl);
			p1 = intersection(lines[i], l1);
			p2 = intersection(lines[i], l2);
			if(optas[j%optaN].p == -1 || dist(optas[j%optaN].nearest.A , person) - dist(p1 , person) > EP ||  dist(optas[j%optaN].nearest.B , person) - dist(p2 , person) > EP )
			{
				optas[j%optaN].nearest.setPoints(p1,p2);
				optas[j%optaN].p = i;
			}
		}
	}
 
	bool isSee[MaxP] = {0};
	//fout << endl;
	for(i=0;i<optaN;i++)
	{
		//fout << optas[i].p << endl;
		if(optas[i].p >= 0)
			isSee[optas[i].p] = 1;
	}
	int ansN = 0;
	for(i=0;i<n;i++)
	{
		if(isSee[i])
			ansN ++;
	}
	fout << ansN <<endl;
	for(i=0;i<n-2;i++)
	{
		if(isSee[i])
			fout << lines[i] << endl;
	}
	if(isSee[n-2] && isSee[n-1])
	{
		fout << lines[n-1] << endl;
		fout << lines[n-2] << endl;
	}
	else
	{
		if(isSee[n-2])
			fout << lines[n-2] << endl;
		else if(isSee[n-1])
			fout << lines[n-1] << endl;
	}
	return 0;
}
