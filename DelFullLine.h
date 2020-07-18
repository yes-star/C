#ifndef DELFULLLINE_H_
#define DELFULLLINE_H_

extern int i,j;

void DelFullLine(struct russia *Russia)           //删除满行，当有Frame_W-2个方块时，满行删除
{
	int k,delrow=0;                               //k记录每行方块数，delrow记录删除行数
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
					for(k=FrameX+2;k<=FrameX+2*Frame_W-2;k+=2)  //删除满行方块
					{
						a[k][j]=0;
						toxy(k,j);
						printf(" ");
					}
					for(k=j-1;k>FrameY;k--)                    //如果删除行上面有方块，则先清除，再将方块下移一个位置
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
								printf("■");
							}
						}
					}
					j++;                                           //方块下移后重新判断删除行是否满行
					delrow++;                                      //记录删除行数
				}
			}
		}
	}
	Russia->score+=100*delrow;                                                        //记录分数
	if(delrow>0&&(Russia->score%1000==0||Russia->score/1000>Russia->level-1))         //得分1000分时，速度加快20ms，且升一级
	{
		Russia->speed-=20;
		Russia->level++;
	}
}
#endif