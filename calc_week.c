//#include "header.h"   //Anycodes includes the head file by default, needn't cancle the notation.
#include <stdio.h>
#include <stdlib.h>

/**
	功能：根据日期计算星期
	使用情景：有得时钟IC，不会自动根据日期调整星期。
	by: simple小强哥
	github:LifeSimpleLwq
	qq: 997950763 存在bug请练习本人更改，thanks
*/

char fun(int *month,int *year)
{
    char days;
    switch (*month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:days = 31;break;
        
        case 2:
				if (((*year%4 == 0)&& (*year%100 != 0)) || (*year %400 == 0))  days = 29;
				else days = 28;
				break;
        
        case 4:
        case 6:
        case 9:
        case 11: days = 30;break;
        
    }
    return days;
}

int main(void)
{
    int str[] = {2017,1,1,7};
    int data[] = {2020,12,18};	// 待计算日期
    
    int sun = 0,i;
    
    for (i = str[0]; i < data[0]; i++)
    {
        if (((i%4 == 0)&& (i%100 != 0)) || (i %400 == 0))  sun += 366;
        else sun += 365;
    }
    
    for (i = 1; i < data[1]; i++)
    {
        sun += fun(&i,&data[0]);   
    }
    sun += data[2]-1;	// 减1原因是我们是从1月1号开始算，1号算一天。
    sun = sun%7;
    
    str[3] += sun;
    str[3] = str[3]%7;
    
    printf("%d年%d月%d日 星期%d\r\n",data[0],data[1],data[2],str[3]);
	printf("Hello,world!");
	return EXIT_SUCCESS;
}