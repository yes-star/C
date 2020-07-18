#ifndef WELCOME_H_
#define WELCOME_H_
int color (int a);
void toxy(int x,int y);
void Gameplay();
void UI();
void close();
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
#endif