#ifndef __OPERATION_H
#define __OPERATION_H
//多文件操作注意各个头文件得包含关系
#include "linklist.h"

void deleterect(myrect* source); 


void move(double x, double y);
void upper();
void downer();
void roundrectrotate(myroundrect* source, double angle);


#endif
