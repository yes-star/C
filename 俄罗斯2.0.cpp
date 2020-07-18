// 俄罗斯2.0.cpp : 定义控制台应用程序的入口点。
//
/*以下俄罗斯方块分为19种，田字*1，横竖2中，正Z字*4，反Z字*4，正7字*4，反7字*4，T字方块*4*/
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#include "conio.h"
#include "time.h"
#include "ifMove.h"
#include "clean.h"
#include "welcome.h"
#include "UI.h"
#include "MakeRussia.h"
#include "Gameplay.h"
#include "DrawRussia.h"
#include "DelFullLine.h"
#include "title.h"
#include "FlagReply.h"
#define FrameX 13//游戏窗口左上x轴坐标为13
#define FrameY 3//游戏窗口左上y轴坐标为3
#define Frame_H 20//游戏窗口高为20
#define Frame_W 18 //游戏窗口宽为18

int i,j,temp,temp1,temp2;
int a[80][80]={0}; 
int b[4];                   //标记4个小方块，0表示无方块，1未有方块

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

void close()                                   //退出游戏
{
	exit(0);                 
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

int main()
{
	title();
	welcome();
}