#include "linklist.h"
#include "draw.h"
#include "file.h"
#include "string.h"
#include "windows.h"
void pushrect(myrect* source)
{
	myrect* p = rect_head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = source;
	return;
}

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

int open()
{
	char szFile[MAX_PATH] = { 0 };
	FileOpenDialog(szFile);//szFile中返回了再文件选择窗口选择得文件得路径
	if (strlen(szFile) == 0)
	{
		MessageBox(NULL, "Please choose a File", "Waring", MB_OK | MB_ICONWARNING);
		return 0;
	}
	return 1;
}
int save()
{
	char szFile[MAX_PATH] = { 0 };
	FileSaveDialog(szFile);//szFile中返回了再文件选择窗口选择得文件得路径
	if (strlen(szFile) == 0)
	{
		MessageBox(NULL,"Please choose a File","Waring", MB_OK| MB_ICONWARNING);
		return 0;
	}
	return 1;
}
