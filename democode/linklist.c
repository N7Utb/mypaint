#include "linklist.h"
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
		if (p == selected_rect)
		{
			rect_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_rect)
		{
			p = p->next;
		}
		p->next = selected_rect->next;
		free(selected_rect);
		break;
	}
	case 2:
	{
		myroundrect* p = roundrect_head->next;
		if (p == selected_roundrect)
		{
			roundrect_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_roundrect)
		{
			p = p->next;
		}
		p->next = selected_roundrect->next;
		free(selected_roundrect);
		break;
	}
	case 3:
	{
		mydiamond* p = diamond_head->next;
		if (p == selected_diamond)
		{
			diamond_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_diamond)
		{
			p = p->next;
		}
		p->next = selected_diamond->next;
		free(selected_diamond);
		break;
	}
	case 4:
	{
		myline* p = line_head->next;
		if (p == selected_line)
		{
			line_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_line)
		{
			p = p->next;
		}
		p->next = selected_line->next;
		free(selected_line);
		break;
	}
	case 5:
	{
		mydirectionalconnection* p = directionalconnection_head->next;
		if (p == selected_directionalconnection)
		{
			directionalconnection_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_directionalconnection)
		{
			p = p->next;
		}
		p->next = selected_directionalconnection->next;
		free(selected_directionalconnection);
		break;
	}
	case 6:
	{
		mybidirectionalconnection* p = bidirectionalconnection_head->next;
		if (p == selected_bidirectionalconnection)
		{
			bidirectionalconnection_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_bidirectionalconnection)
		{
			p = p->next;
		}
		p->next = selected_bidirectionalconnection->next;
		free(selected_bidirectionalconnection);
		break;
	}
	case 7:
	{
		mydashline* p = dashline_head->next;
		if (p == selected_dashline)
		{
			dashline_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_dashline)
		{
			p = p->next;
		}
		p->next = selected_dashline->next;
		free(selected_dashline);
		break;
	}
	case 8:
	{
		myprocess* p = process_head->next;
		if (p == selected_process)
		{
			process_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_process)
		{
			p = p->next;
		}
		p->next = selected_process->next;
		free(selected_process);
		break;
	}
	case 9:
	{
		mycircle* p = circle_head->next;
		if (p == selected_circle)
		{
			circle_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_circle)
		{
			p = p->next;
		}
		p->next = selected_circle->next;
		free(selected_circle);
		break;
	}
	case 10:
	{
		myoval* p = oval_head->next;
		if (p == selected_oval)
		{
			oval_head->next = p->next;
			free(p);
			return;
		}
		while (p->next != selected_oval)
		{
			p = p->next;
		}
		p->next = selected_oval->next;
		free(selected_oval);
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
	FileOpenDialog(szFile);//szFile中返回了再文件选择窗口选择得文件得路径
	if (strlen(szFile) == 0)
	{
		MessageBox(NULL, "Please choose a File", "Waring", MB_OK | MB_ICONWARNING);
		return 0;
	}
	fp = fopen(szFile, "r");
	char c = getc(fp);
	c = fgetc(fp);
	c = fgetc(fp);
	if (c == '#')
	{

	}
	else
	{
		fseek(fp,-1L,SEEK_CUR);
		while (1)
		{
			myrect* loadrect = malloc(sizeof(myrect));
			fscanf(fp, "%lf%lf%lf%lf%d%d", &loadrect->x, &loadrect->y, &loadrect->width, &loadrect->height, &loadrect->fillflag, &loadrect->text_flag);
			c = fgetc(fp);
			loadrect->alignment = fgetc(fp);
			c = fgetc(fp);
			fgets(loadrect->text,100,fp);
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
	fclose(fp);
	return 1;
}

void savemyrect(myrect* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
		return;
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
		return;
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
		return;
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
		return;
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
		return;
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
		return;
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
		return;
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
		return;
	myprocess* pCur = source->next;
	while (pCur != NULL)
	{
		fprintf(fp, "%lf\n%lf\n%lf\n%lf\n", pCur->x, pCur->y, pCur->width, pCur->height);
		fprintf(fp, "%d\n%d\n", pCur->fillflag, pCur->text_flag);
		fprintf(fp, "%c\n", pCur->alignment);
		fprintf(fp, "%s\n%s\n%s\n", pCur->text, pCur->fill_color, pCur->front_color);
		fprintf(fp, "%c", '@'); //设置分隔符“@”
		pCur = pCur->next;
	}
	fprintf(fp, "%c\n", '#');//设置分隔符“#”
}

void savemycircle(mycircle* source)
{
	fprintf(fp, "#\n");
	if (source->next == NULL)
		return;
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
		fprintf(fp, "%c", '#');//设置分隔符“#”
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
	return 1;
}
