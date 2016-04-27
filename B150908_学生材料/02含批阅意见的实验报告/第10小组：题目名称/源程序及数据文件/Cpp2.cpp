#include "play.h"
#include <stdio.h>

int readPla(Player  *pla , int n)          /*读入球员记录值，球员号码为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one player\'s information\n");
		printf("num:  ");
	     scanf("%ld", &pla[i].num);
		if (pla[i].num==0) break;
		printf("name: ");
		scanf("%s",pla[i].name);
		printf("nation:  ");
		scanf("%s",pla[i].nation);
    	     pla[i].total=0;                /*总分需要计算求得，初值置为0*/
		printf("Input three data of the player:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&pla[i].score[j]);
		}

	}
	return i;                         /*返回实际读入的记录条数*/
}

void printPla ( Player  *pla , int n)       /*输出所有球员记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", pla[i].num);
		printf("%8s", pla[i].name);
		printf("%8s", pla[i].nation);
		for (j=0;j<3;j++)
		   printf("%6d",pla[i].score[j]);

	}
}

int equal(Player s1,Player s2,int condition)  /*如何判断两个Player记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较球员号码*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
}

int larger(Player s1,Player s2,int condition)  /*根据condition条件比较两个Player记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较球员号码*/
		return s1.num>s2.num;


	else return 1; /*其余情况返回1*/
}

void reverse(Player pla[],int n)             /*数组元素逆置*/
{
	int i;
	Player temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=pla[i];
		pla[i]=pla[n-1-i];
		pla[n-1-i]=temp;
	}
}

void calcuTotal(Player pla[],int n)         /*计算球队的总分*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有球员记录*/
	{
		pla[i].total =0;

			pla[i].total +=pla[i].score[1];
	}
}
