#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"

#include "draw.h"
#include "windraw.h"
#include "linklist.h"
void Initwin();
void display();
void InitButton();
void startTimer(int id, int timeinterval);
void Main()
{
	SetWindowTitle("New file");
	SetWindowSize(20, 9); // ��λ - Ӣ��
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
	InitGraphics();
	// ��ô��ڳߴ�
	strcpy(mytext, "Please insert here");
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();
	filled_flag = -1;
	operate_flag = 0;
	filled_color = 0;
	front_color = 0;
	alignment_flag = 2;
	strcpy(table, "LRC");
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��
	startTimer(1,2);

	mciSendString((LPCSTR)"open SoldOut.mp3 alias a", NULL, 0, NULL);



	copy_ptr = NULL;

	InitButton();
	Initwin();
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
 

}
