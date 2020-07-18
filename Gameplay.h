#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#define FrameX 13//��Ϸ��������x������Ϊ13
#define FrameY 3//��Ϸ��������y������Ϊ3
#define Frame_H 20//��Ϸ���ڸ�Ϊ20
#define Frame_W 18 //��Ϸ���ڿ�Ϊ18

extern int b[4];
extern int a[80][80];
extern int temp,temp1,temp2;
void Flag(struct russia *);
void DrawRussia(struct russia*);
void clean(struct russia *);
int ifMove(struct russia *);
void welcome();
void DelFullLine(struct russia *);
void Replay(struct russia *);
int color (int a);
void toxy(int x,int y);
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
				printf("\t\t\tE  N  D\n");
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
#endif