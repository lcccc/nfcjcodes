#include <iostream>
using namespace std;
	int enable[15];
	int k = 15;				//enable�ĸ���
	int SG[1001];		//���SGֵ
	int SG_value(int n)			//��SGֵ
	{
		int i,temp;
		int judge[16]={0};		//����Ѱ����С��SGֵ�����
		for(i=0;i<k;i++)
		{
			temp = n - enable[i];
			if(temp<0)
				break;
			if(SG[temp]==-1)	//Ѱ����С��SG��
				SG[temp]=SG_value(temp);
			judge[SG[temp]]=1;	//Ϊ��̵���ϱ��
		}
		for(i=0;;i++)			//�ҵ�ÿһ��SG��i�ݵ���СSGֵ
		{
			if(judge[i]==0)
				return i;
		}
	}
int main()
{
	int m,i,j,l,n,t,p;
	enable[0] = 1;
	enable[1] = 2;
	for (i=2;i<15;i++)
	{
		enable[i] = enable[i-1] + enable[i-2];
	}
	int s;
	while (scanf("%d %d %d",&m,&n,&p)!=EOF)
	{
		memset(SG,-1,sizeof(SG));//��ʼ��
		if (m == 0 && n == 0 && p == 0)
		{
			break;
		}
		s = SG_value(n)^SG_value(m)^SG_value(p);
		if (s == 0)
		{
			printf("Nacci/n");
		}
		else
			printf("Fibo/n");
	}
	return 0;
}

