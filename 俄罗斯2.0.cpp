// ����˹2.0.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*���¶���˹�����Ϊ19�֣�����*1������2�У���Z��*4����Z��*4����7��*4����7��*4��T�ַ���*4*/
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
#define FrameX 13//��Ϸ��������x������Ϊ13
#define FrameY 3//��Ϸ��������y������Ϊ3
#define Frame_H 20//��Ϸ���ڸ�Ϊ20
#define Frame_W 18 //��Ϸ���ڿ�Ϊ18

int i,j,temp,temp1,temp2;
int a[80][80]={0}; 
int b[4];                   //���4��С���飬0��ʾ�޷��飬1δ�з���

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

void close()                                   //�˳���Ϸ
{
	exit(0);                 
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

int main()
{
	title();
	welcome();
}