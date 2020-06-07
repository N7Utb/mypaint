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
		"Font Colors",
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
		"L",
		"R",
		"C(default)"
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
	if (selection == 4)
	{
		if (operate_flag == 2)
		{
			pop();
			operate_flag = 0;
		}
	}
	else if (selection == 1)
	{
		if (operate_flag == 2)
		{
			cut();
		}
	}
	else if (selection == 2)
	{
		if (operate_flag == 2)
		{
			copy();
		}
	}
	else if (selection == 3)
	{
		if (operate_flag == 2)
		{
			paste();
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
	if (selection == 1)
	{
		//system("notepad Aboutus.txt");
		//About us ���ܣ�������ȷ��ʱ�����������ǰ��github�ֿ���ҳ
		if (MessageBox(NULL, "About us\nBased on libgraphics, we design process - drawing.\n\nAnd now we can provide you with a full - featured drawing tool, which support drawingand editing some simple algorithm flow charts, with file savingand reading functions.\n\nIt has a cleanand simple interfaceand is easy to use.I hope you will like it.\n\nNow you can have a try with graphics!\n\n go to github and know more about us", "About us", MB_OKCANCEL) == IDOK)
		{
			system("start https://github.com/Vainlory/mypaint.git");
		}
	}
	else if (selection == 2)
	{
		if(MessageBox(NULL,"Copy | Ctrl+C\nPaste | Ctrl+V\nDelete | Delete\nSave | Ctrl+S\nNew | Ctrl+N\nOpen | Ctrl+O\nWant to see more please go to our home","Shortcut List",MB_OKCANCEL)==IDOK)
		{
			system("start https://github.com/Vainlory/mypaint.git");
		}
	}
	else if (selection == 3)
	{
		if (MessageBox(NULL, "You know how to use this application,right?\nWhat?You don't know?Really?\nOK,We can't say how to use this application in two lines\n and as the ususal you can goto our page\nI don't think you will click at this OK button \n ","I don't want to say this anymore", MB_OKCANCEL) == IDOK)
		{
			system("start https://github.com/Vainlory/mypaint.git");
		}
	}
	drawMenuBar(44 * h, y - 2 * h, 10 * h, h);
	//�����ɫ�˵�
	selection = menuList(GenUIID(0), 44 * h, y - 2 * h, w, wlist, h, menuListColors1, sizeof(menuListColors1) / sizeof(menuListColors1[0]));
	if (selection)
	{
		filled_color = selection-1;
		if (operate_flag == 2)
		{
			changefillcolor(filled_color);
			
			
		}
	}
	//������ɫ�˵�
	selection = menuList(GenUIID(0), 44 * h+w, y -2*  h, w, wlist, h, menuListColors2, sizeof(menuListColors2) / sizeof(menuListColors2[0]));
	if (selection)
	{
		front_color = selection - 1;
		if (operate_flag == 2)
		{
			changefontcolor(selection);
			
			
		}
	}
	//����˵�
	selection = menuList(GenUIID(0), 44 * h + 2 * w, y - 2 * h, w, wlist, h, menuListAli, sizeof(menuListAli) / sizeof(menuListAli[0]));
	if (selection)
	{
		alignment_flag = selection - 1;
		if (operate_flag == 2)
		{
			changealigment(table[alignment_flag]);
		}
	}
	//�߿�˵�
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
				((myline*)select_ptr)->pensize = selection;
				break;
			}
			case 5:
			{
				((mydirectionalconnection*)select_ptr)->pensize = selection;
				break;
			}
			case 6:
			{
				((mybidirectionalconnection*)select_ptr)->pensize = selection;
				break;
			}
			case 7:
			{
				((mydashline*)select_ptr)->pensize = selection;
				break;
			}
			}
		}
	}
	//��ͷ��ʽ�˵�
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
				((mydirectionalconnection*)select_ptr)->arrow_style = arrow_style;
				break;
			}
			case 6:
			{
				((mybidirectionalconnection*)select_ptr)->arrow_style = arrow_style;
				break;
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
	//��ѡ�е�ͼ�ν�����ת��ť
	if (button(GenUIID(0), 24 * h, y - 2 * h, 6 * h, h, "Clockwise Rotate"))
	{
		if (operate_flag == 2)
		{
			clockwiserotate();
		}
	}

	if (button(GenUIID(0), 30 * h, y - 2 * h, 6 * h, h, "AntiClockwise Rotate"))
	{
		if (operate_flag == 2)
		{
			anticlockwiserotate();
		}
	}
	if (button(GenUIID(0), 36*h, y - 2 * h, 2*h, h, "Enlarge"))
	{
		if (operate_flag == 2)
		{
			upper();
		}
	}
	if (button(GenUIID(0), 38 * h, y - 2 * h, 2 * h, h, "Reduce"))
	{
		if (operate_flag == 2)
		{
			downer();
		}
	}
	if (button(GenUIID(0), 0, y - 2 * h, 4 * h, h, "Save"))
	{
		save();
	}
	if (button(GenUIID(0), 4 * h, y - 2 * h, 4 * h, h, "Open"))
	{
		open();
	}
	//��ѡ�е�ͼ�ν���ɾ����ť
	if (button(GenUIID(0), 8 * h, y - 2 * h, 4 * h, h, "Delete"))
	{
		if (operate_flag == 2)
		{
			pop();
			operate_flag = 0;
		}
	}
	if (button(GenUIID(0), 12 * h, y - 2 * h, 4 * h, h, "Cut"))
	{
		//cut����
		if (operate_flag == 2)
		{
			cut();
		}
	}
	if (button(GenUIID(0), 16 * h, y - 2 * h, 4 * h, h, "Copy"))
	{
		if (operate_flag == 2)
		{
		//copy���� 
			copy();
		}
	}
	if (button(GenUIID(0), 20 * h, y - 2 * h, 4 * h, h, "Paste"))
	{
		if (copy_ptr != NULL)
		{
		//paste���� 
			paste();
		}
	}
	setButtonColors("Light Gray", "Black", "Dark Gray", "Black", 0);
	if (button(GenUIID(0), 0, y - 4 * h, 10 * h, 2 * h, "Rectangle"))
	{

		//draw Rectangle ������ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 1;
	}
	if (button(GenUIID(0), 0, y - 6 * h, 10 * h, 2 * h, "Roundrec"))
	{
		//draw roundrec ��Բ�Ǿ��� 
		operate_flag = 1;
		click_count = 0;
		draw_what = 2;
	}
	if (button(GenUIID(0), 0, y - 8 * h, 10 * h, 2 * h, "Diamond"))
	{
		//draw diamond ������ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 3;
	}
	if (button(GenUIID(0), 0, y - 10 * h, 10 * h, 2 * h, "Line"))
	{
		//draw line ��ֱ�� 
		operate_flag = 1;
		click_count = 0;
		draw_what = 4;
	}
	if (button(GenUIID(0), 0, y - 12 * h, 10 * h, 2 * h, "Directional connection"))
	{
		//draw directional connection �������ͷ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 5;
	}
	if (button(GenUIID(0), 0, y - 14 * h, 10 * h, 2 * h, "Bidirectional connection"))
	{
		//draw bidirectional connection  ��˫���ͷ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 6;
	}
	if (button(GenUIID(0), 0, y - 16 * h, 10 * h, 2 * h, "Dashed line"))
	{
		//draw dashed line ������ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 7;
	}
	if (button(GenUIID(0), 0, y - 18 * h, 10 * h, 2 * h, "Parallelogram"))
	{
		//draw process ������ͼ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 8;
	}
	if (button(GenUIID(0), 0, y - 20 * h, 10 * h, 2 * h, "Circle"))
	{
		//draw circle ��Բ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 9;
	}
	if (button(GenUIID(0), 0, y - 22 * h, 10 * h, 2 * h, "Oval"))
	{
		//draw oval ����Բ 
		operate_flag = 1;
		click_count = 0;
		draw_what = 10;
	}
	setButtonColors("Light Gray", "Black", "Dark Gray", "Black", 0);
	//�Ƿ���䰴ť
	if (filled_flag == 1)
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
	//�Ƿ񲥷����ְ�ť 
	if (music_flag == 0)
	{
		if (button(GenUIID(0), 14 * h, 0, 4 * h, h, "Silent"))
		{
			music_flag = 1;
			mciSendString("play a repeat", NULL, 0, NULL);  
		}
		
	}
	else if (music_flag == 1)
	{
		if (button(GenUIID(0), 14 * h, 0, 4 * h, h, "Music on"))
		{
			music_flag = 0;
			mciSendString("stop a", NULL, 0, NULL);
		}
	}
		//�·�����״̬��
	if (operate_flag == 0)
		drawLabel(winwidth - 6 * h, 0.25 * h, "No operation");
	else if (operate_flag == 1)
		drawLabel(winwidth - 6 * h, 0.25 * h, "Drawing");
	else if (operate_flag == 2)
		drawLabel(winwidth - 6 * h, 0.25 * h, "Selecting");
	else if (operate_flag == 3)
		drawLabel(winwidth - 6 * h, 0.25 * h, "Moving");
	//��ʾ��ǰ��������ɫ�������ɫ
	drawLabel(winwidth - 13 * h, 0.25 * h, "Font Color:");
	if (operate_flag == 2)
	{
		switch (select_what)
		{
		case 1:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, ((myrect*)select_ptr)->front_color);
			break;
		}
		case 2:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, ((myroundrect*)select_ptr)->front_color);
			break;
		}
		case 3:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, ((mydiamond*)select_ptr)->front_color);
			break;
		}
		case 4:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, "None");
			break;
		}
		case 5:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, "None");
			break;
		}
		case 6:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, "None");
			break;
		}
		case 7:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, "None");
			break;
		}
		case 8:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, ((myprocess*)select_ptr)->front_color);
			break;
		}
		case 9:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, ((mycircle*)select_ptr)->front_color);
			break;
		}

		case 10:
		{
			drawLabel(winwidth - 9.5 * h, 0.25 * h, ((myoval*)select_ptr)->front_color);
			break;
		}
		}
	}
	else 
		drawLabel(winwidth - 9.5 * h, 0.25 * h, bColors[front_color]);
	drawLabel(winwidth - 19 * h, 0.25 * h, "Fill Color:");
	if (operate_flag == 2)
	{
		switch (select_what)
		{
		case 1:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((myrect*)select_ptr)->fill_color);
			break;
		}
		case 2:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((myroundrect*)select_ptr)->fill_color);
			break;
		}
		case 3:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((mydiamond*)select_ptr)->fill_color);
			break;
		}
		case 4:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((myline*)select_ptr)->pencolor);
			break;
		}
		case 5:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((mydirectionalconnection*)select_ptr)->fill_color);
			break;
		}
		case 6:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((mybidirectionalconnection*)select_ptr)->fill_color);
			break;
		}
		case 7:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((mydashline*)select_ptr)->pencolor);
			break;
		}
		case 8:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((myprocess*)select_ptr)->fill_color);
			break;
		}
		case 9:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((mycircle*)select_ptr)->fill_color);
			break;
		}

		case 10:
		{
			drawLabel(winwidth - 16 * h, 0.25 * h, ((myoval*)select_ptr)->fill_color);
			break;
		}
		}
	}
	else
		drawLabel(winwidth - 16 * h, 0.25 * h, bColors[filled_color]);
	//ʵ���ı�������ı��� 
	if (textbox(GenUIID(0), 18 * h, 0, 10 * h, h, mytext, 100))
	{
		if (operate_flag == 2)
		{
			switch (select_what)
			{
			case 1:
			{
				strcpy(((myrect*)select_ptr)->text, mytext);
				break;
			}
			case 2:
			{
				strcpy(((myroundrect*)select_ptr)->text, mytext);
				break;
			}
			case 3:
			{
				strcpy(((mydiamond*)select_ptr)->text, mytext);
				break;
			}
			case 8:
			{
				strcpy(((myprocess*)select_ptr)->text, mytext);
				break;
			}
			case 9:
			{
				strcpy(((mycircle*)select_ptr)->text, mytext);
				break;
			}
			case 10:
			{
				strcpy(((myoval*)select_ptr)->text, mytext);
				break;
			}
			}
		}
	}
	SetPenColor("Light Gray");
	drawRectangle(10 * h, h, 8 * h, winheight - 3 * h, 1);
	drawRectangle(winwidth - 8 * h, h, 8 * h, winheight - 3 * h, 1);
}



//��һ��Բ�Ǿ���
void drawRoundrec(double x, double y, double w, double h, int fillflag)
{
	MovePen(x, y);
	if (fillflag) StartFilledRegion(1);
	{
		if (h > 0 && w > 0)  //���� 
		{
			MovePen(x, y);
			DrawLine(w, 0);
			DrawEllipticalArc(w / 6, h / 6, 270, 90);
			DrawLine(0, h);
			DrawEllipticalArc(w / 6, h / 6, 0, 90);
			DrawLine(-w, 0);
			DrawEllipticalArc(w / 6, h / 6, 90, 90);
			DrawLine(0, -h);
			DrawEllipticalArc(w / 6, h / 6, 180, 90);
		}
		else if (h < 0 && w < 0)  //���� 
		{
			MovePen(x, y);
			DrawLine(w, 0);
			DrawEllipticalArc(-w / 6, -h / 6, 90, 90);
			DrawLine(0, h);
			DrawEllipticalArc(-w / 6, -h / 6, 180, 90);
			DrawLine(-w, 0);
			DrawEllipticalArc(-w / 6, -h / 6, 270, 90);
			DrawLine(0, -h);
			DrawEllipticalArc(-w / 6, -h / 6, 0, 90);
		}
		else if (h > 0 && w < 0) //����
		{
			MovePen(x, y);
			DrawLine(0, h);
			DrawEllipticalArc(-w / 6, h / 6, 0, 90);
			DrawLine(w, 0);
			DrawEllipticalArc(-w / 6, h / 6, 90, 90);
			DrawLine(0, -h);
			DrawEllipticalArc(-w / 6, h / 6, 180, 90);
			DrawLine(-w, 0);
			DrawEllipticalArc(-w / 6, h / 6, 270, 90);
		}
		else if (h < 0 && w>0)   //����
		{
			MovePen(x, y);
			DrawLine(0, h);
			DrawEllipticalArc(w / 6, -h / 6, 180, 90);
			DrawLine(w, 0);
			DrawEllipticalArc(w / 6, -h / 6, 270, 90);
			DrawLine(0, -h);
			DrawEllipticalArc(w / 6, -h / 6, 0, 90);
			DrawLine(-w, 0);
			DrawEllipticalArc(w / 6, -h / 6, 90, 90);
		}

	}
	if (fillflag) EndFilledRegion();
}

//��һ������ 
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

//��һ��Բ 
void drawCircle(double x, double y, double r,int fillflag)
{
	
    MovePen(x + r, y);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawArc(r, 0, 360);
	}
	if( fillflag ) EndFilledRegion();
	
 } 


//��һ��ֱ��
void drawLine(double x1,double y1,double dx,double dy)
{ 
	MovePen(x1, y1);
	DrawLine(dx, dy);
}

//��һ������
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
//��һ�������ͷ 
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

//��һ��˫���ͷ
void drawBidirectionalconnection(double x, double y, double dx, double dy, int fillflag, int arrow_style)
{
	double sin = dy / (sqrt(dy * dy + dx * dx));
	double cos = dx / (sqrt(dy * dy + dx * dx));
	double length = sqrt(dy * dy + dx * dx);
	drawDirectionalconnection(x+0.5*dx, y+0.5*dy, 0.5*dx, 0.5*dy, fillflag, arrow_style);
	drawDirectionalconnection(x+0.5*dx, y+0.5*dy, -0.5*dx, -0.5*dy, fillflag, arrow_style);
}

//��һ����Բ
void drawOval(double x, double y, double rx,double ry,int fillflag)
{
	
    MovePen(x + 2*rx, y+ry);
	if( fillflag ) StartFilledRegion(1); 
	{
		DrawEllipticalArc(rx, ry, 0, 360);
	}
	if( fillflag ) EndFilledRegion();
	
 } 
//��һ��process
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


//��һ��Բ�Ǿ��Σ��������ڲ�������ʾһ���ַ�����ǩlabel
void drawRoundrecBox(double x, double y, double w, double h, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();
	//roundrec 
	drawRoundrec(x,y,w,h,fillflag);
	// text
	if( label && strlen(label)>0 )
	{
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+h/2-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+w-fa/2-TextStringWidth(label), y+h/2-fa/2);
		else  if( labelAlignment=='C')
			MovePen(x+(w-TextStringWidth(label))/2, y+h/2-fa/2);
		DrawTextString(label);
	}
}

//��һ�����Σ��������ڲ�������ʾһ���ַ�����ǩlabel
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
		else  if( labelAlignment=='C')
			MovePen(x+(w-TextStringWidth(label))/2, y+h/2-fa/2);
		DrawTextString(label);
	}
}

//��һ��Բ���������ڲ�������ʾһ���ַ�����ǩlabel
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
		else  if( labelAlignment=='C')
			MovePen(x-(TextStringWidth(label))/2, y-fa/2);
		DrawTextString(label);
	}   
}

//��һ����Բ���������ڲ�������ʾһ���ַ�����ǩlabel
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
		else  if( labelAlignment=='C')
			MovePen(x+(2*rx-TextStringWidth(label))/2, y+ry-fa/2);
		DrawTextString(label);
	}
}
//��һ��process���������ڲ�������ʾһ���ַ�����ǩlabel
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
		else  if( labelAlignment=='C')
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
	if (key == 0x2e)
	{
		if (operate_flag == 2)
		{
			pop();
			operate_flag = 0;
		}
	}

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
				if (operate_flag == 1)
				{
					if (click_count == 1)
					{
						select_what = draw_what;
						select_ptr = draw_ptr;
						pop();
						operate_flag = 0;
					}
					else
						operate_flag = 0;
				}
				else
				{
					operate_flag = 0;
				}
			}
			else if (button == LEFT_BUTTON)
			{
				if (operate_flag == 1)
				{
					if (mx > 18 * h && mx < winwidth - 8 * h && my<winheight - 3 * h && my>h)//������ڻ������򵥻���� 
					{
						if (click_count == 0)				//����ʱ��ȡ��һ����ʱ��mx,myΪ���ϵ�
						{
							click_count = 1;
							draw(mx,my);
						}
						else
						{
							click_count = 2;
							x_2 = mx;
							y_2 = my;
							
							display();
							click_count = 0;
							operate_flag = 0;
						}
					}
				}								
				else if (operate_flag == 0)
				{
					if (mx > 18 * h && mx < winwidth - 8 * h && my<winheight - 3 * h && my>h)//������ڻ������򵥻���� 
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
			else if (operate_flag == 1 && click_count == 1)
			{
				drawing(mx, my);
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
	if (save_flag == 1 && timerID % 100000 == 0)
	{
		save_flag == 0;
	}
	display();

}
void drawlinklist1()//n ��linklist�д����Ÿ���ͼԪ��ÿ��display���Ὣ���������е�ͼԪ�������ͬ 
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
//ѡ��ͼ�κ������� 
int  select_graphic(double mx,double my)
{
	//ѡ�о��� 
	myrect* p = rect_head->next;
	while (p != NULL)
	{
		if ((mx-p->x)*(mx-p->x-p->width)<=0&& (my - p->y) * (my - p->y - p->height)<=0)
		{
			operate_flag = 2;
			select_ptr = p;
			select_what = 1;
			strcpy(mytext, p->text);
			return 1;
		}
		p = p->next;
	}
	//ѡ��Բ�Ǿ��� 
	myroundrect* q = roundrect_head->next;
	while (q != NULL)
	{
		if ((mx - q->x) * (mx - q->x - q->width) <= 0 && (my - q->y) * (my - q->y - q->height) <= 0)
		{
			operate_flag = 2;
			select_ptr = q;
			select_what = 2;
			strcpy(mytext, q->text);
			return 1;
		}
		q = q->next;
	}
	//ѡ��ֱ�� 
	myline* o = line_head->next;
	while (o != NULL)
	{
		if ((my>=(o->dy*(mx-o->x1)/o->dx+o->y1-0.1))&& (my <= (o->dy * (mx - o->x1) / o->dx + o->y1 + 0.1)))
		{

			operate_flag = 2;
			select_ptr = o;
			select_what = 4;
			strcpy(mytext, "");
			return 1;
		}
		o = o->next;
	}
	//ѡ������ 
	mydiamond* s = diamond_head->next;
	while (s != NULL)
	{
		if ((mx - s->x) * (mx - s->x - s->width) <= 0 && (my - s->y) * (my - s->y - s->height) <= 0)
		{
			operate_flag = 2;
			select_ptr = s;
			select_what = 3;
			strcpy(mytext, s->text);
			return 1;
		}
		s = s->next;
	}
	//ѡ�е����ͷ 
	mydirectionalconnection* t = directionalconnection_head->next;
	while (t != NULL)
	{
		if ((my >= (t->dy * (mx - t->x) / t->dx + t->y - 0.1)) && (my <= (t->dy * (mx - t->x) / t->dx + t->y + 0.1)))
		{
			operate_flag = 2;
			select_ptr = t;
			select_what = 5;
			strcpy(mytext, "");
			return 1;
		}
		t = t->next;
	}
	//ѡ��˫���ͷ 
	mybidirectionalconnection* u = bidirectionalconnection_head->next;
	while (u != NULL)
	{
		if ((my >= (u->dy * (mx - u->x) / u->dx + u->y - 0.1)) && (my <= (u->dy * (mx - u->x) / u->dx + u->y + 0.1)))
		{
			operate_flag = 2;
			select_ptr = u;
			select_what = 6;
			strcpy(mytext, "");
			return 1;
		}
		u = u->next;
	}
	//ѡ��process 
	myprocess* v = process_head->next;
	while (v != NULL)
	{
		if ((mx - v->x) * (mx - v->x - v->width) <= 0 && (my - v->y) * (my - v->y - v->height) <= 0)
		{
			operate_flag = 2;
			select_ptr = v;
			select_what = 8; 
			strcpy(mytext, v->text);
			return 1;
		}
		v = v->next;
	}
	//ѡ������ 
	mydashline* w = dashline_head->next;
	while (w != NULL)
	{
		if ((my >= (w->dy * (mx - w->x1) / w->dx + w->y1 - 0.1)) && (my <= (w->dy * (mx - w->x1) / w->dx + w->y1 + 0.1)))
		{
			operate_flag = 2;
			select_ptr = w;
			select_what = 7;
			strcpy(mytext, "");
			return 1;
		}
		w = w->next;
	}
	//ѡ��Բ�� 
	mycircle* x = circle_head->next;
	while (x != NULL)
	{
		double distance = sqrt((mx - x->x) * (mx - x->x) + (my - x->y) * (my - x->y));
		if (distance <= x->r)
		{
			operate_flag = 2;
			select_ptr = x;
			select_what = 9;
			strcpy(mytext, x->text);
			return 1;
		}
		x = x->next;
	}
	//ѡ����Բ 
	myoval* y = oval_head->next;
	while (y != NULL)
	{
		if ((pow(mx-y->x-y->rx,2)/pow(y->rx,2) + pow(my-y->y-y->ry,2)/pow(y->ry,2))<= 1)
		{
			operate_flag = 2;
			select_ptr = y;
			select_what = 10;
			strcpy(mytext, y->text);
			return 1;
		}
		y = y->next;
	}
	
	return 0;
}
