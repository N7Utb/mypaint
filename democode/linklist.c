#include "linklist.h"
#include "windraw.h"
#include "draw.h"
#include "file.h"
#include "string.h"
#include "windows.h"
#include "stdio.h"
//将一个矩形压入链表
void pushrect(myrect* source)
{
	myrect* p = rect_head;
	p = rect_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}
//初始化矩形得链表
void Initlinklist1()
{
	myrect* p;
	p = malloc(sizeof(myrect));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	rect_head = p;

}
//将一个圆角矩形压入链表
void pushroundrect(myroundrect* source)
{
	myroundrect* p = roundrect_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}
//初始化圆角矩形得链表
void Initlinklist2()
{
	myroundrect* p;
	p = malloc(sizeof(myroundrect));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	roundrect_head = p;
}
//将菱形压入链表
void pushdiamond(mydiamond* source)
{
	mydiamond* p = diamond_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}
void Initlinklist3()
{
	mydiamond* p;
	p = malloc(sizeof(mydiamond));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	diamond_head = p;

}
//将线压入链表
void pushline(myline* source)
{
	myline* p = line_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

void pop()
{
	switch (select_what)
	{
	case 1:
	{
		myrect* p = rect_head->next;
		if (p == ((myrect*)select_ptr))
		{
			rect_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((myrect*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((myrect*)select_ptr)->next;
		free(((myrect*)select_ptr));
		break;
	}
	case 2:
	{
		myroundrect* p = roundrect_head->next;
		if (p == ((myroundrect*)select_ptr))
		{
			roundrect_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((myroundrect*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((myroundrect*)select_ptr)->next;
		free(((myroundrect*)select_ptr));
		break;
	}
	case 3:
	{
		mydiamond* p = diamond_head->next;
		if (p == ((mydiamond*)select_ptr))
		{
			diamond_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((mydiamond*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((mydiamond*)select_ptr)->next;
		free(((mydiamond*)select_ptr));
		break;
	}
	case 4:
	{
		myline* p = line_head->next;
		if (p == ((myline*)select_ptr))
		{
			line_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((myline*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((myline*)select_ptr)->next;
		free(((myline*)select_ptr));
		break;
	}
	case 5:
	{
		mydirectionalconnection* p = directionalconnection_head->next;
		if (p == ((mydirectionalconnection*)select_ptr))
		{
			directionalconnection_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((mydirectionalconnection*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((mydirectionalconnection*)select_ptr)->next;
		free(((mydirectionalconnection*)select_ptr));
		break;
	}
	case 6:
	{
		mybidirectionalconnection* p = bidirectionalconnection_head->next;
		if (p == ((mybidirectionalconnection*)select_ptr))
		{
			bidirectionalconnection_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((mybidirectionalconnection*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((mybidirectionalconnection*)select_ptr)->next;
		free(((mybidirectionalconnection*)select_ptr));
		break;
	}
	case 7:
	{
		mydashline* p = dashline_head->next;
		if (p == ((mydashline*)select_ptr))
		{
			dashline_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((mydashline*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((mydashline*)select_ptr)->next;
		free(((mydashline*)select_ptr));
		break;
	}
	case 8:
	{
		myprocess* p = process_head->next;
		if (p == ((myprocess*)select_ptr))
		{
			process_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((myprocess*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((myprocess*)select_ptr)->next;
		free(((myprocess*)select_ptr));
		break;
	}
	case 9:
	{
		mycircle* p = circle_head->next;
		if (p == ((mycircle*)select_ptr))
		{
			circle_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((mycircle*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((mycircle*)select_ptr)->next;
		free(((mycircle*)select_ptr));
		break;
	}
	case 10:
	{
		myoval* p = oval_head->next;
		if (p == ((myoval*)select_ptr))
		{
			oval_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != ((myoval*)select_ptr))
		{
			p = p->next;
		}
		p->next = ((myoval*)select_ptr)->next;
		free(((myoval*)select_ptr));
		break;
	}
	}
}
void Initlinklist4()
{
	myline* p;
	p = malloc(sizeof(myline));
	if (p == NULL)
	{
		exit(0);
	}
	p->x1 = 0;
	p->y1 = 0;
	p->next = NULL;
	line_head = p;

}

//将虚线压入链表
void pushdashline(mydashline* source)
{
	mydashline* p = dashline_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

void Initlinklist7()
{
	mydashline* p;
	p = malloc(sizeof(mydashline));
	if (p == NULL)
	{
		exit(0);
	}
	p->x1 = 0;
	p->y1 = 0;
	p->next = NULL;
	dashline_head = p;

}


void pushdirectionalconnection(mydirectionalconnection* source)
{
	mydirectionalconnection* p = directionalconnection_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

void Initlinklist5()
{
	mydirectionalconnection* p;
	p = malloc(sizeof(mydirectionalconnection));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	directionalconnection_head = p;

}


void pushbidirectionalconnection(mybidirectionalconnection* source)
{
	mybidirectionalconnection* p = bidirectionalconnection_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

void Initlinklist6()
{
	mybidirectionalconnection* p;
	p = malloc(sizeof(mybidirectionalconnection));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	bidirectionalconnection_head = p;

}


void pushprocess(myprocess* source)
{
	myprocess* p = process_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}
void Initlinklist8()
{
	myprocess* p;
	p = malloc(sizeof(myprocess));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	process_head = p;

}


void pushcircle(mycircle* source)
{
	mycircle* p = circle_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

void Initlinklist9()
{
	mycircle* p;
	p = malloc(sizeof(mycircle));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	circle_head = p;

}
void pushoval(myoval* source)
{
	myoval* p = oval_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

void Initlinklist10()
{
	myoval* p;
	p = malloc(sizeof(myoval));
	if (p == NULL)
	{
		exit(0);
	}
	p->x = 0;
	p->y = 0;
	p->next = NULL;
	oval_head = p;

}
//2020/5/26 23:04添加关于打开文件得函数
int open()
{
	char szFile[MAX_PATH] = { 0 };
	//close相当于将当前窗口关闭，询问是否保存文件
	if (save_flag == 0)
	{
		int k = MessageBox(NULL, "your file was not save yet, do you want to save and quit right now", "Warning", MB_YESNOCANCEL | MB_ICONINFORMATION / MB_ICONASTERISK);
		if (k == IDYES)
		{
			if (save() == 1)		//如果用户选择是并且选择了保存路径则保存
			{
			}						//如果未选择保存路径则无事发生
			else
			{
				return;
			}
		}
		else if (k == IDNO)		//如果用户选择了否则直接退出
		{
		}
		else if (k == IDCANCEL)
		{
			return;
		}
		save_flag = 1;
	}

	Initlinklist1();
	Initlinklist2();
	Initlinklist3();
	Initlinklist4();
	Initlinklist5();
	Initlinklist6();
	Initlinklist7();
	Initlinklist8();
	Initlinklist9();
	Initlinklist10();

	FileOpenDialog(szFile);//szFile中返回了再文件选择窗口选择得文件得路径
	if (strlen(szFile) == 0)
	{
		MessageBox(NULL, "Please choose a File", "Waring", MB_OK | MB_ICONWARNING);
		return 0;
	}
	fp = fopen(szFile, "r");
	char ch = '\\',string[20];
	char* q = strrchr(szFile, ch) + 1;
	int i = 0;
	while (*q != '.')
	{
		string[i] = *q;
		i++;
		q++;
	}
	string[i] = 0;
	SetWindowTitle(string);
	//1:load rectangle
	char c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			myrect* loadrect = malloc(sizeof(myrect));
			fscanf(fp, "%lf%lf%lf%lf%d%d", &loadrect->x, &loadrect->y, &loadrect->width, &loadrect->height, &loadrect->fillflag, &loadrect->text_flag);
			c = fgetc(fp);
			loadrect->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loadrect->text, 100, fp);
			loadrect->text[strlen(loadrect->text) - 1] = 0;
			fgets(loadrect->fill_color, 100, fp);
			loadrect->fill_color[strlen(loadrect->fill_color) - 1] = 0;
			fgets(loadrect->front_color, 100, fp);
			loadrect->front_color[strlen(loadrect->front_color) - 1] = 0;

			loadrect->next = NULL;
			pushrect(loadrect);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//2:load roundrectangle
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			myroundrect* loadroundrect = malloc(sizeof(myroundrect));
			fscanf(fp, "%lf%lf%lf%lf%d%d", &loadroundrect->x, &loadroundrect->y, &loadroundrect->width, &loadroundrect->height, &loadroundrect->fillflag, &loadroundrect->text_flag);
			c = fgetc(fp);
			loadroundrect->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loadroundrect->text, 100, fp);
			loadroundrect->text[strlen(loadroundrect->text) - 1] = 0;
			fgets(loadroundrect->fill_color, 100, fp);
			loadroundrect->fill_color[strlen(loadroundrect->fill_color) - 1] = 0;

			fgets(loadroundrect->front_color, 100, fp);
			loadroundrect->front_color[strlen(loadroundrect->front_color) - 1] = 0;
			loadroundrect->next = NULL;
			pushroundrect(loadroundrect);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//3:load diamond
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			mydiamond* loaddiamond = malloc(sizeof(mydiamond));
			fscanf(fp, "%lf%lf%lf%lf%d%d", &loaddiamond->x, &loaddiamond->y, &loaddiamond->width, &loaddiamond->height, &loaddiamond->fillflag, &loaddiamond->text_flag);
			c = fgetc(fp);
			loaddiamond->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loaddiamond->text, 100, fp);
			loaddiamond->text[strlen(loaddiamond->text) - 1] = 0;
			fgets(loaddiamond->fill_color, 100, fp);
			loaddiamond->fill_color[strlen(loaddiamond->fill_color) - 1] = 0;

			fgets(loaddiamond->front_color, 100, fp);
			loaddiamond->front_color[strlen(loaddiamond->front_color) - 1] = 0;
			loaddiamond->next = NULL;
			pushdiamond(loaddiamond);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//4:load line
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			myline* loadline = malloc(sizeof(myline));
			fscanf(fp, "%lf%lf%lf%lf%d", &loadline->x1, &loadline->y1, &loadline->dx, &loadline->dy, &loadline->pensize);
			c = fgetc(fp);
			fgets(loadline->pencolor, 100, fp);
			loadline->pencolor[strlen(loadline->pencolor) - 1] = 0;
			loadline->next = NULL;
			pushline(loadline);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//5:loaddashline
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			mydashline* loaddashline = malloc(sizeof(mydashline));
			fscanf(fp, "%lf%lf%lf%lf%d", &loaddashline->x1, &loaddashline->y1, &loaddashline->dx, &loaddashline->dy, &loaddashline->pensize);
			c = fgetc(fp);
			fgets(loaddashline->pencolor, 100, fp);
			loaddashline->pencolor[strlen(loaddashline->pencolor) - 1] = 0;
			loaddashline->next = NULL;
			pushdashline(loaddashline);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//6:load directionalconnection
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			mydirectionalconnection* loaddirectionalconnection = malloc(sizeof(mydirectionalconnection));
			fscanf(fp, "%lf%lf%lf%lf%d%d%d", &loaddirectionalconnection->x, &loaddirectionalconnection->y, &loaddirectionalconnection->dx, &loaddirectionalconnection->dy, &loaddirectionalconnection->fillflag, &loaddirectionalconnection->arrow_style, &loaddirectionalconnection->pensize);
			c = fgetc(fp);
			fgets(loaddirectionalconnection->fill_color, 100, fp);
			loaddirectionalconnection->fill_color[strlen(loaddirectionalconnection->fill_color) - 1] = 0;
			c = fgetc(fp);
			fgets(loaddirectionalconnection->front_color, 100, fp);
			loaddirectionalconnection->front_color[strlen(loaddirectionalconnection->front_color) - 1] = 0;

			loaddirectionalconnection->next = NULL;
			pushdirectionalconnection(loaddirectionalconnection);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//7:load bidirectionalconnection
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			mybidirectionalconnection* loadbidirectionalconnection = malloc(sizeof(mybidirectionalconnection));
			fscanf(fp, "%lf%lf%lf%lf%d%d%d", &loadbidirectionalconnection->x, &loadbidirectionalconnection->y, &loadbidirectionalconnection->dx, &loadbidirectionalconnection->dy, &loadbidirectionalconnection->fillflag, &loadbidirectionalconnection->arrow_style, &loadbidirectionalconnection->pensize);
			c = fgetc(fp);
			fgets(loadbidirectionalconnection->fill_color, 100, fp);
			loadbidirectionalconnection->fill_color[strlen(loadbidirectionalconnection->fill_color) - 1] = 0;
			c = fgetc(fp);
			fgets(loadbidirectionalconnection->front_color, 100, fp);
			loadbidirectionalconnection->front_color[strlen(loadbidirectionalconnection->front_color) - 1] = 0;

			loadbidirectionalconnection->next = NULL;
			pushbidirectionalconnection(loadbidirectionalconnection);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//8:load process
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			myprocess* loadprocess = malloc(sizeof(myprocess));
			fscanf(fp, "%lf%lf%lf%lf%d%d", &loadprocess->x, &loadprocess->y, &loadprocess->width, &loadprocess->height, &loadprocess->fillflag, &loadprocess->text_flag);
			c = fgetc(fp);
			loadprocess->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loadprocess->text, 100, fp);
			loadprocess->text[strlen(loadprocess->text) - 1] = 0;
			fgets(loadprocess->fill_color, 100, fp);
			loadprocess->fill_color[strlen(loadprocess->fill_color) - 1] = 0;
			fgets(loadprocess->front_color, 100, fp);
			loadprocess->front_color[strlen(loadprocess->front_color) - 1] = 0;

			loadprocess->next = NULL;
			pushprocess(loadprocess);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//9:load circle
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			mycircle* loadcircle = malloc(sizeof(mycircle));
			fscanf(fp, "%lf%lf%lf%d%d", &loadcircle->x, &loadcircle->y, &loadcircle->r, &loadcircle->fillflag, &loadcircle->text_flag);
			c = fgetc(fp);
			loadcircle->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loadcircle->text, 100, fp);
			loadcircle->text[strlen(loadcircle->text) - 1] = 0;
			fgets(loadcircle->fill_color, 100, fp);
			loadcircle->fill_color[strlen(loadcircle->fill_color) - 1] = 0;
			fgets(loadcircle->front_color, 100, fp);
			loadcircle->front_color[strlen(loadcircle->front_color) - 1] = 0;

			loadcircle->next = NULL;
			pushcircle(loadcircle);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	//10:load oval
	c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp, -1L, SEEK_CUR);
		while (1)
		{
			myoval* loadoval = malloc(sizeof(myoval));
			fscanf(fp, "%lf%lf%lf%lf%d%d", &loadoval->x, &loadoval->y, &loadoval->rx, &loadoval->ry, &loadoval->fillflag, &loadoval->text_flag);
			c = fgetc(fp);
			loadoval->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loadoval->text, 100, fp);
			loadoval->text[strlen(loadoval->text) - 1] = 0;
			fgets(loadoval->fill_color, 100, fp);
			loadoval->fill_color[strlen(loadoval->fill_color) - 1] = 0;
			fgets(loadoval->front_color, 100, fp);
			loadoval->front_color[strlen(loadoval->front_color) - 1] = 0;

			loadoval->next = NULL;
			pushoval(loadoval);
			c = getc(fp);
			if (c == '@')
			{
				c = getc(fp);
				c = getc(fp);
				if (c == '#')
					break;
				else
					fseek(fp, -1, SEEK_CUR);
			}
		}
	}

	fclose(fp);
	return 1;
}
void savemyrect(myrect* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	myrect* pCur = source->next;
	while (pCur!= NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->width, pCur->height);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”

}

void savemyroundrect(myroundrect* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	myroundrect* pCur = source->next;
	while (pCur!= NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->width, pCur->height);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemymdiamond(mydiamond* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	mydiamond* pCur = source->next;
	while (pCur != NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->width, pCur->height);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemyline(myline* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	myline* pCur = source->next;
	while (pCur!= NULL)
	{
		fprintf(fp, "%lf\n%lf\n", pCur->x1, pCur->y1);
		fprintf(fp, "%lf\n%lf\n", pCur->dx, pCur->dy);
		fprintf(fp, "%d\n", pCur->pensize);
		fprintf(fp, "%s\n", pCur->pencolor);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemydashline(mydashline* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	mydashline* pCur = source->next;
	while (pCur!= NULL)
	{
		fprintf(fp, "%lf\n%lf\n", pCur->x1, pCur->y1);
		fprintf(fp, "%lf\n%lf\n", pCur->dx, pCur->dy);
		fprintf(fp, "%d\n", pCur->pensize);
		fprintf(fp, "%s\n", pCur->pencolor);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”


}
void savemydirectionalconnection(mydirectionalconnection* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	mybidirectionalconnection* pCur = source->next;
	while (pCur!= NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->dx, pCur->dy);
		fprintf(fp, "%d\n%d\n%d\n", pCur->fillflag, pCur->arrow_style, pCur->pensize);
		fprintf(fp, "%s\n%s\n", pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemybidirectionalconnection(mybidirectionalconnection* source)
{
	fprintf(fp, "#\n");
		if (source->next == NULL)
		{
			fprintf(fp, "%c\n", '#');//设置分隔符“#”
			return;
		}
	mybidirectionalconnection* pCur = source->next;
	while (pCur != NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->dx, pCur->dy);
		fprintf(fp, "%d\n%d\n%d\n", pCur->fillflag, pCur->arrow_style, pCur->pensize);
		fprintf(fp, "%s\n%s\n", pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemyprocess(myprocess* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	myprocess* pCur = source->next;
	while (pCur != NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->width, pCur->height);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemycircle(mycircle* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	mycircle* pCur = source->next;
	while (pCur!= NULL)
	{
		fprintf(fp, "%lf\n%lf\n", pCur->x, pCur->y);
		fprintf(fp, "%lf\n", pCur->r);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemyoval(myoval* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
	{
		fprintf(fp, "%c\n", '#');//设置分隔符“#”
		return;
	}
	myoval* pCur = source->next;
	while (pCur != NULL)
	{
		fprintf(fp, "%lf\n%lf\n", pCur->x, pCur->y);
		fprintf(fp, "%lf\n%lf\n", pCur->rx, pCur->ry);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c\n", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}
int save()
{
	char szFile[MAX_PATH] = { 0 };
	FileSaveDialog(szFile);//szFile中返回了再文件选择窗口选择得文件得路径
	if (strlen(szFile) == 0)
	{
		MessageBox(NULL, "Please choose a File", "Waring", MB_OK | MB_ICONWARNING);
		return 0;
	}
	fp = fopen(szFile, "w+");
	char ch = '\\', string[20];
	char* q = strrchr(szFile, ch) + 1;
	int i = 0;
	while (*q != '.')
	{
		string[i] = *q;
		i++;
		q++;
	}
	string[i] = 0;
	SetWindowTitle(string);
	//存储图元数据
	//1：rectangle矩形
	savemyrect(rect_head);

	//2: roundrectangle圆角矩形
	savemyroundrect(roundrect_head);

	//3diamond菱形
	savemymdiamond(diamond_head);

	//4: line直线
	savemyline(line_head);

	//5	:dashline虚线
	savemydashline(dashline_head);

	//6:directionalconnection 单向箭头
	savemydirectionalconnection(directionalconnection_head);

	//7:bidirectionalconnection 双向箭头
	savemybidirectionalconnection(bidirectionalconnection_head);

	//8:process 进程图
	savemyprocess(process_head);

	//9:circle 圆
	savemycircle(circle_head);

	//10:oval 椭圆
	savemyoval(oval_head);

	fclose(fp);
	save_flag = 1;
	return 1;
}
void copy()
{
	switch (select_what)
	{
	case 1:
	{
		myrect* a = malloc(sizeof(myrect));
		memcpy(a, ((myrect*)select_ptr), sizeof(myrect));
		a->next = NULL;
		a->x = 18 * h;
		a->y = winheight - 3 * h-a->height;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 2:
	{
		myroundrect* a = malloc(sizeof(myroundrect));
		memcpy(a, ((myroundrect*)select_ptr), sizeof(myroundrect));
		a->next = NULL;
		a->x = 18 * h;
		a->y = winheight - 3 * h - a->height;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 3:
	{
		mydiamond* a = malloc(sizeof(mydiamond));
		memcpy(a, ((mydiamond*)select_ptr), sizeof(mydiamond));
		a->next = NULL;
		a->x = 18 * h;
		a->y = winheight - 3 * h - a->height;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 4:
	{
		myline* a = malloc(sizeof(myline));
		memcpy(a, ((myline*)select_ptr), sizeof(myline));
		a->next = NULL;
		a->x1 += 0.5;
		a->y1 += 0.5;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 5:
	{
		mydirectionalconnection* a = malloc(sizeof(mydirectionalconnection));
		memcpy(a, ((mydirectionalconnection*)select_ptr), sizeof(mydirectionalconnection));
		a->next = NULL;
		a->x += 0.5;
		a->y += 0.5;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 6:
	{
		mybidirectionalconnection* a = malloc(sizeof(mybidirectionalconnection));
		memcpy(a, ((mybidirectionalconnection*)select_ptr), sizeof(mybidirectionalconnection));
		a->next = NULL;
		a->x += 0.5;
		a->y += 0.5;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 8:
	{
		myprocess* a = malloc(sizeof(myprocess));
		memcpy(a, ((myprocess*)select_ptr), sizeof(myprocess));
		a->next = NULL;
		a->x = 18 * h;
		a->y = winheight - 3 * h - a->height;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 7:
	{
		mydashline* a = malloc(sizeof(mydashline));
		memcpy(a, ((mydashline*)select_ptr), sizeof(mydashline));
		a->next = NULL;
		a->x1 += 0.5;
		a->y1 += 0.5;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 9:
	{
		mycircle* a = malloc(sizeof(mycircle));
		memcpy(a, ((mycircle*)select_ptr), sizeof(mycircle));
		a->next = NULL;
		a->x = 18 * h+a->r;
		a->y = winheight - 3 * h - a->r;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	case 10:
	{
		myoval* a = malloc(sizeof(myoval));
		memcpy(a, ((myoval*)select_ptr), sizeof(myoval));
		a->next = NULL;
		a->x = 18 * h + a->rx;
		a->y = winheight - 3 * h - a->ry;
		copy_what = select_what;
		copy_ptr = a;
		break;
	}
	}
}
void paste()
{
	switch (copy_what)
	{
	case 1:
	{
		pushrect(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 2:
	{
		pushroundrect(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 4:
	{
		pushline(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 3:
	{
		pushdiamond(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 5:
	{
		pushdirectionalconnection(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 6:
	{
		pushbidirectionalconnection(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 7:
	{
		pushdashline(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 8:
	{
		pushprocess(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 9:
	{
		pushcircle(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	case 10:
	{
		pushoval(copy_ptr);
		copy_ptr = NULL;
		break;
	}
	}
}

void cut()
{
	copy();
	pop();
}