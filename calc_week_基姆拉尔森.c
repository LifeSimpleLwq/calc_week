#include <stdio.h>

/**
	功能：根据日期计算星期，使用基姆拉尔森公式
	by: simple小强哥
	github:LifeSimpleLwq
	qq: 997950763 存在bug请练习本人更改，thanks
*/


int main(void) {
	int y = 1900,m = 12,d = 18;
	int w;
	
	if (m==1 || m==2)
	{
		m = (m==1?13:14);
		y--;
	}
	
	w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;
	printf("%d\r\n",w);
	printf("hello,world\r\n");
	return 0;
}
