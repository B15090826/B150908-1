#include "play.h"
#include <stdio.h>

int readPla(Player  *pla , int n)          /*������Ա��¼ֵ����Ա����Ϊ0������涨������¼ʱֹͣ*/
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
    	     pla[i].total=0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three data of the player:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&pla[i].score[j]);
		}

	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printPla ( Player  *pla , int n)       /*���������Ա��¼��ֵ*/
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

int equal(Player s1,Player s2,int condition)  /*����ж�����Player��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ���Ա����*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
}

int larger(Player s1,Player s2,int condition)  /*����condition�����Ƚ�����Player��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ���Ա����*/
		return s1.num>s2.num;


	else return 1; /*�����������1*/
}

void reverse(Player pla[],int n)             /*����Ԫ������*/
{
	int i;
	Player temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=pla[i];
		pla[i]=pla[n-1-i];
		pla[n-1-i]=temp;
	}
}

void calcuTotal(Player pla[],int n)         /*������ӵ��ܷ�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ������������Ա��¼*/
	{
		pla[i].total =0;

			pla[i].total +=pla[i].score[1];
	}
}
