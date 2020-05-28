#include "draw.h"
#include "windraw.h"
#include "linklist.h"
#include  "math.h"
char* acolor[20] = {
		"Black",
		"Dark Gray",
		"Light Gray",
		"White",
		"Brown",
		"Red",
		"Orange",
		"Yellow",
		"Green",
		"Blue",
		"Violet",
		"Magenta",
		"Cyan"
};
char table[3] = "LRC";

void draw(double mx,double my)
{
	switch (draw_what)
	{
		case 1:
		{
			drawrectangle(mx,my);
			break;
		}
		case 2:
		{
			drawroundrec(mx, my);
			break;
		} 
		case 3:
		{
			drawdiamond(mx, my);
			break;
		}
        case 4:
        {
        	drawline(mx, my);
	        	break;
		}
		case 5:
		{
			drawdirectionalconnection(mx, my);
			break;
		 } 
		case 6:
		{
			drawbiddirectionalconnection(mx, my);
			break;
		 }
		case 7:
		{
			drawdashline(mx, my);
			break;
		}
		 case 8:
		 {
		 	drawprocess(mx, my);
		 	break;
		  } 
		case 9:
		{
			drawcircle(mx, my);
			break;
		}
		case 10:
		{
			drawoval(mx, my);
			break;
		}
	}
}


void drawrectangle(double mx,double my)  //画矩形 
{
		
	myrect* a=malloc(sizeof(myrect));
	if (a == NULL)
	{
		exit(0);
	}
	a->x =mx;
	a->y =my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height = 0;
	a->width = 0;
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = table[alignment_flag];
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushrect(a);
}

void drawroundrec(double mx, double my)   //绘制圆角矩形 
{
		
	myroundrect* a=malloc(sizeof(myroundrect));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = mx;					//两个点中横坐标最小值为矩形左下角横坐标
	a->y =my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height =0;	//两个点的纵坐标相减的绝对值为高
	a->width = 0;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = table[alignment_flag];
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushroundrect(a);
	
}

void drawdiamond(double mx, double my) //画菱形 
{
	mydiamond* a=malloc(sizeof(mydiamond));
	if (a == NULL)
	{
		exit(0);
	}
	a->x =mx;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y =my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height =0;	//两个点的纵坐标相减的绝对值为高
	a->width = 0;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = table[alignment_flag];
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushdiamond(a); 
 } 


void drawline(double mx, double my)   //画直线 
{
	myline* a=malloc(sizeof(myline));
	if (a == NULL)
	{
		exit(0);
	}
	a->x1 =mx ;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y1 =my ;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dx =0;	//两个点的纵坐标相减的绝对值为高
	a->dy =0;//两个点的横坐标相减的绝对值为宽
	a->pensize = PenSize;
	a->next = NULL;
	//a->pensize=GetPenSize();  //还有错误   还不知道怎样改变粗细 
	strcpy(a->pencolor , acolor[filled_color]);
	draw_ptr = a;
	pushline(a);
}


void drawdashline(double mx, double my)   //虚线 
{
	mydashline* a=malloc(sizeof(mydashline));
	if (a == NULL)
	{
		exit(0);
	}
	a->x1 = mx;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y1 = my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dx = 0;	//两个点的纵坐标相减的绝对值为高
	a->dy = 0;//两个点的横坐标相减的绝对值为宽
	a->pensize = PenSize;
	a->next = NULL;
	//a->pensize=GetPenSize();  //还有错误   还不知道怎样改变粗细
	strcpy(a->pencolor , acolor[filled_color]); 
	draw_ptr = a;
	pushdashline(a);
}

void drawdirectionalconnection(double mx, double my)
{
	mydirectionalconnection* a=malloc(sizeof(mydirectionalconnection));
	if (a == NULL)
	{
		exit(0);
	}
	a->x =mx;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y =my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dy =0;	//两个点的纵坐标相减的绝对值为高
	a->dx = 0;	//两个点的横坐标相减的绝对值为宽
	a->arrow_style = arrow_style;
	a->fillflag = filled_flag==1?1:0;
	a->next = NULL;
	a->pensize = PenSize;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushdirectionalconnection(a); 
}
void  drawbiddirectionalconnection(double mx, double my)
{
	mybidirectionalconnection* a = malloc(sizeof(mybidirectionalconnection));
	if (a == NULL)
	{
		exit(0);
	}
	a->x =mx;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y =my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dy = 0;	//两个点的纵坐标相减的绝对值为高
	a->dx =0;	//两个点的横坐标相减的绝对值为宽
	a->arrow_style = arrow_style;
	a->fillflag = filled_flag == 1 ? 1 : 0;
	a->next = NULL;
	a->pensize = PenSize;
	strcpy(a->fill_color, acolor[filled_color]);
	strcpy(a->front_color, acolor[front_color]);
	draw_ptr = a;
	pushbidirectionalconnection(a);
}
 
 void drawprocess(double mx, double my)  //画process 
{
		
	myprocess* a=malloc(sizeof(myprocess));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = mx;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y =my;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height = 0;	//两个点的纵坐标相减的绝对值为高
	a->width = 0;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment =  table[alignment_flag];
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushprocess(a);
}

 void drawcircle(double mx, double my)
 {
 	mycircle* a=malloc(sizeof(mycircle));
 	if(a==NULL)
 	{
 		exit(0);
	 }
	a->x=mx;	
	a->y=my;					
	a->r=0;
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = table[alignment_flag];
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushcircle(a);		
 }
 
 

 void drawoval(double mx, double my)
 {
 	myoval* a=malloc(sizeof(myoval));
 	if(a==NULL)
 	{
 		exit(0);
	 }
    a->x =mx;						
	a->y =my;						
	a->ry =0;	
	a->rx =0;	
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = table[alignment_flag];
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	draw_ptr = a;
	pushoval(a);
 }
 void drawing(double mx, double my)
 {
	 switch (draw_what)
	 {
	 case 1:
	 {
		 ((myrect*)draw_ptr)->width = mx - ((myrect*)draw_ptr)->x;
		 ((myrect*)draw_ptr)->height = my - ((myrect*)draw_ptr)->y;
		 break;
	 }
	 case 2:
	 {
		 ((myroundrect*)draw_ptr)->width = mx - ((myroundrect*)draw_ptr)->x;
		 ((myroundrect*)draw_ptr)->height = my - ((myroundrect*)draw_ptr)->y;
		 break;
	 }
	 case 3:
	 {
		 ((mydiamond*)draw_ptr)->width = mx - ((mydiamond*)draw_ptr)->x;
		 ((mydiamond*)draw_ptr)->height = my - ((mydiamond*)draw_ptr)->y;
		 break;
	 }
	 case 4:
	 {
		 ((myline*)draw_ptr)->dx = mx - ((myline*)draw_ptr)->x1;
		 ((myline*)draw_ptr)->dy = my - ((myline*)draw_ptr)->y1;
		break;
	 }
	 case 5:
	 {
		 ((mydirectionalconnection*)draw_ptr)->dx = mx - ((mydirectionalconnection*)draw_ptr)->x;
		 ((mydirectionalconnection*)draw_ptr)->dy = my - ((mydirectionalconnection*)draw_ptr)->y;
		 break;
	 }
	 case 6:
	 {
		 ((mybidirectionalconnection*)draw_ptr)->dx = mx - ((mybidirectionalconnection*)draw_ptr)->x;
		 ((mybidirectionalconnection*)draw_ptr)->dy = my - ((mybidirectionalconnection*)draw_ptr)->y;
		 break;
	 }
	 case 7:
	 {
		 ((mydashline*)draw_ptr)->dx = mx - ((mydashline*)draw_ptr)->x1;
		 ((mydashline*)draw_ptr)->dy = my - ((mydashline*)draw_ptr)->y1;
		 break;
	 }
	 case 8:
	 {
		 ((myprocess*)draw_ptr)->width = mx - ((myprocess*)draw_ptr)->x;
		 ((myprocess*)draw_ptr)->height = my - ((myprocess*)draw_ptr)->y;
		 break;
	 }
	 case 9:
	 {
		 ((mycircle*)draw_ptr)->r = sqrt(pow(mx - ((mycircle*)draw_ptr)->x, 2) + pow(my - ((mycircle*)draw_ptr)->y, 2));
		 break;
	 }
	 case 10:
	 {
		 ((myoval*)draw_ptr)->rx= mx - ((myoval*)draw_ptr)->x;
		 ((myoval*)draw_ptr)->ry = my - ((myoval*)draw_ptr)->y;
		 break;
	 }
	 }
 }

