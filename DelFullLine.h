#ifndef DELFULLLINE_H_
#define DELFULLLINE_H_

extern int i,j;

void DelFullLine(struct russia *Russia)           //ɾ�����У�����Frame_W-2������ʱ������ɾ��
{
	int k,delrow=0;                               //k��¼ÿ�з�������delrow��¼ɾ������
	for(j=FrameY+Frame_H-1;j>=FrameY+1;j--)
	{
		k=0;
		for(i=FrameX+2;i<=FrameX+2*Frame_W-2;i+=2)
		{
			if(a[i][j]==1)
			{
				k++;
				if(k==Frame_W-2)
				{
					for(k=FrameX+2;k<=FrameX+2*Frame_W-2;k+=2)  //ɾ�����з���
					{
						a[k][j]=0;
						toxy(k,j);
						printf(" ");
					}
					for(k=j-1;k>FrameY;k--)                    //���ɾ���������з��飬����������ٽ���������һ��λ��
					{
						for(i=FrameX+2;i<=FrameX+2*Frame_W-2;i+=2)
						{
							if(a[i][k]==1)
							{
								a[i][k]=0;
								toxy(i,k);
								printf(" ");
								a[i][k+1]=1;
								toxy(i,k+1);
								printf("��");
							}
						}
					}
					j++;                                           //�������ƺ������ж�ɾ�����Ƿ�����
					delrow++;                                      //��¼ɾ������
				}
			}
		}
	}
	Russia->score+=100*delrow;                                                        //��¼����
	if(delrow>0&&(Russia->score%1000==0||Russia->score/1000>Russia->level-1))         //�÷�1000��ʱ���ٶȼӿ�20ms������һ��
	{
		Russia->speed-=20;
		Russia->level++;
	}
}
#endif