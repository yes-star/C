// ����˹����.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*���¶���˹�����Ϊ19�֣�����*1������2�У���Z��*4����Z��*4����7��*4����7��*4��T�ַ���*4*/
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#include "conio.h"
#include "time.h"
#define FrameX 13//��Ϸ��������x������Ϊ13
#define FrameY 3//��Ϸ��������y������Ϊ3
#define Frame_H 20//��Ϸ���ڸ�Ϊ20
#define Frame_W 18 //��Ϸ���ڿ�Ϊ18

int i,j,temp,temp1,temp2;
int a[80][80]={0}; 
int b[4];                   //���4��С���飬0��ʾ�޷��飬1δ�з���

struct russia               //����˹����ṹ��
{
	int x,y;                /*����˹��������ķ���x��y������*/
	int flag;               /*�������͵ı��*/  
	int next;               /*��һ������ı��*/
	int speed;              /*�����½��ٶ�*/
	int number;             /*��������ĸ���*/
	int score;              /*��Ϸ�ۼƵ÷�*/
	int level;              /*��Ϸ�ȼ����Ѷȣ�*/
};
HANDLE hOut;


int ifMove(struct russia *);       //�жϷ����Ƿ�����ƶ�(46)
void clean(struct russia *);       //������� (99)
void Replay(struct russia *);      //���¿�ʼ��Ϸ(164)
void close();                      //�˳���Ϸ(172)
void UI();                         //��Ϸ���棨177��
void welcome();                    //��Ϸ��ӭ����(179)
void MakeRussia(struct russia *);  //�������飨235��
void Flag(struct russia *);        //�������һ��������ţ�395��
void Gameplay();                   //��ʼ��Ϸ(406)
void DrawRussia(struct russia *);  //��ӡ���飨566)
void DelFullLine(struct russia *); //�ж��Ƿ����У�Ȼ���������(602)
int color (int a);                 //��ɫ������650��
void toxy(int x,int y);            //����ƶ���ָ��λ�ã�654��
void title();                      //��ӭ�������(664)

int ifMove(struct russia *Russia)  //�жϷ����Ƿ�����ƶ�
{
	if(a[Russia->x][Russia->y]!=0)         //�ж����ķ��鲻Ϊ0�����з�����߽߱�
	{
		return 0;                          //����0�򲻿��ƶ�
	}
	else
	{
		if(
			(Russia->flag==1&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x+2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||          //�ж����ַ�������ķ����⣬��������λ���Ƿ����ͼ���������򷵻�1�������ƶ�

			(Russia->flag==2&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0&&a[Russia->x+4][Russia->y]==0))||            //ֱ�߷��飨�ᣩ

			(Russia->flag==3&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y-2]==0&&a[Russia->x][Russia->y+1]==0))||            //ֱ�߷��飨����

			(Russia->flag==4&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0&&a[Russia->x][Russia->y+1]==0))||            //4��5��6��7T�ַ��鼰�����

			(Russia->flag==5&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y]==0))||

			(Russia->flag==6&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==7&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==8&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y+1]==0))||          //8��9ΪZ�ַ��飨����

			(Russia->flag==9&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y+1]==0))||

			(Russia->flag==10&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||         //10��11ΪZ�ַ��飨��ת��

			(Russia->flag==11&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0))||

			(Russia->flag==12&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y-1]==0))||         //12~15Ϊ7�ַ��鼰�����

			(Russia->flag==13&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==14&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x+2][Russia->y+1]==0))||

			(Russia->flag==15&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==16&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x][Russia->y-1]==0&&a[Russia->x+2][Russia->y-1]==0))||         //16~19Ϊ��ת��7�ַ��鼰�����

			(Russia->flag==17&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==18&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y+1]==0))||

			(Russia->flag==19&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0)))
		{
			return 1;
		}
	}
	return 0;
}

void clean(struct russia *Russia)                 //�������˹�������µĺۼ�
{
	for(i=0;i<4;i++)                              //b[i]���һ������˹�����4��С����
	{
		b[i]=0;                                   //����Ϊ�޷���
	}
	MakeRussia(Russia);                           //��������
	for(i=Russia->x-2;i<=Russia->x+4;i+=2)
	{
		for(j=Russia->y-2;j<=Russia->y+1;j++)
		{
			if(a[i][j]==0&&j>FrameY)              //����λ���޷��飬������Ϸ������
			{
				toxy(i,j);                        
			    printf(" ");                      //��ӡ�ո��滻���飬ʵ�ַ������
			}
		}
	}
}

void welcome()
{
	int n,i,j=1;                        //nΪ��Ϸ��ʼѡ�i��j���д��ڴ�ӡ
	color(11);                          
	for (i=9;i<=20;i++)                 //���ڴ�ӡ
	{
		for(j=15;j<=60;j++)
		{
			toxy(j,i);
			if(i==9||i==20)
				printf("=");
			else if (j==15||j==59)
				printf("||");
		}
	}
	color(12);
	toxy(25,12);
	printf("1.��Ϸ��ʼ");
	toxy(40,12);
	printf("2.����˵��");               //δ��д��غ���
	toxy(25,17);
	printf("3.��Ϸ����");               //δ��д��غ���
	toxy(40,17);
	printf("4.�˳�");
	toxy(21,22);
	printf("��ѡ��[1 2 3 4]��[ ]\b\b");
	color(14);
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		system("cls");              //����
		UI();
		Gameplay();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		close();                    //�˳���Ϸ
		break;
	}
}

void Replay(struct russia *Russia)
{
	system("cls");                             //����
	memset(a,0,6400*sizeof(int));              //��ʼ������
	UI();   
	Gameplay();                                //��ʼ��Ϸ
}

void close()                                   //�˳���Ϸ
{
	exit(0);                 
}

void UI()                       //��Ϸ������ɺ���
{
	int i;
	toxy(FrameX+Frame_W -7,FrameY-2);
	color(15);
	printf("Ȥζ����˹����");
	toxy(FrameX+2*Frame_W+3,FrameY+7);
	color(2);
	printf("**********");
	toxy(FrameX+2*Frame_W+13,FrameY+7);
	color(3);
	printf("��һ�����ֵķ���");
	toxy(FrameX+2*Frame_W+3,FrameY+13);
	color(2);
	printf("**********");
	toxy(FrameX+2*Frame_W+3,FrameY+17);
	color(14);
	printf("��������ת");
	toxy(FrameX+2*Frame_W+3,FrameY+19);
	printf("�ո���ͣ��Ϸ");
	toxy(FrameX+2*Frame_W+3,FrameY+15);
	printf("Esc:�˳���Ϸ");
	toxy(FrameX,FrameY);
	color(12);
	printf("�X");
	toxy(FrameX+2*Frame_W-2,FrameY);
	printf("�[");
	toxy(FrameX,FrameY+Frame_H);
	printf("�^");
	toxy(FrameX+2*Frame_W-2,FrameY+Frame_H);
	printf("�a");
	a[FrameX][FrameY+Frame_H]=2;
	a[FrameX+2*Frame_W-2][FrameY+Frame_H]=2;
	for(i=2;i<2*Frame_W-2;i+=2)                 //�����������a�^�X �[�T  �T
	{
		toxy(FrameX+i,FrameY);
		printf("�T");
	}
	for(i=2;i<2*Frame_W-2;i+=2)                 //���������a�^�X �[�T  �T
	{
		toxy(FrameX+i,FrameY+Frame_H);
		printf("�T");
		a[FrameX+i][FrameY+Frame_H]=2;
	}
	for(i=1;i<Frame_H;i++)
	{
		toxy(FrameX,FrameY+i);
		printf("��");
		a[FrameX][FrameY+i]=2;
	}
	for(i=1;i<Frame_H;i++)
	{
		toxy(FrameX+2*Frame_W-2,FrameY+i);
		printf("��");
		a[FrameX+2*Frame_W-2][FrameY+i]=2;
	}
}

void MakeRussia(struct russia *Russia)                    //�����ӡ����˹����ĺ���
{
	a[Russia->x][Russia->y]=b[0];                         //���ķ����λ��
	switch(Russia->flag)                                  //���ѡ������һ�ַ���
	{
	case 1:
		{
			color(10);             
			a[Russia->x][Russia->y-1]=b[1];               //��b[i]��Ƿ���         
			a[Russia->x+2][Russia->y-1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 2:
		{
			color(10);
			a[Russia->x-2][Russia->y]=b[1];
			a[Russia->x+2][Russia->y]=b[2];
			a[Russia->x+4][Russia->y]=b[3];
			break;
		}
	case 3:
		{
			color(13);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x][Russia->y-2]=b[2];
			a[Russia->x][Russia->y+1]=b[3];
			break;
		}
	case 4:
		{
			color(11);
			a[Russia->x-2][Russia->y]=b[1];
			a[Russia->x+2][Russia->y]=b[2];
			a[Russia->x][Russia->y+1]=b[3];
			break;
		}
	case 5: 
		{
			color(11);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x][Russia->y+1]=b[2];
			a[Russia->x-2][Russia->y]=b[3];
			break;
		}
	case 6:
		{
			color(11);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x-2][Russia->y]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 7:
		{
			color(11);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x][Russia->y+1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 8:
		{
			color(14);
			a[Russia->x][Russia->y+1]=b[1];
			a[Russia->x-2][Russia->y]=b[2];
			a[Russia->x+2][Russia->y+1]=b[3];
			break;
		}
	case 9:
		{
			color(14);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x-2][Russia->y]=b[2];
			a[Russia->x-2][Russia->y+1]=b[3];
			break;
		}
	case 10:
		{
			color(14);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x-2][Russia->y-1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 11:
		{
			color(14);
			a[Russia->x][Russia->y+1]=b[1];
			a[Russia->x-2][Russia->y-1]=b[2];
			a[Russia->x-2][Russia->y]=b[3];
			break;
		}
	case 12:
		{
			color(12);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x][Russia->y+1]=b[2];
			a[Russia->x-2][Russia->y-1]=b[3];
			break;
		}
	case 13:
		{
			color(12);
			a[Russia->x-2][Russia->y]=b[1];
			a[Russia->x+2][Russia->y-1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 14:
		{
			color(12);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x][Russia->y+1]=b[2];
			a[Russia->x+2][Russia->y+1]=b[3];
			break;
		}
	case 15:
		{
			color(12);
			a[Russia->x-2][Russia->y]=b[1];
			a[Russia->x-2][Russia->y+1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 16:
		{
			color(12);
			a[Russia->x][Russia->y+1]=b[1];
			a[Russia->x][Russia->y-1]=b[2];
			a[Russia->x+2][Russia->y-1]=b[3];
			break;
		}
	case 17:
		{
			color(12);
			a[Russia->x-2][Russia->y]=b[1];
			a[Russia->x+2][Russia->y+1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	case 18:
		{
			color(12);
			a[Russia->x][Russia->y-1]=b[1];
			a[Russia->x][Russia->y+1]=b[2];
			a[Russia->x-2][Russia->y+1]=b[3];
			break;
		}
	case 19:
		{
			color(12);
			a[Russia->x-2][Russia->y]=b[1];
			a[Russia->x-2][Russia->y-1]=b[2];
			a[Russia->x+2][Russia->y]=b[3];
			break;
		}
	}
}

void Flag(struct russia *Russia)                   //�����������˹��������
{
	Russia->number++;                              //��¼��������˹����ĸ���
	srand(time(NULL));                             //���������
	if(Russia->number==1)                         
	{
		Russia->flag=rand()%19+1;                  //��¼��һ����������
	}
	Russia->next=rand()%19+1;                      //��һ����������
}

void Gameplay()
{
	int n;
	struct russia t,*Russia=&t;                    //����ṹ���ָ�벢ָ��ṹ�����
	char ch;                                       //�����������ı���
	Russia->number=0;            
	Russia->speed=300;
	Russia->score=0;
	Russia->level=1;
	while(1)
	{
		Flag(Russia);                              //�õ������������͵����
		temp=Russia->flag;                         //��¼���鵱ǰ�����
		Russia->x=FrameX+2*Frame_W+6;              //����ұ����ѷ����x����
		Russia->y=FrameY+10;                       //����ұ����ѷ����y����
		Russia->flag=Russia->next;                 //�����һ����������
		DrawRussia(Russia);                        //��ӡ����
		Russia->x=FrameX+Frame_W;                  //�����Ϸ���������ķ����x����
		Russia->y=FrameY-1;                        //�����Ϸ���������ķ����y����
		Russia->flag=temp;                    
		while(1)
		{
			W:DrawRussia(Russia);
			Sleep(Russia->speed);                  //�ӻ�ʱ��
			clean(Russia);                         //����ۼ�
			temp1=Russia->x;                       //��¼���ķ����ֵ
			temp2=Russia->flag;                    //��¼��ǰ��������
			if(kbhit())
			{
				ch=getch();                        //��
				if(ch==75)                         //��������
				{
					Russia->x-=2;
				}
				if(ch==77)                         //��������
				{
					Russia->x+=2;
				}
				if(ch==80)                         //�� ����������
				{
					if(ifMove(Russia)!=0)
					{
						Russia->y+=2;
					}
					if(ifMove(Russia)==0)
					{
						Russia->y=FrameY+Frame_H-2;
					}
				}
				if(ch==72)                          //�����������
				{
					if(Russia->flag>=2&&Russia->flag<=3)         //ֱ�߷���
					{
						Russia->flag++;
						Russia->flag%=2;
						Russia->flag+=2;
					}
					if(Russia->flag>=4&&Russia->flag<=7)         //T�ַ���
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=4;
					}
					if(Russia->flag>=8&&Russia->flag<=11)        //Z�ַ��飨�������У�
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=8;
					}
					if(Russia->flag>=12&&Russia->flag<=15)        //7�ַ���
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=12;
					}
					if(Russia->flag>=16&&Russia->flag<=19)       //��7�ַ���
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=16;
					}
				}
				if(ch==32)                               //�����ո񡱣���ͣ
				{
					DrawRussia(Russia);
					while(1)
					{
						if(kbhit())                     
						{
							ch=getch();
							if(ch==32)                   //�ٰ����ո񡱣�������Ϸ
							{
								goto W;
							}
							
						}
					}
				}
				if(ch==27)
				{
					system("cls");
					memset(a,0,6400*sizeof(int));        //��ʼ������
					welcome();
				}
				if(ifMove(Russia)==0)                    //�ж��Ƿ���ƶ������������ϲ�����Ч
				{
					Russia->x=temp1;
					Russia->flag=temp2;
				}
				else
				{
					goto W;
				}
			}
			Russia->y++;                                 //���κβ����������������
			if(ifMove(Russia)==0)                        //��������Ҳ��ܶ����򷽿���ڴ˴�
			{
				Russia->y--;
				DrawRussia(Russia);
				DelFullLine(Russia);                     //�ж����У�Ȼ����������е�һ��
				break;
			}
		}
		for(i=Russia->y-2;i<Russia->y+2;i++)
		{
			if(i==FrameY)
			{
				system("cls");
				toxy(29,7);
				printf("  \n");
				color(12);
				printf("E  N  D\n");
				toxy(17,14);
				printf("����һ��----1");
				toxy(44,14);
				printf("�˳���Ϸ----2\n");
				int n;
				toxy(32,16);
				printf("ѡ��1/2����");
				color(11);
				scanf("%d",&n);
				switch(n)
				{
				case 1:
					system("cls");
					Replay(Russia);
					break;
				case 2:
					exit(0);
					break;
				}
			}
		}
		Russia->flag=Russia->next;                  //����Ϊ�����ʾ�������ͼ��
		Russia->x=FrameX+2*Frame_W+6;
		Russia->y=FrameY+10;
		clean(Russia);
	}
}

void DrawRussia(struct russia *Russia)
{

	for(i=0;i<4;i++) 
	{
		b[i]=1;                                //����Ϊ1�����������Ϸ�߼��ж�
	}
	MakeRussia(Russia);                 
	for(i=Russia->x-2;i<=Russia->x+4;i+=2)     //���ֶ���˹�����ӡ
	{
		for(j=Russia->y-2;j<=Russia->y+1;j++)
		{
			if(a[i][j]==1&&j>FrameY)
			{
			toxy(i,j);
			printf("��");
			}
		}
	}
	toxy(FrameX+2*Frame_W+3,FrameY+1);         //�˵���Ϣ��ӡ
	color(4);
	printf("level:");
	color(12);
	printf("%d",Russia->level);
	toxy(FrameX+2*Frame_W+3,FrameY+3);
	color(4);
	printf("score:");
	color(12);
	printf("%d",Russia->score);
	toxy(FrameX+2*Frame_W+3,FrameY+5);
	color(4);
	printf("speed:");
	color(12);
	printf("%dms",Russia->speed);
}

void DelFullLine(struct russia *Russia)           //ɾ�����У�����Frame_W-2������ʱ������ɾ��
{
	int k,delrow=0;                               //k��¼ÿ�з�������delrow��¼ɾ������
	for(j=FrameY+Frame_H-1;j>=FrameY+1;j--)
	{
		k=0;
		for(i=FrameX+2;i<=FrameX+2*Frame_W-2;i+=2)
		{
			if(a[i][j]==1)
			{
				k++;
				if(k==Frame_W-2)
				{
					for(k=FrameX+2;k<=FrameX+2*Frame_W-2;k+=2)  //ɾ�����з���
					{
						a[k][j]=0;
						toxy(k,j);
						printf(" ");
					}
					for(k=j-1;k>FrameY;k--)                    //���ɾ���������з��飬����������ٽ���������һ��λ��
					{
						for(i=FrameX+2;i<=FrameX+2*Frame_W-2;i+=2)
						{
							if(a[i][k]==1)
							{
								a[i][k]=0;
								toxy(i,k);
								printf(" ");
								a[i][k+1]=1;
								toxy(i,k+1);
								printf("��");
							}
						}
					}
					j++;                                           //�������ƺ������ж�ɾ�����Ƿ�����
					delrow++;                                      //��¼ɾ������
				}
			}
		}
	}
	Russia->score+=100*delrow;                                                        //��¼����
	if(delrow>0&&(Russia->score%1000==0||Russia->score/1000>Russia->level-1))         //�÷�1000��ʱ���ٶȼӿ�20ms������һ��
	{
		Russia->speed-=20;
		Russia->level++;
	}
}

int color ( int a )                     //��ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
	return 0 ;
}

void toxy ( int x ,int y )              //��ȡ���λ�ú���
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}
void title()                //��ҳ��չʾ����
{
	color(15);
	toxy(24,3);
	printf("Ȥ ζ �� �� ˹ �� ��");
	color(11);
	toxy(18,5);
	printf("��");
	toxy(18,6);
	printf("����");
	toxy(18,7);
	printf("��");

	color(14);
	toxy(26,6);
	printf("����");
	toxy(28,7);
	printf("����");
	
	color(10);
	toxy(36,6);
	printf("����");
	toxy(36,7);
	printf("����");
	
	color(13);
	toxy(45,5);
	printf("��");
	toxy(45,6);
	printf("��");
	toxy(45,7);
	printf("��");
	toxy(45,8);
	printf("��");

    color(12);
	toxy(56,6);
	printf("��");
	toxy(52,7);
	printf("������\n\n");
}


int main()
{
	title();
	welcome();
}


