
#ifndef __DRAW_H
#define __DRAW_H
char table[3];
double x_1,y_1, x_2,y_2;//�û��ĵ�һ���㡢�ڶ�����
int click_count;
int operate_flag,filled_flag,draw_what,front_color,PenSize,select_what,arrow_style;
int filled_color,alignment_flag,music_flag;
/*
5/12
draw_flag: �Ƿ����ڻ�ͼ
5/14
draw_flag was replaced by operate_flag
operate_flag=0: no operation
operate_flag=1: drawing operation
operate_flag=2: selection
operate_flag=3; moving
��
filled_flag: �Ƿ��ͼ�ν�������
draw_what:����ͼ�εı�־����
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
