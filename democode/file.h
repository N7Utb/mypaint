#ifndef __FILE_H
#define __FILE_H
#include <windows.h>
#include <Commdlg.h>
#include <stdio.h>
//����windows API ʵ����windows�е��ļ��������ý�������������ժ��csdn
int FileOpenDialog(char* path);//���Դ��ļ��Ự��
int FileSaveDialog(char* path);
#endif
