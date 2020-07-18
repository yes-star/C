#ifndef FLAGREPLY_H_
#define FLAGREPLY_H_

void Gameplay();

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

void Replay(struct russia *Russia)
{
	system("cls");                             //清屏
	memset(a,0,6400*sizeof(int));              //初始化数组
	UI();   
	Gameplay();                                //开始游戏
}
#endif
