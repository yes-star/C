#ifndef UI_H_
#define UI_H_
#define FrameX 13//��Ϸ��������x������Ϊ13
#define FrameY 3//��Ϸ��������y������Ϊ3
#define Frame_H 20//��Ϸ���ڸ�Ϊ20
#define Frame_W 18 //��Ϸ���ڿ�Ϊ18
extern int b[4];
extern int a[80][80];
void toxy(int x,int y); 
int color(int a);
void UI()                       //��Ϸ������ɺ���
{
	int i;
	toxy(FrameX+Frame_W -7,FrameY-2);
	color(15);
	printf("Ȥζ����˹����");
	toxy(FrameX+2*Frame_W+3,FrameY+7);
	color(2);
	printf("**********");
	toxy(FrameX+2*Frame_W+13,FrameY+7);
	color(3);
	printf("��һ�����ֵķ���");
	toxy(FrameX+2*Frame_W+3,FrameY+13);
	color(2);
	printf("**********");
	toxy(FrameX+2*Frame_W+3,FrameY+17);
	color(14);
	printf("��������ת");
	toxy(FrameX+2*Frame_W+3,FrameY+19);
	printf("�ո���ͣ��Ϸ");
	toxy(FrameX+2*Frame_W+3,FrameY+15);
	printf("Esc:�˳���Ϸ");
	toxy(FrameX,FrameY);
	color(12);
	printf("�X");
	toxy(FrameX+2*Frame_W-2,FrameY);
	printf("�[");
	toxy(FrameX,FrameY+Frame_H);
	printf("�^");
	toxy(FrameX+2*Frame_W-2,FrameY+Frame_H);
	printf("�a");
	a[FrameX][FrameY+Frame_H]=2;
	a[FrameX+2*Frame_W-2][FrameY+Frame_H]=2;
	for(i=2;i<2*Frame_W-2;i+=2)                 //�����������a�^�X �[�T  �T
	{
		toxy(FrameX+i,FrameY);
		printf("�T");
	}
	for(i=2;i<2*Frame_W-2;i+=2)                 //���������a�^�X �[�T  �T
	{
		toxy(FrameX+i,FrameY+Frame_H);
		printf("�T");
		a[FrameX+i][FrameY+Frame_H]=2;
	}
	for(i=1;i<Frame_H;i++)
	{
		toxy(FrameX,FrameY+i);
		printf("��");
		a[FrameX][FrameY+i]=2;
	}
	for(i=1;i<Frame_H;i++)
	{
		toxy(FrameX+2*Frame_W-2,FrameY+i);
		printf("��");
		a[FrameX+2*Frame_W-2][FrameY+i]=2;
	}
}
#endif