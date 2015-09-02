
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include<ctime>
#include "body.h"
using namespace std;
body::body()
{
	head=new bodynode;
	head->next=NULL;
	head->x=20;
	head->y=6;
	head->z="●";
	dir='a';
	level=1;
	count=4;
	score=0;
	int i;
	bodynode *p=head;
	for(i=1;i<4;i++)//初始蛇身四个结点
	{
		bodynode *q=new bodynode;
		q->x=2*i+20;
		q->y=6;
		q->z="■";
		q->next=NULL;
		p->next=q;
		p=p->next;		
	}

}
body::~body()
{
	bodynode *p=NULL;
	for(p=head;p->next!=NULL;p=p->next)
		delete p;
}
void body::position(int x,int y)
{
	HANDLE a;
	a=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD setps;
	setps.X=x;
	setps.Y=y;
	SetConsoleCursorPosition(a,setps);
}
void body::beginview()
{
		position(26,11);cout<<"■■■■■■■■■■■■■";
		position(26,12);cout<<"■        贪吃蛇        ■";
		position(26,13);cout<<"■■■■■■■■■■■■■";
		position(26,14);cout<<"■一一一一一一一一一一一■";
		position(26,15);cout<<"■ W,S,A,D 对应 上下左右■";
		position(26,16);cout<<"■一一一一一一一一一一一■";
		position(26,17);cout<<"■一一一一一一一一一一一■";
		position(26,18);cout<<"■按任意键开始..        ■";
		position(26,19);cout<<"■■■■■■■■■■■■■";
			position(62,20);
	cout<<"By linnn南";
		char cc;
		cc=getch();
		system("cls");
		return;
}
void body::AllView()
{
	int i;
	for(i=0;i<30;i++)
		cout<<"■";
	for(i=1;i<24;i++)
	{
	position(0,i);
	cout<<"■";
	position(58,i);
	cout<<"■";
	}
	position(0,24);
	for(i=0;i<30;i++)
		cout<<"■";
	position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
	position(62,9);
	cout<<"所得分数:"<<score;
	position(62,20);
	cout<<"By linnn南";
	food();
}
void body::bodyview()//输出蛇身
{
	bodynode *p=head;
	for(;p!=NULL;p=p->next)
	{
	position(p->x,p->y);
		cout<<p->z;
	}
}
void body::taildel()
{
	bodynode *p,*q;
	for(p=head;p->next!=NULL;p=p->next)q=p;
	q->next=NULL;
	position(p->x,p->y);
	cout<<"  ";

	delete p;
	
}
void body::dmove(char dirr)
{
	char ch;
	if(dirr=='a')//left
	{
		bodynode *p=new bodynode;
		p->x=(head->x)-2;
		p->y=(head->y);
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y)
		{
			count++;
			level=(count+1)/5;
			score=score+100*level;
	position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
	position(62,9);
	cout<<"所得分数:"<<score;
			position(62,9);
			food();
			bodyview();return;}
		dir='a';
		taildel();
		bodyview();
	}
	if(dirr=='s')//down
	{
		bodynode *p=new bodynode;
		p->x=(head->x);
		p->y=(head->y)+1;
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y)
		{
			count++;
			level=(count+1)/5;
			score=score+100*level;
	position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
		position(62,9);
	cout<<"所得分数:"<<score;
	food();bodyview();return;}
		dir='s';
		taildel();
		bodyview();
	}
	if(dirr=='d')//right
	{
		bodynode *p=new bodynode;
		p->x=(head->x)+2;
		p->y=(head->y);
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y){count++;level=(count+1)/5;score=score+100*level;	position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
		position(62,9);
	cout<<"所得分数:"<<score;food();bodyview();return;}
		dir='d';
		taildel();
		bodyview();
	}
	if(dirr=='w')//up
	{
		bodynode *p=new bodynode;
		p->x=(head->x);
		p->y=(head->y)-1;
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y){count++;level=(count+1)/5;score=score+100*level;		position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
		position(62,9);
	cout<<"所得分数:"<<score;food();bodyview();return;}
		dir='w';
		taildel();
		bodyview();
	}
	return;
}
void body::move()
{
	char mov,ch;
while(1)
{
	if(!_kbhit())
	{
		dmove(dir);
	}

	if(_kbhit())
	{
	mov=getch();
	if(mov=='a'&&dir!='d')//left
	{
		bodynode *p=new bodynode;
		p->x=(head->x)-2;
		p->y=(head->y);
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y){count++;level=(count+1)/5;score=score+100*level;	position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;	position(62,9);
	cout<<"所得分数:"<<score;food();bodyview();continue;}
		dir='a';
		taildel();
		bodyview();
	}

	if(mov=='s'&&dir!='w')//down
	{
		bodynode *p=new bodynode;
		p->x=(head->x);
		p->y=(head->y)+1;
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y){count++;level=(count+1)/5;score=score+100*level;	position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
		position(62,9);
	cout<<"所得分数:"<<score;food();bodyview();continue;}
		dir='s';
		taildel();
		bodyview();
	}
	if(mov=='d'&&dir!='a')//right
	{
		bodynode *p=new bodynode;
		p->x=(head->x)+2;
		p->y=(head->y);
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y){count++;level=(count+1)/5;score=score+100*level;		position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
		position(62,9);
	cout<<"所得分数:"<<score;food();bodyview();continue;}
		dir='d';
		taildel();
		bodyview();
	}
	if(mov=='w'&&dir!='s')//up
	{
		bodynode *p=new bodynode;
		p->x=(head->x);
		p->y=(head->y)-1;
		p->z="●";
		p->next=head;
		head->z="■";
		head=p;
		if(!over())
		{
			ch=getch();
			exit(0);
		}
		if((head->x)==x&&(head->y)==y){count++;level=(count+1)/5;score=score+100*level;		position(62,3);
	cout<<"蛇身长度:"<<count;
	position(62,6);
	cout<<"游戏难度:"<<level;
		position(62,9);
	cout<<"所得分数:"<<score;food();bodyview();continue;}
		dir='w';
		taildel();
		bodyview();
	}
	
	if(mov!='a'&&mov!='s'&&mov!='d'&&mov!='w')continue;
	if(mov=='a'&&dir=='d'||dir=='a'&&mov=='d'||dir=='s'&&mov=='w'||dir=='w'&&mov=='s')continue;
	}
		Sleep(300-50*level);

}
}
bool body::over()
{
	if(level==6)
	{
				system("cls");
		
		position(26,11);cout<<"■■■■■■■■■■■■■";
		position(26,12);cout<<"■游戏等级到达10，通关! ■";
		position(26,13);cout<<"■■■■■■■■■■■■■";
		return false;
	}
	if((head->x)==0||(head->x)==58||(head->y==0)||(head->y)==24)
	{
		system("cls");
		
		position(26,11);cout<<"■■■■■■■■■■■■■";
		position(26,12);cout<<"■碰撞到墙壁，您以失败! ■";
		position(26,13);cout<<"■■■■■■■■■■■■■";
		return false;
	}
	bodynode *p;
	for(p=(head->next);p!=NULL;p=p->next)
	{
		if((p->x)==(head->x)&&(p->y)==(head->y))
		{
			system("cls");
		position(26,11);cout<<"■■■■■■■■■■■■■";
		position(26,12);cout<<"■碰撞到蛇身，您以失败! ■";
		position(26,13);cout<<"■■■■■■■■■■■■■";
			return false;
		}
	}
	return true;
}
void body::food()
{
	int xx,yy;
	srand(time(0));
	xx=rand()%(56-2+1)+2;
	yy=rand()%(23-1+1)+1;
	if((xx%2)!=0)xx=xx+1;
	bodynode *p;
	for(p=head;p!=NULL;p=p->next)
		if(xx==(p->x)&&yy==(p->y))
		{
				xx=rand()%(56-2+1)+2;
				yy=rand()%(23-1+1)+1;
				p=head;
		}
			x=xx;
			y=yy;
	position(x,y);
	cout<<"★";
		
}
void body::Game()
{
	AllView();
	bodyview();
	move();
}
