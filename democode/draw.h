
#ifndef __DRAW_H
#define __DRAW_H
char table[3];
double x_1,y_1, x_2,y_2;//用户的第一个点、第二个点
int click_count;
int operate_flag,filled_flag,draw_what,front_color,PenSize,select_what,arrow_style;
int filled_color,alignment_flag,music_flag;
/*
5/12
draw_flag: 是否正在绘图
5/14
draw_flag was replaced by operate_flag
operate_flag=0: no operation
operate_flag=1: drawing operation
operate_flag=2: selection
operate_flag=3; moving
当
filled_flag: 是否对图形进行填充给
draw_what:绘制图形的标志其中
1:rectangle
2:roundrec
3:diamond
4:line
5:directional connection
6:bidiretional connection
7:dashline
8:process
9:circle
10:oval 
*/
void drawrectangle();


void drawroundrec();


void drawline();

void drawdiamond();


void drawdirectionalconnection();

void drawbiddirectionalconnection();


void drawdashline();

void drawprocess();


void drawcircle();


void drawoval();


void draw();
#endif
