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
void drawlinklist1();//n 张linklist中储存着各个图元,每次display都会将所有链表中的图元输出
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


/* 画一个圆角矩形 */
void drawRoundrec(double x, double y, double w, double h, int fillflag);
/* 画一个菱形 */
void drawDiamond(double x, double y, double w, double h, int fillflag);

/*画一个中心圆
 *(x,y)为圆心 
 * r为圆的半径
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
