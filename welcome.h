#ifndef WELCOME_H_
#define WELCOME_H_
int color (int a);
void toxy(int x,int y);
void Gameplay();
void UI();
void close();
void welcome()
{
	int n,i,j=1;                        //nΪ��Ϸ��ʼѡ�i��j���д��ڴ�ӡ
	color(11);                          
	for (i=9;i<=20;i++)                 //���ڴ�ӡ
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
	printf("1.��Ϸ��ʼ");
	toxy(40,12);
	printf("2.����˵��");               //δ��д��غ���
	toxy(25,17);
	printf("3.��Ϸ����");               //δ��д��غ���
	toxy(40,17);
	printf("4.�˳�");
	toxy(21,22);
	printf("��ѡ��[1 2 3 4]��[ ]\b\b");
	color(14);
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		system("cls");              //����
		UI();
		Gameplay();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		close();                    //�˳���Ϸ
		break;
	}
}
#endif