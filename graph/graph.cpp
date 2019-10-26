#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include <conio.h>
#include <graphics.h>
#include<cstring>
#include <math.h>
#include<iomanip>
#include<fstream>
const int MAXX = 600 ;
const int MAXY = 600 ;
using namespace std ;


int main()
{
	int drv = VGA , mode = VGAHI;
	initgraph(&drv, &mode, NULL);
	fflush(stdin) ;	
	setcolor(WHITE);
	line(0,(MAXY/2)+120,getmaxx()-10,(MAXY/2)+120);
	line(MAXX-MAXX+50,10,MAXX-MAXX+50,getmaxy());
	fstream fin("file.txt",ios::in);	
	int time=5*50,temp=0;
	int dataset=0;
	setcolor(RED);
//	moveto(50+dataset,getmaxy()-50);
	while(dataset<=300){
		//line(MAXX-MAXX+50+dataset,getmaxy()-50+temp,MAXX-MAXX+50+dataset+100,time);
		moveto(50+dataset,getmaxy()-50-temp);
		lineto(50+dataset+100,time);
		dataset=dataset+100;
		temp=time;
		time=time+5*50;
	}
	
	getche();
	closegraph();
	return 0;
}

