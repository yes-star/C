#ifndef FLAGREPLY_H_
#define FLAGREPLY_H_

void Gameplay();

void Flag(struct russia *Russia)                   //�����������˹��������
{
	Russia->number++;                              //��¼��������˹����ĸ���
	srand(time(NULL));                             //���������
	if(Russia->number==1)                         
	{
		Russia->flag=rand()%19+1;                  //��¼��һ����������
	}
	Russia->next=rand()%19+1;                      //��һ����������
}

void Replay(struct russia *Russia)
{
	system("cls");                             //����
	memset(a,0,6400*sizeof(int));              //��ʼ������
	UI();   
	Gameplay();                                //��ʼ��Ϸ
}
#endif
