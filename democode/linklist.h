#ifndef __LINKLIST_H
#define __LINKIST_H
#include <stdio.h>
#include <stdlib.h>


#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"
typedef struct mrect  //矩形 
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mrect* next;
}myrect ;

typedef struct mroundrect  //圆角矩形 
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mroundrect* next;
}myroundrect;

typedef struct mdiamond  //菱形 
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mdiamond* next;
}mydiamond;

typedef struct mline  //直线 
{
	double x1, y1;
    double dx, dy;
    int pensize; /*粗细*/
    char pencolor[100]; /*颜色*/ 
	struct mline* next;
}myline; 

typedef struct mdashline  //虚线 
{
	double x1, y1;
    double dx, dy;
    int pensize; /*粗细*/
    char pencolor[100]; /*颜色*/ 
	struct mdashline* next;
}mydashline; 

typedef struct mdirectionalconnection //单向箭头 
{
	double x, y, dx, dy;
	int fillflag,arrow_style,pensize;
	char fill_color[100], front_color[100];
	struct mdirectional_connection* next;
}mydirectionalconnection;

typedef struct mbidirectionalconnection //双向箭头 
{
	double x, y, dx, dy;
	int fillflag, arrow_style, pensize;
	char fill_color[100], front_color[100];
	struct mbidirectionalconnection* next;
}mybidirectionalconnection;


typedef struct mprocess  //process
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mprocess* next;
}myprocess ;


typedef struct mcircle  //圆
{
	double  x,y; //圆心
	double  r;  //半径
    int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mcircle* next; 
}mycircle;

typedef struct moval  //椭圆 
{
	double  x,y; //左上角的点 
	double  rx, ry;  //半长轴 半短轴 
    int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mcircle* next; 
}myoval;

myrect* rect_head;//空内容的链表头指针.其中的next指向第一个rect
myrect* selected_rect;
void pushrect(myrect* source);



myroundrect* roundrect_head;
myroundrect* selected_roundrect;
void pushroundrect(myroundrect* source);


mydiamond* diamond_head;//空内容的链表头指针.其中的next指向第一个
mydiamond* selected_diamond;
void pushdiamond(mydiamond* source);


myline* line_head;//空内容的链表头指针.其中的next指向第一个
myline* selected_line;
void pushline(myline* source);


mydashline* dashline_head;//空内容的链表头指针.其中的next指向第一个
mydashline* selected_dashline;
void pushdashline(mydashline* source);


mydirectionalconnection* directionalconnection_head;//空内容的链表头指针.其中的next指向第一个
mydirectionalconnection* selected_directionalconnection;
void pushdirectionalconnection(mydirectionalconnection* source);



mybidirectionalconnection* bidirectionalconnection_head;//空内容的链表头指针.其中的next指向第一个
mybidirectionalconnection* selected_bidirectionalconnection;
void pushbidirectionalconnection(mybidirectionalconnection* source);



myprocess* process_head;//空内容的链表头指针.其中的next指向第一个
myprocess* selected_process;
void pushprocess(myprocess* source);


mycircle* circle_head;//空内容的链表头指针.其中的next指向第一个
mycircle* selected_circle;
void pushcircle(mycircle* source);


myoval* oval_head;//空内容的链表头指针.其中的next指向第一个
myoval* selected_oval;
void pushoval(myoval* source);


int  open();
int  save();

//1-9分别是矩形、圆角矩形，详见draw.h的说明 
void Initlinklist1();
void Initlinklist2();
void Initlinklist3();
void Initlinklist4();
void Initlinklist5();
void Initlinklist6();
void Initlinklist7();
void Initlinklist8();
void Initlinklist9();
void Initlinklist10(); 
#endif
