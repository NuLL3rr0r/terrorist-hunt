#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <time.h>

void man(int x,int y,int color);
void woman(int x,int y,int color);
void gun(int x,int color,char type);

main()
{
	int driver=DETECT,mode=0;
	initgraph(&driver,&mode,"C:\\TC\\BGI");

	char ch=0;
	int bkcolor=8;
	int Pos=320,shoot;
	float Xscale,Yscale;
	int rnd,reset=1;
	int tover,tmax;

	setbkcolor(bkcolor);
	settextstyle(0,0,3);
	outtextxy(70,170,"sound is disabled!!!");
	outtextxy(30,250,"press any key to play...");
	getch();
	cleardevice();
	randomize();
	tmax=3000;

	do
	{
			if (reset==1)
			{
			Pos=320;
			gun(Pos,1,'n');
			man(80,430,15);
			woman(240,430,15);
			man(400,430,15);
			woman(560,430,15);
			rnd=random(4);
			reset=0;
			tover=0;
			setcolor(14);
			printf("Time: %dms",tmax);
			printf("\n\n\n\nEsc: eXIT");
			printf("\nSpace: sHOOT");
			printf("\nLeft: mOVE lEFT");
			printf("\nRight: mOVE rIGHT");
			outtextxy(310,235,"3");
			delay(1000);
			setcolor(bkcolor);
			outtextxy(310,235,"3");
			setcolor(14);
			outtextxy(310,235,"2");
			delay(1000);
			setcolor(bkcolor);
			outtextxy(310,235,"2");
			setcolor(14);
			outtextxy(290,235,"Go!");
			delay(1000);
			setcolor(bkcolor);
			outtextxy(290,235,"Go!");
			clrscr();
			cleardevice();
			setbkcolor(bkcolor);
			ch=NULL;
			}
		do
		{
			if (tover>tmax) break;
			gun(Pos,1,'n');
			man(80,430,3);
			woman(240,430,3);
			man(400,430,3);
			woman(560,430,3);
			delay(50);
			if (rnd==0) man(80,430,4);
			else man(80,430,14);
			if (rnd==1) woman(240,430,4);
			else woman(240,430,14);
			if (rnd==2) man(400,430,4);
			else man(400,430,14);
			if (rnd==3) woman(560,430,4);
			else woman(560,430,14);
			delay(50);
			tover=tover+100;
		}while (kbhit()==0);
		if (tover<tmax)
		{
		ch=getch();
		switch(ch)
		{
			case 32:
				if (Pos!=320)
				{
				gun(Pos,bkcolor,'n');
				gun(Pos,4,'s');
				for(shoot=0,Xscale=0.01,Yscale=0.03;shoot<420;shoot++,Xscale+=0.01,Yscale+=0.03)
				{
					fillellipse(Pos,shoot,Xscale,Yscale);
					delay(1);
					setcolor(bkcolor);
					fillellipse(Pos,shoot,Xscale,Yscale);
					setcolor(3);
				}
						gun(Pos,bkcolor,'s');
						gun(Pos,1,'n');
				delay(300);
				for(shoot=0,Xscale=1,Yscale=3;shoot<20;shoot++,Xscale+=1,Yscale+=3)
				{
					fillellipse(Pos,419,Xscale,Yscale);
					delay(7);
				}
				setcolor(14);
				if ((rnd==0 && Pos==80) || (rnd==1 && Pos==240) || (rnd==2 && Pos==400) || (rnd==3 && Pos==560))
				{
				outtextxy(240,220,"You Win");
				tmax=tmax-300;
				}
				else
				{
				outtextxy(235,220,"You Lose");
				tmax=tmax+100;
				}
				delay(3000);
				clrscr();
				cleardevice();
				reset=1;
				ch=0;
				}
				break;
			case 75:
				gun(Pos,bkcolor,'n');
				switch(Pos)
				{
					case 320:
						Pos=240;
						break;
					case 560:
						Pos=400;
						break;
					case 400:
						Pos=240;
						break;
					case 240:
						Pos=80;
						break;
				}
				break;
			case 77:
				gun(Pos,bkcolor,'n');
				switch(Pos)
				{
					case 320:
						Pos=400;
						break;
					case 80:
						Pos=240;
						break;
					case 240:
						Pos=400;
						break;
					case 400:
						Pos=560;
						break;
				}
				break;
			default:
				break;
		}
		}
		else
		{
				tmax=tmax+100;
				setcolor(14);
				outtextxy(210,220,"Time Over");
				delay(3000);
				clrscr();
				cleardevice();
				reset=1;
				ch=0;
		}
	}while(ch!=27);

	restorecrtmode();
	return(0);
}

void man(int x,int y,int color)
{
	setcolor(color);
	line(x,y,x-15,y+35);
	line(x,y,x+15,y+35);
	line(x,y-35,x,y);
	circle(x,y-50,15);
	line(x,y-25,x-25,y-5);
	line(x,y-25,x+25,y-5);
}

void woman(int x,int y,int color)
{
	setcolor(color);
	arc(x,y+35,0,180,35);
	line(x-35,y+35,x+35,y+35);
	line(x,y-35,x,y);
	circle(x,y-50,15);
	line(x,y-25,x-25,y-5);
	line(x,y-25,x+25,y-5);
}

void gun(int x,int color,char type)
{
	int y=0;

	if (type!='s')
	{
	setcolor(color);
	line(x-15,y,x-15,y+30);
	line(x+15,y,x+15,y+30);
	line(x+10,y+30,x+10,y+40);
	line(x-10,y+30,x-10,y+40);
	line(x-15,y+30,x-10,y+30);
	line(x+15,y+30,x+10,y+30);
	line(x-10,y+40,x+10,y+40);
	}
	else
	{
	setcolor(color);
	line(x-15,y,x-15,y+30);
	line(x+15,y,x+15,y+30);
	line(x+10,y+30,x+10,y+40);
	line(x-10,y+30,x-10,y+40);
	line(x-15,y+30,x-10,y+30);
	line(x+15,y+30,x+10,y+30);
	}
}