
#include "draw.h"
#include "windraw.h"
#include "linklist.h"
void Initwin();
void display();
void InitButton();
void Main()
{
	SetWindowTitle("New file");
	SetWindowSize(20, 9); // ��λ - Ӣ��
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
	InitGraphics();
	// ��ô��ڳߴ�
	mytext[100] = "Please insert here";
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();
	filled_flag = 1;
	operate_flag = 0;
	filled_color = 0;
	front_color = 0;
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��

	// ������ʱ��
	startTimer(2019, 256);
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
