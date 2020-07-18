
#ifndef IFMOVE_H_
#define IFMOVE_H_
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
extern int a[80][80];

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
#endif