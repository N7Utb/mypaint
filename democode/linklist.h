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
typedef struct mrect  //���� 
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mrect* next;
}myrect ;

typedef struct mroundrect  //Բ�Ǿ��� 
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mroundrect* next;
}myroundrect;

typedef struct mdiamond  //���� 
{
	double x, y, width, height;
	int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mdiamond* next;
}mydiamond;

typedef struct mline  //ֱ�� 
{
	double x1, y1;
    double dx, dy;
    int pensize; /*��ϸ*/
    char pencolor[100]; /*��ɫ*/ 
	struct mline* next;
}myline; 

typedef struct mdashline  //���� 
{
	double x1, y1;
    double dx, dy;
    int pensize; /*��ϸ*/
    char pencolor[100]; /*��ɫ*/ 
	struct mdashline* next;
}mydashline; 

typedef struct mdirectionalconnection //�����ͷ 
{
	double x, y, dx, dy;
	int fillflag,arrow_style,pensize;
	char fill_color[100], front_color[100];
	struct mdirectional_connection* next;
}mydirectionalconnection;

typedef struct mbidirectionalconnection //˫���ͷ 
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


typedef struct mcircle  //Բ
{
	double  x,y; //Բ��
	double  r;  //�뾶
    int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mcircle* next; 
}mycircle;

typedef struct moval  //��Բ 
{
	double  x,y; //���Ͻǵĵ� 
	double  rx, ry;  //�볤�� ����� 
    int fillflag,text_flag;
	char alignment;
	char text[100],fill_color[100], front_color[100];
	struct mcircle* next; 
}myoval;

myrect* rect_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��rect
myrect* selected_rect;
void pushrect(myrect* source);



myroundrect* roundrect_head;
myroundrect* selected_roundrect;
void pushroundrect(myroundrect* source);


mydiamond* diamond_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
mydiamond* selected_diamond;
void pushdiamond(mydiamond* source);


myline* line_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
myline* selected_line;
void pushline(myline* source);


mydashline* dashline_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
mydashline* selected_dashline;
void pushdashline(mydashline* source);


mydirectionalconnection* directionalconnection_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
mydirectionalconnection* selected_directionalconnection;
void pushdirectionalconnection(mydirectionalconnection* source);



mybidirectionalconnection* bidirectionalconnection_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
mybidirectionalconnection* selected_bidirectionalconnection;
void pushbidirectionalconnection(mybidirectionalconnection* source);



myprocess* process_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
myprocess* selected_process;
void pushprocess(myprocess* source);


mycircle* circle_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
mycircle* selected_circle;
void pushcircle(mycircle* source);


myoval* oval_head;//�����ݵ�����ͷָ��.���е�nextָ���һ��
myoval* selected_oval;
void pushoval(myoval* source);


int  open();
int  save();

//1-9�ֱ��Ǿ��Ρ�Բ�Ǿ��Σ����draw.h��˵�� 
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
