#ifndef __WINDEF_H
#define __WINDEF_H

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

double winwidth, winheight, h;
char mytext[100];
void CharEventProcess(char ch);
void TimerEventProcess(int timerID);
void MouseEventProcess(int x, int y, int button, int event);
void KeyboardEventProcess(int key, int event);
void drawlinklist1();//n ��linklist�д����Ÿ���ͼԪ,ÿ��display���Ὣ���������е�ͼԪ���
void drawlinklist2();
void drawlinklist3();
void drawlinklist4();
void drawlinklist5();
void drawlinklist6();
void drawlinklist7();
void drawlinklist8();
void drawlinklist9();
void drawlinklist10();
void display();
void Initwin();
void InitButton();
int  select_graphic(double mx, double my);


/* ��һ��Բ�Ǿ��� */
void drawRoundrec(double x, double y, double w, double h, int fillflag);
/* ��һ������ */
void drawDiamond(double x, double y, double w, double h, int fillflag);

/*��һ������Բ
 *(x,y)ΪԲ�� 
 * rΪԲ�İ뾶
 */ 
void drawCircle(double x, double y, double r,int fillflag);
void drawOval(double x, double y, double rx, double ry,int fillflag);
void drawLine(double x1,double y1,double dx,double dy);
void drawDashline(double x1,double y1,double dx, double dy);
void drawDirectionalconnection(double x, double y, double dx, double dy, int fillflag,int arrow_style);
void drawBidirectionalconnection(double x, double y, double dx, double dy, int fillflag, int arrow_style);
void drawProcess(double x, double y, double w, double h, int fillflag);
void drawRoundrecBox(double x, double y, double w, double h, int fillflag, char *label, char xalignment, char *labelColor);
void drawDiamondBox(double x, double y, double w, double h, int fillflag, char *label, char xalignment, char *labelColor);
void drawCircleBox(double x, double y, double r, int fillflag, char *label, char labelAlignment, char *labelColor); 

void drawOvalBox(double x, double y, double rx, double ry, int fillflag, char *label, char labelAlignment, char *labelColor); 
void drawProcessBox(double x, double y, double w, double h, int fillflag, char *label, char labelAlignment, char *labelColor);
#endif
