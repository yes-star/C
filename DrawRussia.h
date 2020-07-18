#ifndef DRAWRUSSIA_H_
#define DRAWRUSSIA_H_

extern int i,j;

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
#endif