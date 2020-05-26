#ifndef __FILE_H
#define __FILE_H
#include <windows.h>
#include <Commdlg.h>
#include <stdio.h>
#pragma comment(lib,"Winmm.lib")
#include<mmsystem.h>
//调用windows API 实现与windows中得文件管理器得交互、函数代码摘自csdn
int FileOpenDialog(char* path);//可以打开文件会话框
int FileSaveDialog(char* path);


#endif
