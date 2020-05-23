
#include "draw.h"
#include "windraw.h"
#include "linklist.h"
void Initwin();
void display();
void InitButton();
void Main()
{
	SetWindowTitle("New file");
	SetWindowSize(20, 9); // 单位 - 英寸
	//SetWindowSize(10, 20);  // 如果屏幕尺寸不够，则按比例缩小
	InitGraphics();
	// 获得窗口尺寸
	mytext[100] = "Please insert here";
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();
	filled_flag = 1;
	operate_flag = 0;
	filled_color = 0;
	front_color = 0;
	registerCharEvent(CharEventProcess);        // 字符
	registerKeyboardEvent(KeyboardEventProcess);// 键盘
	registerMouseEvent(MouseEventProcess);      // 鼠标
	registerTimerEvent(TimerEventProcess);      // 定时器

	// 开启定时器
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
