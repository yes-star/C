#ifndef CLEAN_H_
#define CLEAN_H_
#define FrameY 3
extern int b[4];
extern int a[80][80];
extern int i,j;
void MakeRussia(struct russia *);
void toxy(int x,int y); 
void clean(struct russia *Russia)                 //�������˹�������µĺۼ�
{
	for(i=0;i<4;i++)                              //b[i]���һ������˹�����4��С����
	{
		b[i]=0;                                   //����Ϊ�޷���
	}
	MakeRussia(Russia);                           //��������
	for(i=Russia->x-2;i<=Russia->x+4;i+=2)
	{
		for(j=Russia->y-2;j<=Russia->y+1;j++)
		{
			if(a[i][j]==0&&j>FrameY)              //����λ���޷��飬������Ϸ������
			{
				toxy(i,j);                        
			    printf(" ");                      //��ӡ�ո��滻���飬ʵ�ַ������
			}
		}
	}
}
#endif
