#ifndef MAKERUSSIA_H_
#define MAKERUSSIA_H_

extern int a[80][80];
extern int b[4];
int color(int a);

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
#endif