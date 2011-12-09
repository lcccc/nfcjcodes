/*
ID:lc757692
TASK:contact
LANG:C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#define LENGTH 200000
#define MAX 8192

using namespace std;

int a,b,n;

int tree[MAX];
char letter[LENGTH];
int length = 0;
ifstream fin("contact.in");
ofstream fout("contact.out");

void contact(int index,int layer,int position)
{
	if (layer > b || index >= length)
	{
		return;
	}
	else
	{
		if (letter[index] == '0')
		{
			position = position * 2 + 1;
		}
		else
		{
			position = position * 2 + 2;
		}
		if (layer >= a)
		{
			tree[position] ++;
		}//在范围内
		contact(index+1,layer+1,position);
	}
}

//打印结果
void printResult(int num)
{
	int l = 0;
	int result[12];
	while (num != 1)
	{
		if ((num&1) == 1)
		{
			result[l] = 1;
		}
		else
		{
			result[l] = 0;
		}
		l ++;
		num = num >> 1;
	}

	for (int i =l-1; i >=0; i --)
	{
		fout << result[i];
	}
}

int main()
{
	fin >> a >> b >> n;
	while (!fin.eof())
	{
		fin >> letter[length];
		length ++;
	}

	length --;
	
	//遍历数组
	for (int i=0; i < length; i ++)
	{
		contact(i,1,0);
	}

	//打印结果
	int pl = pow((double)2,b+1) -1;
	int start = pow((double)2,a) -1;

	for (int i = 0; i < n; i ++ )
	{
		int max = 0;
		for (int j = start; j < pl; j ++)
		{
			if (max < tree[j])
			{
				max = tree[j];
			}//end if 
		}
		if (max == 0)
		{
			return 0;
		}
		fout << max;

		int number = 0;
		for (int k=start; k < pl; k ++)
		{
			if (tree[k] == max)
			{
				if (number%6 == 0)
				{
					fout << endl;
				}
				else
					fout<<" ";
				printResult(k+1);
				number ++;
				tree[k] = -1;
			}			
		}
		fout << endl;
	}
	return 0;
}
