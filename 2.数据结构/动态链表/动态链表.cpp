#include<iostream>
#include <malloc.h>
#include <stdbool.h>
#define LEN sizeof(struct S)//定义结构体变量的大小为符号常量LEN
using namespace std;

struct S{
	int ID;//链表元素
	string name;//姓名
	struct S *next;//指向下一个结构体
};
struct S *input();//输入函数
void output(struct S * head);//输出函数
struct S *deletee(struct S *head,int stdID);//删除一个元素，返回删除后表的头指针
struct S *insertt(struct S *head,int stdID,struct S *insertstd);//返回插入元素（子表）后的头指针
int append(struct S *head);//插入一个链表，从input函数输入
struct S *isexist(struct S *head,int stdID);

int main()
{
	struct S *present;//当前链表的头指针
	int choice;
	bool next;
	int stdID;
	/*
	1：插入一个元素
	2：删除一个元素
	3：续表
	4：查找表
	*/
	printf("**********动态链表**********\n初始化一个链表：\n");
	present=input();//当前的链表指针
	do{
		printf("请选择:\n|1：插入元素(子表)\n|2：删除元素\n|3：续表\n|4：查找表\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("请输入插入地点的后一个链表元素: ");
				scanf("%d",&stdID);
				if(isexist(present,stdID)==NULL)
				{
					printf("该元素不存在!\n");
					break;//退出switch语句
				}
				present=insertt(present,stdID,input());
				printf("插入元素后的链表为:\n");
				output(present);
				break;
			case 2:
				printf("请输入删除的元素:  ");
				scanf("%d",&stdID);
				if(isexist(present,stdID)==NULL)
				{
					printf("该元素不存在!\n");
					break;//退出switch语句
				}
				present=deletee(present,stdID);
				printf("删除后的链表为:\n");
				output(present);
				break;
			case 3:
				append(present);
				printf("续表后的链表为：\n");
				output(present);
				break;
			case 4:
				printf("当前链表为：\n");
				output(present);
				break;
		}
		printf("是否继续(Yes:1,No:0):  ");
		scanf("%d",&next);
		fflush(stdin);
	}while(next);


	return 0;
}


struct S * input()
{
	struct S *p1,*p2,*head=NULL;
	printf("************************动态链表 ***********************\n【输入动态链表】\n");
	printf("请输入链表元素（用空格间隔，输入0结束）:\n");
	p2=p1=(struct S *)malloc(LEN);//开辟内存
	scanf("%d",&p1->ID);
	if(p1->ID==0)return(head);
	else head=p1;
	while(p1->ID!=0)
	{
		p2->next=p1;
		p2=p1;
		p1=(struct S *)malloc(LEN);//分配长度为LEN字节的内存（块），会返回指向该内存的指针。
		scanf("%d",&p1->ID);
	}
	p2->next=NULL;
	return(head);//返回链表头指针
}

void output(struct S *head)
{
	struct S *p;
	int num=1;
	p=head;//将头指针地址传给p
	printf("【输出动态链表】\n");
	while(p!=NULL)
	{
		printf("%d ",p->ID);
		p=p->next;
	}
	printf("\n");
}

struct S *deletee(struct S *head,int stdID)
{
	struct S *p1,*p2;
	if(head->ID==stdID)
	{
		p1=head->next;
		free(head);
		return p1;
	}//如果删除的是第一个元素，比较特殊，需要修改头指针，其余不动
	//剩余几种情况都是修改next结构体指针
	for(p1=head;p1!=NULL;p2=p1,p1=p1->next)//p1指针和p2指针同时查找,p1指向当前的元素，p2保指向了上一个元素
	{
		if(p1->ID==stdID)
		{
		 	p2->next=p1->next;//假设找到了需要删除的元素，则让它上一个元素的指针指向跳过它的下一个元素
		 	free(p1);
		 	return head;
		}
	}
	return NULL;//返回NULL代表没找到
}

struct S *insertt(struct S *head,int stdID,struct S *insertstd)
{
	struct S *p1,*p2,*p;
	for(p=insertstd;p->next!=NULL;p=p->next);//找到insert链表的最后一个元素
	if(head->ID==stdID)
	{
		p->next=head;
		return insertstd;
	}

	for(p1=head;p1!=NULL;p2=p1,p1=p1->next)
	{
		if(p1->ID==stdID)
		{
			p2->next=insertstd;
			p->next=p1;
			return head;
		}
	}
	return NULL;
}

int append(struct S *head)//插入一个链表，从input函数输入
{
	struct S *p;
	for(p=head;p->next!=NULL;p=p->next);//找到head链表的最后一个元素
	p->next=input();//从input输入需要添加的元素，可以是1个或者多个
}

struct S *isexist(struct S *head,int stdID)
{
	struct S *p;
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->ID==stdID)
		{
			return p;
		}
	}
	return NULL;
}


