
#ifndef IFMOVE_H_
#define IFMOVE_H_
struct russia               //����˹����ṹ��
{
	int x,y;                /*����˹��������ķ���x��y������*/
	int flag;               /*�������͵ı��*/  
	int next;               /*��һ������ı��*/
	int speed;              /*�����½��ٶ�*/
	int number;             /*��������ĸ���*/
	int score;              /*��Ϸ�ۼƵ÷�*/
	int level;              /*��Ϸ�ȼ����Ѷȣ�*/
};
extern int a[80][80];

int ifMove(struct russia *Russia)  //�жϷ����Ƿ�����ƶ�
{
	if(a[Russia->x][Russia->y]!=0)         //�ж����ķ��鲻Ϊ0�����з�����߽߱�
	{
		return 0;                          //����0�򲻿��ƶ�
	}
	else
	{
		if(
			(Russia->flag==1&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x+2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||          //�ж����ַ�������ķ����⣬��������λ���Ƿ����ͼ���������򷵻�1�������ƶ�

			(Russia->flag==2&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0&&a[Russia->x+4][Russia->y]==0))||            //ֱ�߷��飨�ᣩ

			(Russia->flag==3&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y-2]==0&&a[Russia->x][Russia->y+1]==0))||            //ֱ�߷��飨����

			(Russia->flag==4&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0&&a[Russia->x][Russia->y+1]==0))||            //4��5��6��7T�ַ��鼰�����

			(Russia->flag==5&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y]==0))||

			(Russia->flag==6&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==7&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==8&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y+1]==0))||          //8��9ΪZ�ַ��飨����

			(Russia->flag==9&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y+1]==0))||

			(Russia->flag==10&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||         //10��11ΪZ�ַ��飨��ת��

			(Russia->flag==11&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y-1]==0&&a[Russia->x-2][Russia->y]==0))||

			(Russia->flag==12&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x-2][Russia->y-1]==0))||         //12~15Ϊ7�ַ��鼰�����

			(Russia->flag==13&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x+2][Russia->y-1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==14&&(a[Russia->x][Russia->y-1]==0&&a[Russia->x][Russia->y+1]==0&&a[Russia->x+2][Russia->y+1]==0))||

			(Russia->flag==15&&(a[Russia->x-2][Russia->y]==0&&a[Russia->x-2][Russia->y+1]==0&&a[Russia->x+2][Russia->y]==0))||

			(Russia->flag==16&&(a[Russia->x][Russia->y+1]==0&&a[Russia->x][Russia->y-1]==0&&a[Russia->x+2][Russia->y-1]==0))||         //16~19Ϊ��ת��7�ַ��鼰�����

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