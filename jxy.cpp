#include <stdio.h>
main (void)
struct student 
{
	int id;
	char name[20];
	int chineseScore;
	int mathScore;
	int englishScore;
	int computerScore;	
} 

void sort(student stu[],int index)
{
	int i;
	int j;
	int sum[4];
	student temp;
	for (i = 0;i < 5;i++)
	{
		sum[i] = stu[i].chinese Score+stu[i].computerScore+stu[i].englishScore+stu[i].mathScore;
	}
	for (i = 0;i < 4;i++)
	{
		for(j = i;j < 4;j++)
		{
			if(sum[j]<sum[j+1])
			{
				temp = stu[j];
				stu[j+1] = stu[j];
				stu[j] = temp;
			}
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	int choice;
	char submit;
	int index = 0;
	int findchoice;
	char findname[20];
	char course[20];
	int findindex;
	char coursename[20];
	int chinesesum;
	int chinesemax;
	int chinesemin;
	int mathsum;
	int mathmax;
	int mathmin;
	int englishsum;
	int englishmax;
	int englishmin;
	int computersum;
	int computermax;
	int computermin ;
	while(true)
	{
		struct student stu[5];
		printf("\n*******************************\n");
		printf("        ѧ���ɼ�����ϵͳ       \n");
		printf("*******************************\n");
		printf("      ��1������ѧ���ɼ�      \n ");
		printf("      ��2����ѯѧ���ɼ�       \n");
		printf("      ��3���޸�ѧ���ɼ�       \n");
		printf("      ��4�����ѧ���ɼ�       \n");
		printf("      ��5) �˳�ϵͳ            \n");
		printf("������ѡ��1,2,3,4,5����\n");
		scanf("%d",&choice);
		while(true)
		{
			if (choice == 1){
				printf("*************************");
				printf("\nѧ��:");scanf("%d",&stu[index].id);
				printf("\n����:");scanf("%s",stu[index].name);
				printf("\nӢ��:");scanf("%d",&stu[index].englishScore);
				printf("\n�����:");scanf("%d",&stu[index].computerScore);
				printf("\n����:");scanf("%d",&stu[index].chineseScore);
				printf("\n��ѧ:");scanf("%d",&stu[index].mathScore);
				printf("\n�Ƿ��������Y/N��:");
				scanf("%c",&submit);
				index++;
				if(submit == 'Y')
				{
					choice = 1;
					continue;
				}
				else 
				{
					break;
				}
			}
		
			else if(choice == 2)
			{
				printf("��ѯһ��Ŷ�ף�\n");
				printf("(1)��������ѯ  \n");
				printf("(2)���γ̲�ѯ\n");
				printf("(3)���ܷ����β�ѯ\n");
				printf("1 or 2 or 3:");
				scanf("%d",&findchoice);
				switch(findchoice)
				{
				case 1:
					printf("name:");
					scanf("%s",findname);
					for (findindex = 0;findindex < index;findindex++)
					{
						if(stu[findindex].name == findname)
						{
							printf("%d\n",stu[findindex].id);	 
						}
					}
					break;
				case 2:
					printf("coursename:");
					scanf("%s",coursename);
					if(coursename == "Ӣ��")
					{
						englishsum = 0;
						englishmax = 0;
						englishmin = stu[0].computerScore;
						for (findindex = 0;findindex <index;findindex++)
						{
							
							if (stu[findindex].englishScore<englishmin){englishmin = stu[findindex].englishScore;}
							if(stu[findindex].englishScore>englishmax){englishmax = stu[findindex].englishScore;}
							printf("%d",stu[findindex].englishScore);
							englishsum += stu[findindex].englishScore;
							
						}
						printf("the max score is: %d",englishmax);
						printf("the min score is: %d",englishmin);
						printf("the average score is: %d",englishsum/index);
						
						
						}
					 else if coursename == "����")
					{
						chinesesum = 0;
						chinesemax = 0;
						chinesemin = stu[0].computerScore;
						for (findindex = 0;findindex <index;findindex++)
						{
							
							if (stu[findindex].chineseScore<chinesemin){chinesemin = stu[findindex].chineseScore;}
							if(stu[findindex].chineseScore>chinesemax){chinesemax = stu[findindex].chineseScore;}
							printf("%d",stu[findindex].chineseScore);
							chinesesum += stu[findindex].chineseScore;
							
						}
						printf("the max score is: %d",chinesemax);
						printf("the min score is: %d",chinesemin);
						printf("the average score is: %d",chinesesum/index);
						
						 
					else if coursename == " ��ѧ")
					{
						mathsum = 0;
						mathmax = 0;
						mathmin = stu[0].computerScore;
						for (findindex = 0;findindex <index;findindex++)
						{
							
							if (stu[findindex].mathScore<mathmin){mathmin = stu[findindex].mathScore;}
							if(stu[findindex].mathScore>mathmax){mathmax = stu[findindex].mathScore;}
							printf("%d",stu[findindex].mathScore);
							mathsum += stu[findindex].mathScore;
							
						}
						printf("the max score is: %d",mathmax);
						printf("the min score is: %d",mathmin);
						printf("the average score is: %d",mathsum/index);
						
						
					else if coursename == " �����")
					{
						 computersum = 0;
						 computermax = 0;
						 computermin = stu[0].computerScore;
						for (findindex = 0;findindex <index;findindex++)
						{
							
							if (stu[findindex]. computerScore< computermin){ computermin = stu[findindex]. computerScore;}
							if(stu[findindex]. computerScore> computermax){ computermax = stu[findindex]. computerScore;}
							printf("%d",stu[findindex]. computerScore);
							 computersum += stu[findindex]. computerScore;
							
						}
						printf("the max score is: %d", computermax);
						printf("the min score is: %d", computermin);
						printf("the average score is: %d", computersum/index);
						
						 
					else printf("No Match Course!");
					*/
							break;a
						case 3:
							sort(stu,index);
							for (findindex = 0;findindex < index;findindex++)
							{
								printf("%d\n",stu[findindex].id);
							}
							break;
					
					}
				
		}
				else if(choice == 4) {
					int chineseaverage;
					int mathaverage;
					int englishaverage;
					int computeraverage;
					
					printf(" \n");
					 
							for (findindex = 0;findindex <index;findindex++)
						{
							
							if (stu[findindex].englishScore<englishmin){englishmin = stu[findindex].englishScore;}
							if(stu[findindex].englishScore>englishmax){englishmax = stu[findindex].englishScore;}
							printf("%d",stu[findindex].englishScore);
							englishsum += stu[findindex].englishScore;
							.........you know ,repeat fout times!
						}
					*/
					printf("ѧ��   ����   ����  ��ѧ  Ӣ��   �����   �ܷ�����");
					int order = 1;
					for (findindex = 0;findindex < index;findindex++)
					{
						printf("%6d%s%6d%6d%6d%6d order++",stu[findindex].id,stu[findindex].name,stu[findindex].chineseScore,stu[findindex].mathScore,stu[findindex].englishScore,stu[findindex].computerScore);
					}
					 
					break;
				}		
		}		
		continue;
	}
	return 0;
}

