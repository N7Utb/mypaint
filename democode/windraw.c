#include "windraw.h"
#include "draw.h"
#include "operation.h"
#include "file.h"
#include "math.h"
#include "windraw.h"
char* bColors[] =
{
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
void Initwin()
{
	//�·�Ϊmenu�еĸ����ַ���������
	static char* menuListFile[] = { "File",
		"New  | Ctrl-N", // ��ݼ��������[Ctrl-X]��ʽ�������ַ����Ľ�β
		"Open | Ctrl-O",
		"Save | Ctrl-S",
		"Close",
		"Exit" };
	static char* menuListEdit[] = { "Edit",
		"Undo   | Ctrl-Z",
		"Redo   | Ctrl-Y",
		"Cut    | Ctrl-X",
		"Copy   | Ctrl-C",
		"Paste  | Ctrl-V",
		"Delete | Delete" };
	static char* menuListDraw[] = { "Draw",
		"Rectangle",
		"Roundrec",
		"Diamond",
		"Line",
		"directionalconnection" ,
		"bidirectionalconnection",
		"dashline",
		"process",
		"circle",
		"oval"};
	static char* menuListHelp[] = { "Help",
		"About us",
		"Short cuts list",
		"Guard"
	};
	static char* menuListColors1[] =
	{
		"Fill Colors",
		"Black(default)",
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
	static char* menuListColors2[] =
	{
		"Front Colors",
		"Black(default)",
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
	static char* menuListAli[] =
	{
		"Alignment",
		"L(default)",
		"R"
	};
	static char* menuListPenSize[] =
	{
		"PenSize",
		"1",
		"2",
		"3",
		"4",
		"5"
	};
	static char* menuListArrowstyle[] =
	{
		"Arrowstyle",
		"1",
		"2",
	};
	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double w = TextStringWidth(menuListFile[0]) * 4; // ���˵����
	double wlist = TextStringWidth(menuListFile[1]) * 1.2;
	double xindent = winheight / 20; // ����
	int    selection;
	int enable_move_disc = 1;
	// menu bar
	h = fH * 1.5; // �ؼ��߶�
	DefineColor("Black", 0, 0, 0);
	SetPenColor("Black");
	//�����������ڵĸ�������
	//���ڵ��Եĳߴ����⣬���ܴ��ڻ��в��ֵ�ס��������Ҫ�ֶ���ק���������
	drawRectangle(x, y - 2 * h, winwidth, h, 0);
	drawRectangle(x, 0, 10 * h, winheight - 2 * h, 0);
	drawRectangle(10 * h, 0, winwidth - 8 * h, h, 0);
	//��������ɫ����Ϊ����
	SetPenColor("Light Gray");
	drawRectangle(10 * h, h, 8 * h, winheight - 3 * h, 1);
	drawRectangle(winwidth - 8 * h, h, 8 * h, winheight - 3 * h, 1);
	setMenuColors("Dark Gray", "White", "Black", "Yellow", 1);
	drawMenuBar(0, y - h, winwidth, h);
	//File�˵���
	selection = menuList(GenUIID(0), x, y - h, w, wlist, h, menuListFile, sizeof(menuListFile) / sizeof(menuListFile[0]));

	if (selection == 1)
	{
		system("demo.exe");//�������иó���
	}
	else if (selection == 2)
	{
		open();
	}
	else if (selection == 3)
	{
		save();
	}
	else if (selection == 4)
	{
		//close�൱�ڽ���ǰ���ڹرգ�ѯ���Ƿ񱣴��ļ�
		int k = MessageBox(NULL, "your file was not save yet, do you want to save and quit right now", "Waring", MB_YESNOCANCEL | MB_ICONINFORMATION / MB_ICONASTERISK);
		if (k==IDYES)
		{
			if (save() == 1)		//����û�ѡ���ǲ���ѡ���˱���·���򱣴����֮���˳�����
			{
				exit(0);
				
			}						//���δѡ�񱣴�·�������·���
			
		}
		else if(k==IDNO)		//����û�ѡ���˷���ֱ���˳�
		{
			exit(0);
		}
		
	}
	else if (selection == 5)
	{
		exit(0);						//quit��ֱ���˳�
	}
	// Edit �˵�
	selection = menuList(GenUIID(0), x + w, y - h, 2*w, 2*wlist, h, menuListEdit, sizeof(menuListEdit) / sizeof(menuListEdit[0]));
	if (selection == 6)
	{
		if (operate_flag == 2)
		{
			pop();
			operate_flag = 0;
		}
	}
	//Draw �˵�
	selection = menuList(GenUIID(0), x + 3 * w, y - h,2* w, 2*wlist, h, menuListDraw, sizeof(menuListDraw) / sizeof(menuListEdit[0]));
	if (selection == 1)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 1;
	}
	else if (selection == 2)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 2;
	}
	else if (selection == 3)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 3;
	}
	else if (selection == 4)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 4;
	}
	else if (selection == 5)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 5;
	}
	else if (selection == 6)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 6;
	}
	else if (selection == 7)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 7;
	}
	else if (selection == 8)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 8;
	}
	else if (selection == 9)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 9;
	}
	else if (selection == 10)
	{
		operate_flag = 1;
		click_count = 0;
		draw_what = 10;
	}
	// Help �˵�
	selection = menuList(GenUIID(0), x + 5 * w, y - h, 2*w, 2*wlist, h, menuListHelp, sizeof(menuListHelp) / sizeof(menuListHelp[0]));
	drawMenuBar(44 * h, y - 2 * h, 10 * h, h);
	selection = menuList(GenUIID(0), 44 * h, y - 2 * h, w, wlist, h, menuListColors1, sizeof(menuListColors1) / sizeof(menuListColors1[0]));
	if (selection)
	{
		filled_color = selection-1;
		if (operate_flag == 2)
		{
			changefillcolor(filled_color);
			
			
		}
	}
	selection = menuList(GenUIID(0), 44 * h+w, y -2*  h, w, wlist, h, menuListColors2, sizeof(menuListColors2) / sizeof(menuListColors2[0]));
	if (selection)
	{
		front_color = selection - 1;
		if (operate_flag == 2)
		{
			changefontcolor(selection);
			
			
		}
	}
	selection = menuList(GenUIID(0), 44 * h+2*w, y - 2 * h, w, wlist, h, menuListAli, sizeof(menuListAli) / sizeof(menuListAli[0]));
	if (selection)
	{
		alignment_flag = selection - 1;
		if (operate_flag == 2)
		{
			changealigment(alignment_flag == 0 ? 'L' : 'R');
		}
	}
	selection = menuList(GenUIID(0), 44 * h + 3 * w, y - 2 * h, w, wlist, h, menuListPenSize, sizeof(menuListPenSize) / sizeof(menuListAli[0]));
	if (selection)
	{
		PenSize = selection;
		if (operate_flag == 2)
		{
			switch (select_what)
			{
			case 4:
			{
				selected_line->pensize = selection;
				break;
			}
			case 5:
			{
				selected_directionalconnection->pensize = selection;
				break;
			}
			case 6:
			{
				selected_bidirectionalconnection->pensize = selection;
				break;
			}
			case 7:
			{
				selected_dashline->pensize = selection;
				break;
			}
			}
		}
	}
	selection = menuList(GenUIID(0), 44 * h -w, y - 2 * h, w, wlist, h, menuListArrowstyle, sizeof(menuListArrowstyle) / sizeof(menuListArrowstyle[0]));
	if (selection)
	{
		arrow_style = selection - 1;
		if (operate_flag == 2)
		{
			switch (select_what)
			{
			case 5:
			{
				selected_directionalconnection->arrow_style = arrow_style;
			}
			case 6:
			{
				selected_bidirectionalconnection->arrow_style = arrow_style;
			}
			}
		}
	}
}
void InitButton()
{
	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double xindent = winheight / 20; // ����
	int    selection;
	int enable_move_disc = 1;
	setButtonColors("Light Gray", "Black", "Dark Gray", "Yellow", 1);
	if (button(GenUIID(0), 27 * h, y - 2 * h, 6*h, h, "Clockwise Rotate"))
	{
		// undo button
	}

	if (button(GenUIID(0), 33 * h, y - 2 * h, 6*h, h, "AntiClockwise Rotate"))
	{
		//redo button
	}
	if (button(GenUIID(0), 3 * h, y - 2 * h, 4 * h, h, "Save"))
	{
		//Save button
	}
	if (button(GenUIID(0), 7 * h, y - 2 * h, 4 * h, h, "Open"))
	{
		//Open button
	}
	if (button(GenUIID(0), 11 * h, y - 2 * h, 4 * h, h, "Delete"))
	{
		if (operate_flag == 2)
		{
			pop();
			operate_flag = 0;
		}
	}
	if (button(GenUIID(0), 15 * h, y - 2 * h, 4 * h, h, "Cut"))
	{
		//whether use grid lines
	}
	if (button(GenUIID(0), 19 * h, y - 2 * h, 4 * h, h, "Copy"))
	{
		//
	}
	if (button(GenUIID(0), 23 * h, y - 2 * h, 4 * h, h, "Paste"))
	{
		//whether use grid lines
	}
	setButtonColors("Light Gray", "Black", "Dark Gray", "Black", 0);
	if (button(GenUIID(0), 0, y - 4 * h, 10 * h, 2 * h, "Rectangle"))
	{

		//draw Rectangle
		operate_flag = 1;
		click_count = 0;
		draw_what = 1;
	}
	if (button(GenUIID(0), 0, y - 6 * h, 10 * h, 2 * h, "Roundrec"))
	{
		//draw roundrec
		operate_flag = 1;
		click_count = 0;
		draw_what = 2;
	}
	if (button(GenUIID(0), 0, y - 8 * h, 10 * h, 2 * h, "Diamond"))
	{
		//draw diamond
		operate_flag = 1;
		click_count = 0;
		draw_what = 3;
	}
	if (button(GenUIID(0), 0, y - 10 * h, 10 * h, 2 * h, "Line"))
	{
		//draw line
		operate_flag = 1;
		click_count = 0;
		draw_what = 4;
	}
	if (button(GenUIID(0), 0, y - 12 * h, 10 * h, 2 * h, "Directional connection"))
	{
		//draw directional connection �����ͷ
		operate_flag = 1;
		click_count = 0;
		draw_what = 5;
	}
	if (button(GenUIID(0), 0, y - 14 * h, 10 * h, 2 * h, "Bidirectional connection"))
	{
		//draw ˫���ͷ
		operate_flag = 1;
		click_count = 0;
		draw_what = 6;
	}
	if (button(GenUIID(0), 0, y - 16 * h, 10 * h, 2 * h, "Dashed line"))
	{
		//draw dashed line ����
		operate_flag = 1;
		click_count = 0;
		draw_what = 7;
	}
	if (button(GenUIID(0), 0, y - 18 * h, 10 * h, 2 * h, "Parallelogram"))
	{
         //draw process
		operate_flag = 1;
		click_count = 0;
		draw_what = 8 ;
	}
	if (button(GenUIID(0), 0, y - 20 * h, 10 * h, 2 * h, "Circle"))
	{
        //draw circle  Բ
		operate_flag = 1;
		click_count = 0;
		draw_what = 9;
	}
	if (button(GenUIID(0), 0, y - 22 * h, 10 * h, 2 * h, "Oval"))
	{
        //draw oval  ��Բ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 10;
	}
	setButtonColors("Light Gray", "Black", "Dark Gray", "Black", 0);
	if (filled_flag==1)
	{
		if (button(GenUIID(0), 10 * h, 0, 4 * h, h, "filled"))
		{
			filled_flag *= -1;
			if (operate_flag == 2)
			{
				changefillflag(filled_flag == 1 ? 1 : 0);
			}
		}
	}
	else
	{
		if (button(GenUIID(0), 10 * h, 0, 4 * h, h, "unfilled"))
		{
			filled_flag *= -1;
			if (operate_flag == 2)
			{
				changefillflag(filled_flag == 1 ? 1 : 0);
			}
		}
	}
	if (operate_flag == 0)
		drawLabel(winwidth - 6 * h, 0.25 * h, "No operation");
	else if (operate_flag == 1)
		drawLabel(winwidth - 6 * h, 0.25 * h, "Drawing");
	else if (operate_flag == 2)
		drawLabel(winwidth - 6 * h, 0.25 * h, "Selecting");
	else if (operate_flag == 3)
		drawLabel(winwidth - 6 * h, 0.25 * h, "Moving");
	drawLabel(winwidth - 13 * h, 0.25 * h, "Front Color:");
	drawLabel(winwidth - 9.5 * h, 0.25 * h, bColors[front_color]);
	drawLabel(winwidth - 19 * h, 0.25 * h, "Fill Color:");
	drawLabel(winwidth - 16 * h, 0.25 * h, bColors[filled_color]);
	if (textbox(GenUIID(0), 18 * h, 0, 10 * h, h, mytext, 100))
	{
		if (operate_flag == 2)
		{
			switch (select_what)
			{
			case 1:
			{
				strcpy(selected_rect->text, mytext);
				break;
			}
			case 2:
			{
				strcpy(selected_roundrect->text, mytext);
				break;
			}
			case 3:
			{
				strcpy(selected_diamond->text, mytext);
				break;
			}
			}
		}
	}

}



/* ��һ��Բ�Ǿ��� */
void drawRoundrec(double x, double y, double w, double h, int fillflag)
{
	MovePen(x, y);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawLine(w, 0);
		DrawEllipticalArc(w/6,h/6, 270, 90);
		DrawLine(0, h);
		DrawEllipticalArc(w/6,h/6, 0, 90);
		DrawLine(-w, 0);
		DrawEllipticalArc(w/6,h/6, 90, 90);
		DrawLine(0, -h);
		DrawEllipticalArc(w/6,h/6, 180, 90);
	}
	if( fillflag ) EndFilledRegion();
}

/* ��һ������ */
void drawDiamond(double x, double y, double w, double h, int fillflag)
{
	MovePen(x, y+h/2);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawLine(w/2, h/2);
		DrawLine(w/2, -h/2);
		DrawLine(-w/2, -h/2);
		DrawLine(-w/2, h/2);
	}
	if( fillflag ) EndFilledRegion();
}

/*��һ��Բ */
void drawCircle(double x, double y, double r,int fillflag)
{
	
    MovePen(x + r, y);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawArc(r, 0, 360);
	}
	if( fillflag ) EndFilledRegion();
	
 } 


/* ��һ��ֱ�� */
void drawLine(double x1,double y1,double dx,double dy)
{ 
	MovePen(x1, y1);
	DrawLine(dx, dy);
}

/*��һ������ */ 
void drawDashline(double x1,double y1,double dx, double dy)
{
	int i;
	double ddx=dx/10;   
	double ddy=dy/10;
	for(i=0;i<10;i+=2)
	{
		MovePen(x1+i*ddx,y1+i*ddy);
		DrawLine(dx/10,dy/10);
	}
	 
}
/*��һ�������ͷ*/ 
void drawDirectionalconnection(double x, double y, double dx, double dy, int fillflag, int arrow_style)
{
	
	MovePen( x,  y);
	double sin =  dy / (sqrt( dy *  dy +  dx *  dx));
	double cos =  dx / (sqrt( dy *  dy +  dx *  dx));
	double length =  sqrt(dy * dy + dx * dx);
	if ( arrow_style == 1)
	{
		if ( fillflag) StartFilledRegion(1);
		
			DrawLine(length * 0.05*sin, -cos * length * 0.05);
			DrawLine(0.9 * length * cos, 0.9 * length * sin);
			DrawLine(length * 0.05*sin, -cos * length * 0.05);
			DrawLine(dx - 0.9 * length * cos - length * 0.1*sin, dy - 0.9 * length * sin + cos* length * 0.1);
			DrawLine(-dx +0.9 * length * cos - length * 0.1 * sin, -dy + 0.9 * length * sin + cos * length * 0.1);
			DrawLine(length * 0.05 * sin, -cos * length * 0.05);
			DrawLine(-0.9 * length * cos, -0.9 * length * sin);
			DrawLine(length * 0.05 * sin, -cos * length * 0.05);
			
		if ( 	fillflag) EndFilledRegion();
	}
	else
	{
		DrawLine( dx,  dy);
		DrawLine(0.1*length* (-0.65 * cos - 0.5 * sin), 0.1 * length*( -0.65 * sin + 0.5 * cos));
		MovePen(x + dx, y + dy);
		DrawLine(0.1 * length * (-0.65 * cos + sin * 0.5), 0.1 * length * (-sin * 0.65 - cos * 0.5));
	}
}

/*��һ��˫���ͷ*/ 
void drawBidirectionalconnection(double x, double y, double dx, double dy, int fillflag, int arrow_style)
{
	double sin = dy / (sqrt(dy * dy + dx * dx));
	double cos = dx / (sqrt(dy * dy + dx * dx));
	double length = sqrt(dy * dy + dx * dx);
	drawDirectionalconnection(x+0.5*dx, y+0.5*dy, 0.5*dx, 0.5*dy, fillflag, arrow_style);
	drawDirectionalconnection(x+0.5*dx, y+0.5*dy, -0.5*dx, -0.5*dy, fillflag, arrow_style);
}

/*��һ����Բ*/ 
void drawOval(double x, double y, double rx,double ry,int fillflag)
{
	
    MovePen(x + 2*rx, y+ry);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawEllipticalArc(rx, ry, 0, 360);
	}
	if( fillflag ) EndFilledRegion();
	
 } 
/* ��һ��process */
void drawProcess(double x, double y, double w, double h, int fillflag)
{
	MovePen(x, y);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawLine(w*0.75, 0);
		DrawLine(w*0.25, h);
		DrawLine(-w*0.75, 0);
		DrawLine(-w*0.25, -h);
	}
	if( fillflag ) EndFilledRegion();
	    

	
}


/* ��һ��Բ�Ǿ��Σ��������ڲ�������ʾһ���ַ�����ǩlabel */
void drawRoundrecBox(double x, double y, double w, double h, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();   //����Ҳ�֪������� 
	//roundrec 
	drawRoundrec(x,y,w,h,fillflag);
	// text
	if( label && strlen(label)>0 ) {
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+h/2-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+w-fa/2-TextStringWidth(label), y+h/2-fa/2);
		else // if( labelAlignment=='C'
			MovePen(x+(w-TextStringWidth(label))/2, y+h/2-fa/2);
		DrawTextString(label);
	}
}

/* ��һ�����Σ��������ڲ�������ʾһ���ַ�����ǩlabel */
void drawDiamondBox(double x, double y, double w, double h, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();
	// diamond 
	drawDiamond(x,y,w,h,fillflag);
	// text
	if( label && strlen(label)>0 ) {
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+h/2-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+w-fa/2-TextStringWidth(label), y+h/2-fa/2);
		else // if( labelAlignment=='C'
			MovePen(x+(w-TextStringWidth(label))/2, y+h/2-fa/2);
		DrawTextString(label);
	}
}

/* ��һ��Բ�Σ��������ڲ�������ʾһ���ַ�����ǩlabel */
void drawCircleBox(double x, double y, double r, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();
	// circle 
	drawCircle(x,y,r,fillflag);
	// text
	if( label && strlen(label)>0 )
	 {
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+r/2-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+r-fa/2-TextStringWidth(label), y+r/2-fa/2);
		else // if( labelAlignment=='C'
			MovePen(x+(r-TextStringWidth(label))/2, y+r/2-fa/2);
		DrawTextString(label);
	}   
}

/* ��һ��oval���������ڲ�������ʾһ���ַ�����ǩlabel */
void drawOvalBox(double x, double y, double rx, double ry, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();
	// oval 
	drawOval(x,y,rx,ry,fillflag);
	// text
	if( label && strlen(label)>0 ) {
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+ry-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+2*rx-fa/2-TextStringWidth(label), y+ry-fa/2);
		else // if( labelAlignment=='C'
			MovePen(x+(2*rx-TextStringWidth(label))/2, y+ry-fa/2);
		DrawTextString(label);
	}
}
/* ��һ��process���������ڲ�������ʾһ���ַ�����ǩlabel */
void drawProcessBox(double x, double y, double w, double h, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();
	// process
	drawProcess(x,y,w,h,fillflag);
	// text
	if( label && strlen(label)>0 ) {
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+h/2-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+w-fa/2-TextStringWidth(label), y+h/2-fa/2);
		else // if( labelAlignment=='C'
			MovePen(x+(w-TextStringWidth(label))/2, y+h/2-fa/2);
		DrawTextString(label);
	}
}
void display()
{
	//clear
	DisplayClear();
	InitButton();
	drawlinklist1();
	drawlinklist2();
	drawlinklist3();
	drawlinklist4();
	drawlinklist5();
	drawlinklist6();
	drawlinklist7();
	drawlinklist8();
	drawlinklist9();
	drawlinklist10();
	Initwin();
}
void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key, event); // GUI��ȡ����


}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	double mx, my;
	uiGetMouse(x, y, button, event); //GUI��ȡ���
	mx = ScaleXInches(x);/*pixels --> inches*/
	my = ScaleYInches(y);/*pixels --> inches*/
	display();
	switch(event)
	{
		case BUTTON_DOWN:
		{
			if (button == RIGHT_BUTTON)
			{										
				if(operate_flag!=0)
					operate_flag = 0;
			}
			else if (button == LEFT_BUTTON)
			{
				if (operate_flag == 1)
				{
					if (mx > 18 * h && mx < winwidth - 8 * h && my<winheight - 3 * h && my>h)//������ڻ����������
					{
						if (click_count == 0)				//����ʱ��ȡ��һ����ʱ��mx,myΪ���ϵ�
						{
							click_count = 1;
							x_1 = mx;
							y_1 = my;
						}
						else
						{
							click_count = 2;
							x_2 = mx;
							y_2 = my;
							draw();
							display();
							click_count = 0;
							operate_flag = 0;
						}
					}
				}								
				else if (operate_flag == 0)
				{
					if (mx > 18 * h && mx < winwidth - 8 * h && my<winheight - 3 * h && my>h)//������ڻ����������
					{
						if (click_count == 0)								//�������е�rect�ṹ��ȷ��ѡ�е�rect
						{
							select_graphic(mx,my);
							break;
						}
					}
				}
				else if (operate_flag == 2)
				{
					if (select_graphic(mx,my))
					{
						operate_flag = 3;
						x_1 = mx;
						y_1 = my;
						break;
					}

				}
			}
			break;
		}
		case BUTTON_UP:
		{
			if (button == LEFT_BUTTON)
			{
				if (operate_flag == 3)
				{
					operate_flag = 2;
				}
			}
			break;
		}
		case MOUSEMOVE:
		{
			if (operate_flag == 3)
			{
				move( mx - x_1, my - y_1);
				y_1 = my;
				x_1 = mx;
			}
			break;
		}
		case ROLL_UP:
		{
			if (operate_flag == 2)
			{
				upper();						
				break;
			}
			break;
		}
		case ROLL_DOWN:
		{
			if (operate_flag == 2)
			{
				downer();
				break;
			}
			break;
		}
	}
}

// �û��ļ�ʱ��ʱ����Ӧ����
void TimerEventProcess(int timerID)
{
	if (2019 == timerID)
	{
		display();
	}
}
void drawlinklist1()//n ��linklist�д����Ÿ���ͼԪ��ÿ��display���Ὣ���������е�ͼԪ���
{
	myrect* p = rect_head->next;
	while (p != NULL)
	{
		SetPenColor(p->fill_color);
		drawBox(p->x, p->y, p->width, p->height, p->fillflag, p->text, p->alignment, p->front_color);
		//drawRectangle(p->x, p->y, p->width, p->height, p->fillflag);
		p = p->next;

	}
	return;
}
void drawlinklist2()
{
	myroundrect* p = roundrect_head->next;
	while (p != NULL)
	{
		
		SetPenColor(p->fill_color);
		drawRoundrecBox(p->x, p->y, p->width, p->height, p->fillflag, p->text, p->alignment, p->front_color);
		//drawRoundrec(p->x, p->y, p->width, p->height, p->fillflag);
		p = p->next;
	}
	return;
}
void drawlinklist3()
{
	mydiamond* p = diamond_head->next;
	while (p != NULL)
	{
		
		SetPenColor(p->fill_color);
		drawDiamondBox(p->x, p->y, p->width, p->height, p->fillflag, p->text, p->alignment, p->front_color);
		//drawDiamond(p->x, p->y, p->width, p->height, p->fillflag);
		p = p->next;
	}
	return;
}
void drawlinklist4()
{
	myline* p = line_head->next;
	while (p != NULL)
	{
		
		SetPenColor(p->pencolor);
		SetPenSize(p->pensize);
		drawLine(p->x1, p->y1, p->dx,p->dy);
		SetPenSize(1);
		p = p->next;
	}
	return;
}
void drawlinklist7()
{
	mydashline* p = dashline_head->next;
	while (p != NULL)
	{
		
		SetPenColor(p->pencolor);
		SetPenSize(p->pensize);
		drawDashline(p->x1, p->y1, p->dx, p->dy);
		SetPenSize(1);
		p = p->next;
	}
	return;
}
void drawlinklist5()
{
	mydirectionalconnection* p = directionalconnection_head->next;
	while (p != NULL)
	{
		SetPenColor(p->fill_color);
		SetPenSize(p->pensize);
		drawDirectionalconnection(p->x,p->y,p->dx,p->dy,p->fillflag,p->arrow_style);
		p = p->next;
		SetPenSize(1);

	}
	return;
}
void drawlinklist6()
{
	mybidirectionalconnection* p = bidirectionalconnection_head->next;
	while (p != NULL)
	{
		SetPenSize(p->pensize);
		SetPenColor(p->fill_color);
		drawBidirectionalconnection(p->x, p->y, p->dx, p->dy, p->fillflag,p->arrow_style);
		p = p->next;
		SetPenSize(1);
	}
	return;
}
void drawlinklist8()
{
	myprocess* p = process_head->next;
	while (p != NULL)
	{
		SetPenColor(p->fill_color);
		drawProcessBox(p->x, p->y, p->width, p->height, p->fillflag, p->text, p->alignment, p->front_color);
		//drawProcess//
		p = p->next;

	}
	return;
}
void drawlinklist9()
{
	mycircle* p = circle_head->next;
	while (p != NULL)
	{
		SetPenColor(p->fill_color);
		drawCircleBox(p->x, p->y, p->r, p->fillflag, p->text, p->alignment, p->front_color);
		//drawCircle//
		p = p->next;

	}
	return;
}

void drawlinklist10()
{
	myoval* p = oval_head->next;
	while (p != NULL)
	{
		SetPenColor(p->fill_color);
		drawOvalBox(p->x, p->y, p->rx, p->ry, p->fillflag, p->text, p->alignment, p->front_color);
		//drawOval
		p = p->next;

	}
	return;
}
int  select_graphic(double mx,double my)
{
	myrect* p = rect_head->next;
	while (p != NULL)
	{
		if (mx >= p->x && mx <= (p->x + p->width) && my >= p->y && my <= (p->y + p->height))
		{
			operate_flag = 2;
			selected_rect = p;
			select_what = 1;
			return 1;
		}
		p = p->next;
	}
	myroundrect* q = roundrect_head->next;
	while (q != NULL)
	{
		if (mx >= q->x && mx <= (q->x + q->width) && my >= q->y && my <= (q->y + q->height))
		{
			operate_flag = 2;
			selected_roundrect = q;
			select_what = 2;
			return 1;
		}
		q = q->next;
	}
	myline* o = line_head->next;
	while (o != NULL)
	{
		if ((my>=(o->dy*(mx-o->x1)/o->dx+o->y1-0.1))&& (my <= (o->dy * (mx - o->x1) / o->dx + o->y1 + 0.1)))
		{
			operate_flag = 2;
			selected_line= o;
			select_what = 4;
			return 1;
		}
		o = o->next;
	}
	mydiamond* s = diamond_head->next;
	while (s != NULL)
	{
		if (mx >= s->x && mx <= (s->x + s->width) && my >= s->y && my <= (s->y + s->height))
		{
			operate_flag = 2;
			selected_diamond = s;
			select_what = 3;
			return 1;
		}
		s = s->next;
	}
	
	mydirectionalconnection* t = directionalconnection_head->next;
	while (t != NULL)
	{
		if ((my >= (t->dy * (mx - t->x) / t->dx + t->y - 0.1)) && (my <= (t->dy * (mx - t->x) / t->dx + t->y + 0.1)))
		{
			operate_flag = 2;
			selected_directionalconnection = t;
			select_what = 5;
			return 1;
		}
		t = t->next;
	}

	mybidirectionalconnection* u = bidirectionalconnection_head->next;
	while (u != NULL)
	{
		if ((my >= (u->dy * (mx - u->x) / u->dx + u->y - 0.1)) && (my <= (u->dy * (mx - u->x) / u->dx + u->y + 0.1)))
		{
			operate_flag = 2;
			selected_bidirectionalconnection = u;
			select_what = 6;
			return 1;
		}
		u = u->next;
	}

	myprocess* v = process_head->next;
	while (v != NULL)
	{
		if (mx >= v->x && mx <= (v->x + v->width) && my >= v->y && my <= (v->y + v->height))
		{
			operate_flag = 2;
			selected_process = v;
			select_what = 8;
			return 1;
		}
		v = v->next;
	}
	mydashline* w = dashline_head->next;
	while (w != NULL)
	{
		if ((my >= (w->dy * (mx - w->x1) / w->dx + w->y1 - 0.1)) && (my <= (w->dy * (mx - w->x1) / w->dx + w->y1 + 0.1)))
		{
			operate_flag = 2;
			selected_dashline = w;
			select_what = 7;
			return 1;
		}
		w = w->next;
	}
	mycircle* x = circle_head->next;
	while (x != NULL)
	{
		double distance = sqrt((mx - x->x) * (mx - x->x) + (my - x->y) * (my - x->y));
		if (distance <= x->r)
		{
			operate_flag = 2;
			selected_circle = x;
			select_what = 9;
			return 1;
		}
		x = x->next;
	}
	myoval* y = oval_head->next;
	while (y != NULL)
	{
		if ((pow(mx-y->x-y->rx,2)/pow(y->rx,2) + pow(my-y->y-y->ry,2)/pow(y->ry,2))<= 1)
		{
			operate_flag = 2;
			selected_oval = y;
			select_what = 10;
			return 1;
		}
		y = y->next;
	}
	
	return 0;
}
