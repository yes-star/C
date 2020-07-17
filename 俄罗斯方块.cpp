// 俄罗斯方块.cpp : 定义控制台应用程序的入口点。
//
/*以下俄罗斯方块分为19种，田字*1，横竖2中，正Z字*4，反Z字*4，正7字*4，反7字*4，T字方块*4*/
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#include "conio.h"
#include "time.h"
#define FrameX 13//游戏窗口左上x轴坐标为13
#define FrameY 3//游戏窗口左上y轴坐标为3
#define Frame_H 20//游戏窗口高为20
#define Frame_W 18 //游戏窗口宽为18

int i,j,temp,temp1,temp2;
int a[80][80]={0}; 
int b[4];                   //标记4个小方块，0表示无方块，1未有方块

struct russia               //俄罗斯方块结构体
{
	int x,y;                /*俄罗斯方块的中心方块x，y轴坐标*/
	int flag;               /*方块类型的标号*/  
	int next;               /*下一个方块的标号*/
	int speed;              /*方块下降速度*/
	int number;             /*产生方块的个数*/
	int score;              /*游戏累计得分*/
	int level;              /*游戏等级（难度）*/
};
HANDLE hOut;


int ifMove(struct russia *);       //判断方块是否可以移动(46)
void clean(struct russia *);       //清除方块 (99)
void Replay(struct russia *);      //重新开始游戏(164)
void close();                      //退出游戏(172)
void UI();                         //游戏界面（177）
void welcome();                    //游戏欢迎界面(179)
void MakeRussia(struct russia *);  //制作方块（235）
void Flag(struct russia *);        //随机产生一个方块序号（395）
void Gameplay();                   //开始游戏(406)
void DrawRussia(struct russia *);  //打印方块（566)
void DelFullLine(struct russia *); //判断是否满行，然后清除满行(602)
int color (int a);                 //颜色函数（650）
void toxy(int x,int y);            //光标移动到指定位置（654）
void title();                      //欢迎界面标题(664)

int ifMove(struct russia *Russia)  //判断方块是否可以移动
{
	if(a[Russia->x][Russia->y]!=0)         //判断中心方块不为0，则有方块或者边界
	{
		return 0;                          //返回0则不可移动
	}
	else
	{
		if(
			(Russia->flag==1&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x+2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||          //判断田字方块除中心方块外，其它方块位置是否存在图案，若无则返回1，即可移动

			(Russia->flag==2&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0&&a[Russia->x+4][Russia->y]==0))||            //直线方块（横）

			(Russia->flag==3&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y-2]==0&&a[Russia->x][Russia->y+1]==0))||            //直线方块（竖）

			(Russia->flag==4&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0&&a[Russia->x][Russia->y+1]==0))||            //4，5，6，7T字方块及其变体

			(Russia->flag==5&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y]==0))||

			(Russia->flag==6&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==7&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==8&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y+1]==0))||          //8，9为Z字方块（正）

			(Russia->flag==9&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y+1]==0))||

			(Russia->flag==10&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||         //10，11为Z字方块（反转）

			(Russia->flag==11&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0))||

			(Russia->flag==12&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y-1]==0))||         //12~15为7字方块及其变体

			(Russia->flag==13&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==14&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x+2][Russia->y+1]==0))||

			(Russia->flag==15&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==16&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x][Russia->y-1]==0&&a[Russia->x+2][Russia->y-1]==0))||         //16~19为反转的7字方块及其变体

			(Russia->flag==17&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==18&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y+1]==0))||

			(Russia->flag==19&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0)))
		{
			return 1;
		}
	}
	return 0;
}

void clean(struct russia *Russia)                 //清除俄罗斯方块落下的痕迹
{
	for(i=0;i<4;i++)                              //b[i]标记一个俄罗斯方块的4个小方块
	{
		b[i]=0;                                   //令其为无方块
	}
	MakeRussia(Russia);                           //制作方块
	for(i=Russia->x-2;i<=Russia->x+4;i+=2)
	{
		for(j=Russia->y-2;j<=Russia->y+1;j++)
		{
			if(a[i][j]==0&&j>FrameY)              //若该位置无方块，且在游戏方框内
			{
				toxy(i,j);                        
			    printf(" ");                      //打印空格替换方块，实现方块清除
			}
		}
	}
}

void welcome()
{
	int n,i,j=1;                        //n为游戏开始选项，i与j进行窗口打印
	color(11);                          
	for (i=9;i<=20;i++)                 //窗口打印
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
	printf("1.游戏开始");
	toxy(40,12);
	printf("2.按键说明");               //未编写相关函数
	toxy(25,17);
	printf("3.游戏规则");               //未编写相关函数
	toxy(40,17);
	printf("4.退出");
	toxy(21,22);
	printf("请选择[1 2 3 4]：[ ]\b\b");
	color(14);
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		system("cls");              //清屏
		UI();
		Gameplay();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		close();                    //退出游戏
		break;
	}
}

void Replay(struct russia *Russia)
{
	system("cls");                             //清屏
	memset(a,0,6400*sizeof(int));              //初始化数组
	UI();   
	Gameplay();                                //开始游戏
}

void close()                                   //退出游戏
{
	exit(0);                 
}

void UI()                       //游戏框架生成函数
{
	int i;
	toxy(FrameX+Frame_W -7,FrameY-2);
	color(15);
	printf("趣味俄罗斯方块");
	toxy(FrameX+2*Frame_W+3,FrameY+7);
	color(2);
	printf("**********");
	toxy(FrameX+2*Frame_W+13,FrameY+7);
	color(3);
	printf("下一个出现的方块");
	toxy(FrameX+2*Frame_W+3,FrameY+13);
	color(2);
	printf("**********");
	toxy(FrameX+2*Frame_W+3,FrameY+17);
	color(14);
	printf("↑键：旋转");
	toxy(FrameX+2*Frame_W+3,FrameY+19);
	printf("空格：暂停游戏");
	toxy(FrameX+2*Frame_W+3,FrameY+15);
	printf("Esc:退出游戏");
	toxy(FrameX,FrameY);
	color(12);
	printf("╔");
	toxy(FrameX+2*Frame_W-2,FrameY);
	printf("╗");
	toxy(FrameX,FrameY+Frame_H);
	printf("╚");
	toxy(FrameX+2*Frame_W-2,FrameY+Frame_H);
	printf("╝");
	a[FrameX][FrameY+Frame_H]=2;
	a[FrameX+2*Frame_W-2][FrameY+Frame_H]=2;
	for(i=2;i<2*Frame_W-2;i+=2)                 //‖↑→←↓╝╚╔ ╗═  ═
	{
		toxy(FrameX+i,FrameY);
		printf("═");
	}
	for(i=2;i<2*Frame_W-2;i+=2)                 //↑→←↓╝╚╔ ╗═  ═
	{
		toxy(FrameX+i,FrameY+Frame_H);
		printf("═");
		a[FrameX+i][FrameY+Frame_H]=2;
	}
	for(i=1;i<Frame_H;i++)
	{
		toxy(FrameX,FrameY+i);
		printf("‖");
		a[FrameX][FrameY+i]=2;
	}
	for(i=1;i<Frame_H;i++)
	{
		toxy(FrameX+2*Frame_W-2,FrameY+i);
		printf("‖");
		a[FrameX+2*Frame_W-2][FrameY+i]=2;
	}
}

void MakeRussia(struct russia *Russia)                    //随机打印俄罗斯方块的函数
{
	a[Russia->x][Russia->y]=b[0];                         //中心方块的位置
	switch(Russia->flag)                                  //随机选择其中一种方块
	{
	case 1:
		{
			color(10);             
			a[Russia->x][Russia->y-1]=b[1];               //用b[i]标记方块         
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

void Flag(struct russia *Russia)                   //随机产生俄罗斯方块的序号
{
	Russia->number++;                              //记录产生俄罗斯方块的个数
	srand(time(NULL));                             //产生随机数
	if(Russia->number==1)                         
	{
		Russia->flag=rand()%19+1;                  //记录第一个方块的序号
	}
	Russia->next=rand()%19+1;                      //下一个方块的序号
}

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
				printf("E  N  D\n");
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

void DrawRussia(struct russia *Russia)
{

	for(i=0;i<4;i++) 
	{
		b[i]=1;                                //设置为1，方便后面游戏逻辑判断
	}
	MakeRussia(Russia);                 
	for(i=Russia->x-2;i<=Russia->x+4;i+=2)     //各种俄罗斯方块打印
	{
		for(j=Russia->y-2;j<=Russia->y+1;j++)
		{
			if(a[i][j]==1&&j>FrameY)
			{
			toxy(i,j);
			printf("■");
			}
		}
	}
	toxy(FrameX+2*Frame_W+3,FrameY+1);         //菜单信息打印
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

void DelFullLine(struct russia *Russia)           //删除满行，当有Frame_W-2个方块时，满行删除
{
	int k,delrow=0;                               //k记录每行方块数，delrow记录删除行数
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
					for(k=FrameX+2;k<=FrameX+2*Frame_W-2;k+=2)  //删除满行方块
					{
						a[k][j]=0;
						toxy(k,j);
						printf(" ");
					}
					for(k=j-1;k>FrameY;k--)                    //如果删除行上面有方块，则先清除，再将方块下移一个位置
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
								printf("■");
							}
						}
					}
					j++;                                           //方块下移后重新判断删除行是否满行
					delrow++;                                      //记录删除行数
				}
			}
		}
	}
	Russia->score+=100*delrow;                                                        //记录分数
	if(delrow>0&&(Russia->score%1000==0||Russia->score/1000>Russia->level-1))         //得分1000分时，速度加快20ms，且升一级
	{
		Russia->speed-=20;
		Russia->level++;
	}
}

int color ( int a )                     //颜色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
	return 0 ;
}

void toxy ( int x ,int y )              //获取光标位置函数
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}
void title()                //首页面展示函数
{
	color(15);
	toxy(24,3);
	printf("趣 味 俄 罗 斯 方 块");
	color(11);
	toxy(18,5);
	printf("■");
	toxy(18,6);
	printf("■■");
	toxy(18,7);
	printf("■");

	color(14);
	toxy(26,6);
	printf("■■");
	toxy(28,7);
	printf("■■");
	
	color(10);
	toxy(36,6);
	printf("■■");
	toxy(36,7);
	printf("■■");
	
	color(13);
	toxy(45,5);
	printf("■");
	toxy(45,6);
	printf("■");
	toxy(45,7);
	printf("■");
	toxy(45,8);
	printf("■");

    color(12);
	toxy(56,6);
	printf("■");
	toxy(52,7);
	printf("■■■\n\n");
}


int main()
{
	title();
	welcome();
}


