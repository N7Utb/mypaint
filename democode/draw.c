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


void drawrectangle()  //������ 
{
		
	myrect* a=malloc(sizeof(myrect));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y = y_1 > y_2 ? y_2 : y_1;						//����������������СֵΪ�������½�������
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//�����������������ľ���ֵΪ��
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//������ĺ���������ľ���ֵΪ��
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

void drawroundrec()   //����Բ�Ǿ��� 
{
		
	myroundrect* a=malloc(sizeof(myroundrect));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y = y_1 > y_2 ? y_2 : y_1;						//����������������СֵΪ�������½�������
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//�����������������ľ���ֵΪ��
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//������ĺ���������ľ���ֵΪ��
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

void drawdiamond() //������ 
{
	mydiamond* a=malloc(sizeof(mydiamond));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y = y_1 > y_2 ? y_2 : y_1;						//����������������СֵΪ�������½�������
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//�����������������ľ���ֵΪ��
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//������ĺ���������ľ���ֵΪ��
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


void drawline()   //��ֱ�� 
{
	myline* a=malloc(sizeof(myline));
	if (a == NULL)
	{
		exit(0);
	}
	a->x1 = x_1 ;						//�������к�������СֵΪ�������½Ǻ�����
	a->y1 = y_1 ;						//����������������СֵΪ�������½�������
	a->dx =x_2-x_1;	//�����������������ľ���ֵΪ��
	a->dy = y_2 - y_1;//������ĺ���������ľ���ֵΪ��
	a->pensize = PenSize;
	a->next = NULL;
	//a->pensize=GetPenSize();  //���д���   ����֪�������ı��ϸ 
	strcpy(a->pencolor , acolor[filled_color]);
	pushline(a);
}


void drawdashline()   //���� 
{
	mydashline* a=malloc(sizeof(mydashline));
	if (a == NULL)
	{
		exit(0);
	}
	a->x1 = x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y1 = y_1;						//����������������СֵΪ�������½�������
	a->dx = x_2 - x_1;	//�����������������ľ���ֵΪ��
	a->dy = y_2 - y_1;//������ĺ���������ľ���ֵΪ��
	a->pensize = PenSize;
	a->next = NULL;
	//a->pensize=GetPenSize();  //���д���   ����֪�������ı��ϸ
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
	a->x = x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y = y_1;						//����������������СֵΪ�������½�������
	a->dy = y_2-y_1;	//�����������������ľ���ֵΪ��
	a->dx = x_2-x_1;	//������ĺ���������ľ���ֵΪ��
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
	a->x = x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y = y_1;						//����������������СֵΪ�������½�������
	a->dy = y_2 - y_1;	//�����������������ľ���ֵΪ��
	a->dx = x_2 - x_1;	//������ĺ���������ľ���ֵΪ��
	a->arrow_style = arrow_style;
	a->fillflag = filled_flag == 1 ? 1 : 0;
	a->next = NULL;
	a->pensize = PenSize;
	strcpy(a->fill_color, acolor[filled_color]);
	strcpy(a->front_color, acolor[front_color]);
	pushbidirectionalconnection(a);
}
 
 void drawprocess()  //��process 
{
		
	myprocess* a=malloc(sizeof(myprocess));
	if (a == NULL)
	{
		exit(0);
	}
	a->x = x_1 > x_2 ? x_2 : x_1;						//�������к�������СֵΪ�������½Ǻ�����
	a->y = y_1 > y_2 ? y_2 : y_1;						//����������������СֵΪ�������½�������
	a->height = (y_1 - y_2) < 0 ? y_2 - y_1 : y_1 - y_2;	//�����������������ľ���ֵΪ��
	a->width = (x_1 - x_2) < 0 ? x_2 - x_1 : x_1 - x_2;	//������ĺ���������ľ���ֵΪ��
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
 

