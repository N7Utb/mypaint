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


void draw()
{
	switch (draw_what)
	{
		case 1:
		{
			drawrectangle();
			break;
		}
		case 2:
		{
			drawroundrec();
			break;
		} 
		case 3:
		{
			drawdiamond();
			break;
		}
        case 4:
        {
        	drawline();
	        	break;
		}
		case 5:
		{
			drawdirectionalconnection();
			break;
		 } 
		case 6:
		{
			drawbiddirectionalconnection();
			break;
		 }
		case 7:
		{
			drawdashline();
			break;
		}
		 case 8:
		 {
		 	drawprocess();
		 	break;
		  } 
		case 9:
		{
			drawcircle();
			break;
		}
		case 10:
		{
			drawoval();
			break;
		}
	}
}


void drawrectangle()  //画矩形 
{
		
	myrect* a=malloc(sizeof(myrect));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y = y_1 > y_2 ? y_2 : y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//两个点的纵坐标相减的绝对值为高
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = alignment_flag==0?'L':'R';
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushrect(a);
}

void drawroundrec()   //绘制圆角矩形 
{
		
	myroundrect* a=malloc(sizeof(myroundrect));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y = y_1 > y_2 ? y_2 : y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//两个点的纵坐标相减的绝对值为高
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = alignment_flag==0?'L':'R';
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushroundrect(a);
	
}

void drawdiamond() //画菱形 
{
	mydiamond* a=malloc(sizeof(mydiamond));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y = y_1 > y_2 ? y_2 : y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//两个点的纵坐标相减的绝对值为高
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = alignment_flag==0?'L':'R';
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushdiamond(a); 
 } 


void drawline()   //画直线 
{
	myline* a=malloc(sizeof(myline));
	if (a == NULL)
	{
		exit(0);
	}
	a->x1 = x_1 ;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y1 = y_1 ;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dx =x_2-x_1;	//两个点的纵坐标相减的绝对值为高
	a->dy = y_2 - y_1;//两个点的横坐标相减的绝对值为宽
	a->pensize = PenSize;
	a->next = NULL;
	//a->pensize=GetPenSize();  //还有错误   还不知道怎样改变粗细 
	strcpy(a->pencolor , acolor[filled_color]);
	pushline(a);
}


void drawdashline()   //虚线 
{
	mydashline* a=malloc(sizeof(mydashline));
	if (a == NULL)
	{
		exit(0);
	}
	a->x1 = x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y1 = y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dx = x_2 - x_1;	//两个点的纵坐标相减的绝对值为高
	a->dy = y_2 - y_1;//两个点的横坐标相减的绝对值为宽
	a->pensize = PenSize;
	a->next = NULL;
	//a->pensize=GetPenSize();  //还有错误   还不知道怎样改变粗细
	strcpy(a->pencolor , acolor[filled_color]); 
	pushdashline(a);
}

void drawdirectionalconnection()
{
	mydirectionalconnection* a=malloc(sizeof(mydirectionalconnection));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y = y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dy = y_2-y_1;	//两个点的纵坐标相减的绝对值为高
	a->dx = x_2-x_1;	//两个点的横坐标相减的绝对值为宽
	a->arrow_style = arrow_style;
	a->fillflag = filled_flag==1?1:0;
	a->next = NULL;
	a->pensize = PenSize;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushdirectionalconnection(a); 
}
void  drawbiddirectionalconnection()
{
	mybidirectionalconnection* a = malloc(sizeof(mybidirectionalconnection));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y = y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->dy = y_2 - y_1;	//两个点的纵坐标相减的绝对值为高
	a->dx = x_2 - x_1;	//两个点的横坐标相减的绝对值为宽
	a->arrow_style = arrow_style;
	a->fillflag = filled_flag == 1 ? 1 : 0;
	a->next = NULL;
	a->pensize = PenSize;
	strcpy(a->fill_color, acolor[filled_color]);
	strcpy(a->front_color, acolor[front_color]);
	pushbidirectionalconnection(a);
}
 
 void drawprocess()  //画process 
{
		
	myprocess* a=malloc(sizeof(myprocess));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//两个点中横坐标最小值为矩形左下角横坐标
	a->y = y_1 > y_2 ? y_2 : y_1;						//两个点中纵坐标最小值为矩形左下角纵坐标
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//两个点的纵坐标相减的绝对值为高
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//两个点的横坐标相减的绝对值为宽
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = alignment_flag==0?'L':'R';
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushprocess(a);
}

 void drawcircle()
 {
 	mycircle* a=malloc(sizeof(mycircle));
 	if(a==NULL)
 	{
 		exit(0);
	 }
	a->x=x_1;	
	a->y=y_1;					
	a->r=sqrt(pow(x_1-x_2,2)+pow(y_1-y_2,2));
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = alignment_flag==0?'L':'R';
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushcircle(a);		
 }
 
 

 void drawoval()
 {
 	myoval* a=malloc(sizeof(myoval));
 	if(a==NULL)
 	{
 		exit(0);
	 }
    a->x = x_1 > x_2 ? x_2 : x_1;						
	a->y = y_1 > y_2 ? y_2 : y_1;						
	a->ry = (y_1 - y_2) < 0 ? (y_2 - y_1)/2 : (y_1 - y_2)/2;	
	a->rx = (x_1 - x_2) < 0 ? (x_2 - x_1)/2: (x_1 - x_2)/2;	
	//strcpy(a->text, mytext);
	int i;
	for (i = 0; i < strlen(mytext); i++)
	{
		a->text[i] = mytext[i];
	}
	a->text[strlen(mytext)] = 0;
	a->fillflag = filled_flag==1?1:0;
	a->alignment = alignment_flag==0?'L':'R';
	a->text_flag = 1;
	a->next = NULL;
	strcpy(a->fill_color , acolor[filled_color]);
	strcpy(a->front_color , acolor[front_color]);
	pushoval(a);
 }
 

