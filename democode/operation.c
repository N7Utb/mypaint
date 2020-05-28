#include "operation.h"
#include "windraw.h"
#include "draw.h"

/*void move(double x, double y)
{
	switch (select_what)
	{
	case 1:
	{
		((myrect*)select_ptr)->x += x;
		((myrect*)select_ptr)->y += y;
		break;
	}
	case 2:
	{
		((myroundrect*)select_ptr)->x += x;
		((myroundrect*)select_ptr)->y += y;
		break;
	}
	}
		
}

void upper()
{
	switch (select_what)
	{
	case 1:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myrect*)select_ptr)->height / ((myrect*)select_ptr)->width;
		if (((myrect*)select_ptr)->height >= (winheight - 3 * h) || ((myrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myrect*)select_ptr)->height += Ratio_of_length_to_width * 0.1;
		((myrect*)select_ptr)->width += 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myroundrect*)select_ptr)->height / ((myroundrect*)select_ptr)->width;
		if (((myroundrect*)select_ptr)->height >= (winheight - 3 * h) || ((myroundrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myroundrect*)select_ptr)->height += Ratio_of_length_to_width * 0.1;
		((myroundrect*)select_ptr)->width += 0.1;
		break;
	}
	}
}
void downer()
{
	switch (select_what)
	{
	case 1:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myrect*)select_ptr)->height / ((myrect*)select_ptr)->width;
		if (((myrect*)select_ptr)->height >= (winheight - 3 * h) || ((myrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myrect*)select_ptr)->height -= Ratio_of_length_to_width * 0.1;
		((myrect*)select_ptr)->width -= 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myroundrect*)select_ptr)->height / ((myroundrect*)select_ptr)->width;
		if (((myroundrect*)select_ptr)->height >= (winheight - 3 * h) || ((myroundrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myroundrect*)select_ptr)->height -= Ratio_of_length_to_width * 0.1;
		((myroundrect*)select_ptr)->width -= 0.1;
		break;
	}
	}
}
*/
#include "operation.h"
#include "windraw.h"
#include "draw.h"
#include "math.h" 

//��ѡ�е�ͼ��Ԫ
void move(double x, double y)
{
	switch (select_what)
	{
	case 1:
	{
		((myrect*)select_ptr)->x += x;
		((myrect*)select_ptr)->y += y;
		break;
	}
	case 2:
	{
		((myroundrect*)select_ptr)->x += x;
		((myroundrect*)select_ptr)->y += y;
		break;
	}
	case 3:
	{
		((mydiamond*)select_ptr)->x += x;
		((mydiamond*)select_ptr)->y += y;
		break;
	}
	case 4:
	{
		((myline*)select_ptr)->x1 += x;
		((myline*)select_ptr)->y1 += y;
		break;
	}
	case 5:
	{
		((mydirectionalconnection*)select_ptr)->x += x;
		((mydirectionalconnection*)select_ptr)->y += y;
		break;
	}
	case 6:
	{
		((mybidirectionalconnection*)select_ptr)->x += x;
		((mybidirectionalconnection*)select_ptr)->y += y;
		break;
	}
	case 7:
	{
		((mydashline*)select_ptr)->x1 += x;
		((mydashline*)select_ptr)->y1 += y;
		break;
	}
	case 8:
	{
		((myprocess*)select_ptr)->x += x;
		((myprocess*)select_ptr)->y += y;
		break;
	}
	case 9:
	{
		((mycircle*)select_ptr)->x += x;
		((mycircle*)select_ptr)->y += y;
		break;
	}
	case 10:
	{
		((myoval*)select_ptr)->x += x;
		((myoval*)select_ptr)->y += y;
		break;
	}

	}

}

void upper()
{
	switch (select_what)
	{
	case 1:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myrect*)select_ptr)->height / ((myrect*)select_ptr)->width;
		if (((myrect*)select_ptr)->height >= (winheight - 3 * h) || ((myrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myrect*)select_ptr)->height += Ratio_of_length_to_width * 0.1;
		((myrect*)select_ptr)->width += 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myroundrect*)select_ptr)->height / ((myroundrect*)select_ptr)->width;
		if (((myroundrect*)select_ptr)->height >= (winheight - 3 * h) || ((myroundrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myroundrect*)select_ptr)->height += Ratio_of_length_to_width * 0.1;
		((myroundrect*)select_ptr)->width += 0.1;
		break;
	}
	case 3:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((mydiamond*)select_ptr)->height / ((mydiamond*)select_ptr)->width;
		if (((mydiamond*)select_ptr)->height >= (winheight - 3 * h) || ((mydiamond*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((mydiamond*)select_ptr)->height += Ratio_of_length_to_width * 0.1;
		((mydiamond*)select_ptr)->width += 0.1;
		break;
	}

	case 4:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = ((myline*)select_ptr)->dy / ((myline*)select_ptr)->dx;
		double ddx = fabs(((myline*)select_ptr)->dx);
		double ddy = fabs(((myline*)select_ptr)->dy);

		if (ddy >= (winheight - 3 * h) || ddx >= (winwidth - 30 * h))
		{
			return;
		}
		/*if (((myline*)select_ptr)->dy > 0)  ((myline*)select_ptr)->dy += 0.1;
		else if (((myline*)select_ptr)->dy < 0)  ((myline*)select_ptr)->dy -=  0.1;
		else;

		if (((myline*)select_ptr)->dx > 0)        ((myline*)select_ptr)->dx +=  Ratio_of_dy_to_dx *0.1;
		else if (((myline*)select_ptr)->dx < 0)   ((myline*)select_ptr)->dx -= Ratio_of_dy_to_dx *0.1;
		else;
		*/
		((myline*)select_ptr)->dy += Ratio_of_dy_to_dx *0.1;
		((myline*)select_ptr)->dx +=  0.1;
		break;
	}

	case 5:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((mydirectionalconnection*)select_ptr)->dy / ((mydirectionalconnection*)select_ptr)->dx;
		if (((mydirectionalconnection*)select_ptr)->dy >= (winheight - 3 * h) || ((mydirectionalconnection*)select_ptr)->dx >= (winwidth - 30 * h))
		{
			return;
		}
		((mydirectionalconnection*)select_ptr)->dy += Ratio_of_length_to_width * 0.1;
		((mydirectionalconnection*)select_ptr)->dx += 0.1;
		break;
	}

	case 6:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((mybidirectionalconnection*)select_ptr)->dy / ((mybidirectionalconnection*)select_ptr)->dx;
		if (((mybidirectionalconnection*)select_ptr)->dy >= (winheight - 3 * h) || ((mybidirectionalconnection*)select_ptr)->dx >= (winwidth - 30 * h))
		{
			return;
		}
		((mybidirectionalconnection*)select_ptr)->dy += Ratio_of_length_to_width * 0.1;
		((mybidirectionalconnection*)select_ptr)->dx += 0.1;
		break;
	}
	
	case 7:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = ((mydashline*)select_ptr)->dy / ((mydashline*)select_ptr)->dx;
		double ddx = fabs(((mydashline*)select_ptr)->dx);
		double ddy = fabs(((mydashline*)select_ptr)->dy);

		if (ddy >= (winheight - 3 * h) || ddx >= (winwidth - 30 * h))
		{
			return;
		}
		if (((mydashline*)select_ptr)->dy > 0)  ((mydashline*)select_ptr)->dy += Ratio_of_dy_to_dx * 0.1;
		else if (((mydashline*)select_ptr)->dy < 0)  ((mydashline*)select_ptr)->dy -= Ratio_of_dy_to_dx * 0.1;
		else;

		if (((mydashline*)select_ptr)->dx > 0)        ((mydashline*)select_ptr)->dx += 0.1;
		else if (((mydashline*)select_ptr)->dx < 0)   ((mydashline*)select_ptr)->dx -= 0.1;
		else;

		break;
	}

	case 8:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myprocess*)select_ptr)->height / ((myprocess*)select_ptr)->width;
		if (((myprocess*)select_ptr)->height >= (winheight - 3 * h) || ((myprocess*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myprocess*)select_ptr)->height += Ratio_of_length_to_width * 0.1;
		((myprocess*)select_ptr)->width += 0.1;
		break;
	}
	case 9:
	{

		if (((mycircle*)select_ptr)->r >= 0.5 * (winheight - 3 * h))
		{
			return;
		}

		((mycircle*)select_ptr)->r += 0.05;
		break;
	}

	case 10:
	{
		double Ratio_of_ry_to_rx;
		Ratio_of_ry_to_rx = ((myoval*)select_ptr)->ry / ((myoval*)select_ptr)->rx;
		if (((myoval*)select_ptr)->ry >= 0.5 * (winheight - 3 * h) || ((myoval*)select_ptr)->rx >= 0.5 * (winwidth - 30 * h))
		{
			return;
		}
		((myoval*)select_ptr)->ry += Ratio_of_ry_to_rx * 0.05;
		((myoval*)select_ptr)->rx += 0.05;
		break;
	}

	}
}
void downer()
{
	switch (select_what)
	{
	case 1:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myrect*)select_ptr)->height / ((myrect*)select_ptr)->width;
		if (((myrect*)select_ptr)->height >= (winheight - 3 * h) || ((myrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myrect*)select_ptr)->height -= Ratio_of_length_to_width * 0.1;
		((myrect*)select_ptr)->width -= 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myroundrect*)select_ptr)->height / ((myroundrect*)select_ptr)->width;
		if (((myroundrect*)select_ptr)->height >= (winheight - 3 * h) || ((myroundrect*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myroundrect*)select_ptr)->height -= Ratio_of_length_to_width * 0.1;
		((myroundrect*)select_ptr)->width -= 0.1;
		break;
	}

	case 3:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((mydiamond*)select_ptr)->height / ((mydiamond*)select_ptr)->width;
		if (((mydiamond*)select_ptr)->height >= (winheight - 3 * h) || ((mydiamond*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((mydiamond*)select_ptr)->height -= Ratio_of_length_to_width * 0.1;
		((mydiamond*)select_ptr)->width -= 0.1;
		break;
	}

	case 4:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = ((myline*)select_ptr)->dy / ((myline*)select_ptr)->dx;
		double ddx = fabs(((myline*)select_ptr)->dx);
		double ddy = fabs(((myline*)select_ptr)->dy);

		((myline*)select_ptr)->dy -= Ratio_of_dy_to_dx * 0.1;
		((myline*)select_ptr)->dx -= 0.1;
		break;
	}

	case 5:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((mydirectionalconnection*)select_ptr)->dy / ((mydirectionalconnection*)select_ptr)->dx;
		if (((mydirectionalconnection*)select_ptr)->dy >= (winheight - 3 * h) || ((mydirectionalconnection*)select_ptr)->dx >= (winwidth - 30 * h))
		{
			return;
		}
		((mydirectionalconnection*)select_ptr)->dy -= Ratio_of_length_to_width * 0.1;
		((mydirectionalconnection*)select_ptr)->dx -= 0.1;
		break;
	}

	case 6:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((mybidirectionalconnection*)select_ptr)->dy / ((mybidirectionalconnection*)select_ptr)->dx;
		if (((mybidirectionalconnection*)select_ptr)->dy >= (winheight - 3 * h) || ((mybidirectionalconnection*)select_ptr)->dx >= (winwidth - 30 * h))
		{
			return;
		}
		((mybidirectionalconnection*)select_ptr)->dy -= Ratio_of_length_to_width * 0.1;
		((mybidirectionalconnection*)select_ptr)->dx -= 0.1;
		break;
	}
	case 7:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = ((mydashline*)select_ptr)->dy / ((mydashline*)select_ptr)->dx;
		double ddx = fabs(((mydashline*)select_ptr)->dx);
		double ddy = fabs(((mydashline*)select_ptr)->dy);

		if (ddy >= (winheight - 3 * h) || ddx >= (winwidth - 30 * h))
		{
			return;
		}
		if (((mydashline*)select_ptr)->dy > 0)  ((mydashline*)select_ptr)->dy -= Ratio_of_dy_to_dx * 0.1;
		else if (((mydashline*)select_ptr)->dy < 0)  ((mydashline*)select_ptr)->dy += Ratio_of_dy_to_dx * 0.1;
		else;

		if (((mydashline*)select_ptr)->dx > 0)        ((mydashline*)select_ptr)->dx -= 0.1;
		else if (((mydashline*)select_ptr)->dx < 0)   ((mydashline*)select_ptr)->dx += 0.1;
		else;

		break;
	}

	case 8:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = ((myprocess*)select_ptr)->height / ((myprocess*)select_ptr)->width;
		if (((myprocess*)select_ptr)->height >= (winheight - 3 * h) || ((myprocess*)select_ptr)->width >= (winwidth - 30 * h))
		{
			return;
		}
		((myprocess*)select_ptr)->height -= Ratio_of_length_to_width * 0.1;
		((myprocess*)select_ptr)->width -= 0.1;
		break;
	}
	case 9:
	{

		if (((mycircle*)select_ptr)->r >= 0.5 * (winheight - 3 * h))
		{
			return;
		}

		((mycircle*)select_ptr)->r -= 0.05;
		break;
	}

	case 10:
	{
		double Ratio_of_ry_to_rx;
		Ratio_of_ry_to_rx = ((myoval*)select_ptr)->ry / ((myoval*)select_ptr)->rx;
		if (((myoval*)select_ptr)->ry >= 0.5 * (winheight - 3 * h) || ((myoval*)select_ptr)->rx >= 0.5 * (winwidth - 30 * h))
		{
			return;
		}
		((myoval*)select_ptr)->ry -= Ratio_of_ry_to_rx * 0.05;
		((myoval*)select_ptr)->rx -= 0.05;
		break;
	}


	}
}
void changefillcolor(int para)
{
	switch (select_what)
	{
	case 1:
	{
		strcpy(((myrect*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 2:
	{
		strcpy(((myroundrect*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 3:
	{
		strcpy(((mydiamond*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 4:
	{
		strcpy(((myline*)select_ptr)->pencolor, bColors[para]);
		break;
	}
	case 5:
	{
		strcpy(((mydirectionalconnection*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 6:
	{
		strcpy(((mybidirectionalconnection*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 7:
	{
		strcpy(((mydashline*)select_ptr)->pencolor, bColors[para]);
		break;
	}
	case 8:
	{
		strcpy(((myprocess*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 9:
	{
		strcpy(((mycircle*)select_ptr)->fill_color, bColors[para]);
		break;
	}
	case 10:
	{
		strcpy(((myoval*)select_ptr)->fill_color, bColors[para]);
		break;

	}

	}
}
void changefontcolor(int para)
{
	switch (select_what)
	{
	case 1:
	{
		strcpy(((myrect*)select_ptr)->front_color, bColors[para]);
		break;
	}
	case 2:
	{
		strcpy(((myroundrect*)select_ptr)->front_color, bColors[para]);
		break;
	}
	case 3:
	{
		strcpy(((mydiamond*)select_ptr)->front_color, bColors[para]);
		break;
	}
	case 4:
	{

		break;
	}
	case 5:
	{
		break;
	}
	case 6:
	{

		break;
	}
	case 7:
	{

		break;
	}
	case 8:
	{
		strcpy(((myprocess*)select_ptr)->front_color, bColors[para]);
		break;
	}
	case 9:
	{
		strcpy(((mycircle*)select_ptr)->front_color, bColors[para]);
		break;
	}
	case 10:
	{
		strcpy(((myoval*)select_ptr)->front_color, bColors[para]);
		break;

	}

	}
}
void changealigment(char para)
{
	switch (select_what)
	{
	case 1:
	{
		((myrect*)select_ptr)->alignment = para;
		break;
	}
	case 2:
	{
		((myroundrect*)select_ptr)->alignment = para;
		break;
	}
	case 3:
	{
		((myrect*)select_ptr)->alignment = para;
		break;
	}
	case 4:
	{

		break;
	}
	case 5:
	{
		break;
	}
	case 6:
	{

		break;
	}
	case 7:
	{

		break;
	}
	case 8:
	{
		((myprocess*)select_ptr)->alignment = para;
		break;
	}
	case 9:
	{
		((mycircle*)select_ptr)->alignment = para;
		break;
	}
	case 10:
	{
		((myoval*)select_ptr)->alignment = para;
		break;

	}

	}
}
void changefillflag(int para)
{
	switch (select_what)
	{
	case 1:
	{
		((myrect*)select_ptr)->fillflag = para;
		break;
	}
	case 2:
	{
		((myroundrect*)select_ptr)->fillflag = para;
		break;
	}
	case 3:
	{
		((mydiamond*)select_ptr)->fillflag = para;
		break;
	}
	case 4:
	{

		break;
	}
	case 5:
	{
		((mydirectionalconnection*)select_ptr)->fillflag = para;
		break;
	}
	case 6:
	{
		((mybidirectionalconnection*)select_ptr)->fillflag = para;
		break;
	}
	case 7:
	{

		break;
	}
	case 8:
	{
		((myprocess*)select_ptr)->fillflag = para;
		break;
	}
	case 9:
	{
		((mycircle*)select_ptr)->fillflag = para;
		break;
	}
	case 10:
	{
		((myoval*)select_ptr)->fillflag = para;
		break;

	}

	}
}
void clockwiserotate()
{

}
void anticlockwiserotate()
{

}