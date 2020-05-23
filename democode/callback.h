#ifndef __CALLBACK_H
#define __CALLBACK_H
#include <stdio.h>
#include <stdlib.h>


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
typedef struct char_key
{
	char ch;
}char_key;
typedef struct key
{
	int key, event;
}key;
typedef struct Mouse
{
	int x, y, button, event;
}Mouse;
char_key CharEventProcess(char ch);
void TimerEventProcess(int timerID);
Mouse MouseEventProcess(int x, int y, int button, int event);
key KeyboardEventProcess(int key, int event);
#endif