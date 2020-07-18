#ifndef CLEAN_H_
#define CLEAN_H_
#define FrameY 3
extern int b[4];
extern int a[80][80];
extern int i,j;
void MakeRussia(struct russia *);
void toxy(int x,int y); 
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
#endif
