#ifndef TITLE_H_
#define TITLE_H_

void title()                //首页面展示函数
{
	color(15);
	toxy(24,3);
	printf("趣 味 俄 罗 斯 方 块");
	color(11);
	toxy(18,5);
	printf("■");
	toxy(18,6);
	printf("■■");
	toxy(18,7);
	printf("■");

	color(14);
	toxy(26,6);
	printf("■■");
	toxy(28,7);
	printf("■■");
	
	color(10);
	toxy(36,6);
	printf("■■");
	toxy(36,7);
	printf("■■");
	
	color(13);
	toxy(45,5);
	printf("■");
	toxy(45,6);
	printf("■");
	toxy(45,7);
	printf("■");
	toxy(45,8);
	printf("■");

    color(12);
	toxy(56,6);
	printf("■");
	toxy(52,7);
	printf("■■■\n\n");
}
#endif