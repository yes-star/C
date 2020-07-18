#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#define FrameX 13//游戏窗口左上x轴坐标为13
#define FrameY 3//游戏窗口左上y轴坐标为3
#define Frame_H 20//游戏窗口高为20
#define Frame_W 18 //游戏窗口宽为18

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
	struct russia t,*Russia=&t;                    //定义结构体的指针并指向结构体变量
	char ch;                                       //定义键盘输入的变量
	Russia->number=0;            
	Russia->speed=300;
	Russia->score=0;
	Russia->level=1;
	while(1)
	{
		Flag(Russia);                              //得到产生方块类型的序号
		temp=Russia->flag;                         //记录方块当前的序号
		Russia->x=FrameX+2*Frame_W+6;              //获得右边提醒方块的x坐标
		Russia->y=FrameY+10;                       //获得右边提醒方块的y坐标
		Russia->flag=Russia->next;                 //获得下一个方块的序号
		DrawRussia(Russia);                        //打印方块
		Russia->x=FrameX+Frame_W;                  //获得游戏窗口内中心方块的x坐标
		Russia->y=FrameY-1;                        //获得游戏窗口内中心方块的y坐标
		Russia->flag=temp;                    
		while(1)
		{
			W:DrawRussia(Russia);
			Sleep(Russia->speed);                  //延缓时间
			clean(Russia);                         //清除痕迹
			temp1=Russia->x;                       //记录中心方块的值
			temp2=Russia->flag;                    //记录当前方块的序号
			if(kbhit())
			{
				ch=getch();                        //←
				if(ch==75)                         //按←左移
				{
					Russia->x-=2;
				}
				if(ch==77)                         //按→右移
				{
					Russia->x+=2;
				}
				if(ch==80)                         //按 ↓加速下落
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
				if(ch==72)                          //按↑方块变体
				{
					if(Russia->flag>=2&&Russia->flag<=3)         //直线方块
					{
						Russia->flag++;
						Russia->flag%=2;
						Russia->flag+=2;
					}
					if(Russia->flag>=4&&Russia->flag<=7)         //T字方块
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=4;
					}
					if(Russia->flag>=8&&Russia->flag<=11)        //Z字方块（正反均有）
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=8;
					}
					if(Russia->flag>=12&&Russia->flag<=15)        //7字方块
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=12;
					}
					if(Russia->flag>=16&&Russia->flag<=19)       //反7字方块
					{
						Russia->flag++;
						Russia->flag%=4;
						Russia->flag+=16;
					}
				}
				if(ch==32)                               //按“空格”，暂停
				{
					DrawRussia(Russia);
					while(1)
					{
						if(kbhit())                     
						{
							ch=getch();
							if(ch==32)                   //再按“空格”，继续游戏
							{
								goto W;
							}
							
						}
					}
				}
				if(ch==27)
				{
					system("cls");
					memset(a,0,6400*sizeof(int));        //初始化数组
					welcome();
				}
				if(ifMove(Russia)==0)                    //判断是否可移动，不可则以上操作无效
				{
					Russia->x=temp1;
					Russia->flag=temp2;
				}
				else
				{
					goto W;
				}
			}
			Russia->y++;                                 //无任何操作，方块继续下移
			if(ifMove(Russia)==0)                        //如果下移且不能动，则方块放在此处
			{
				Russia->y--;
				DrawRussia(Russia);
				DelFullLine(Russia);                     //判断满行，然后清楚已满行的一行
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
				printf("重玩一局----1");
				toxy(44,14);
				printf("退出游戏----2\n");
				int n;
				toxy(32,16);
				printf("选择【1/2】：");
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
		Russia->flag=Russia->next;                  //以下为清除提示处方块的图形
		Russia->x=FrameX+2*Frame_W+6;
		Russia->y=FrameY+10;
		clean(Russia);
	}
}
#endif