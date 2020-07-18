#ifndef UI_H_
#define UI_H_
#define FrameX 13//游戏窗口左上x轴坐标为13
#define FrameY 3//游戏窗口左上y轴坐标为3
#define Frame_H 20//游戏窗口高为20
#define Frame_W 18 //游戏窗口宽为18
extern int b[4];
extern int a[80][80];
void toxy(int x,int y); 
int color(int a);
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
#endif