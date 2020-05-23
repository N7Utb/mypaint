#include "operation.h"
#include "windraw.h"
#include "draw.h"

/*void move(double x, double y)
{
	switch (select_what)
	{
	case 1:
	{
		selected_rect->x += x;
		selected_rect->y += y;
		break;
	}
	case 2:
	{
		selected_roundrect->x += x;
		selected_roundrect->y += y;
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
		Ratio_of_length_to_width = selected_rect->height / selected_rect->width;
		if (selected_rect->height >= (winheight - 3 * h) || selected_rect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_rect->height += Ratio_of_length_to_width * 0.1;
		selected_rect->width += 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_roundrect->height / selected_roundrect->width;
		if (selected_roundrect->height >= (winheight - 3 * h) || selected_roundrect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_roundrect->height += Ratio_of_length_to_width * 0.1;
		selected_roundrect->width += 0.1;
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
		Ratio_of_length_to_width = selected_rect->height / selected_rect->width;
		if (selected_rect->height >= (winheight - 3 * h) || selected_rect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_rect->height -= Ratio_of_length_to_width * 0.1;
		selected_rect->width -= 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_roundrect->height / selected_roundrect->width;
		if (selected_roundrect->height >= (winheight - 3 * h) || selected_roundrect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_roundrect->height -= Ratio_of_length_to_width * 0.1;
		selected_roundrect->width -= 0.1;
		break;
	}
	}
}
*/
#include "operation.h"
#include "windraw.h"
#include "draw.h"
#include "math.h" 

void move(double x, double y)
{
	switch (select_what)
	{
	case 1:
	{
		selected_rect->x += x;
		selected_rect->y += y;
		break;
	}
	case 2:
	{
		selected_roundrect->x += x;
		selected_roundrect->y += y;
		break;
	}
	case 3:
	{
		selected_diamond->x += x;
		selected_diamond->y += y;
		break;
	}
	case 4:
	{
		selected_line->x1 += x;
		selected_line->y1 += y;
		break;
	}
	case 5:
	{
		selected_directionalconnection->x += x;
		selected_directionalconnection->y += y;
		break;
	}
	case 6:
	{
		selected_bidirectionalconnection->x += x;
		selected_bidirectionalconnection->y += y;
		break;
	}
	case 7:
	{
		selected_dashline->x1 += x;
		selected_dashline->y1 += y;
		break;
	}
	case 8:
	{
		selected_process->x += x;
		selected_process->y += y;
		break;
	}
	case 9:
	{
		selected_circle->x += x;
		selected_circle->y += y;
		break;
	}
	case 10:
	{
		selected_oval->x += x;
		selected_oval->y += y;
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
		Ratio_of_length_to_width = selected_rect->height / selected_rect->width;
		if (selected_rect->height >= (winheight - 3 * h) || selected_rect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_rect->height += Ratio_of_length_to_width * 0.1;
		selected_rect->width += 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_roundrect->height / selected_roundrect->width;
		if (selected_roundrect->height >= (winheight - 3 * h) || selected_roundrect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_roundrect->height += Ratio_of_length_to_width * 0.1;
		selected_roundrect->width += 0.1;
		break;
	}
	case 3:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_diamond->height / selected_diamond->width;
		if (selected_diamond->height >= (winheight - 3 * h) || selected_diamond->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_diamond->height += Ratio_of_length_to_width * 0.1;
		selected_diamond->width += 0.1;
		break;
	}

	case 4:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = selected_line->dy / selected_line->dx;
		double ddx = fabs(selected_line->dx);
		double ddy = fabs(selected_line->dy);

		if (ddy >= (winheight - 3 * h) || ddx >= (winwidth - 30 * h))
		{
			return;
		}
		/*if (selected_line->dy > 0)  selected_line->dy += 0.1;
		else if (selected_line->dy < 0)  selected_line->dy -=  0.1;
		else;

		if (selected_line->dx > 0)        selected_line->dx +=  Ratio_of_dy_to_dx *0.1;
		else if (selected_line->dx < 0)   selected_line->dx -= Ratio_of_dy_to_dx *0.1;
		else;
		*/
		selected_line->dy += Ratio_of_dy_to_dx *0.1;
		selected_line->dx +=  0.1;
		break;
	}

	case 5:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_directionalconnection->dy / selected_directionalconnection->dx;
		if (selected_directionalconnection->dy >= (winheight - 3 * h) || selected_directionalconnection->dx >= (winwidth - 30 * h))
		{
			return;
		}
		selected_directionalconnection->dy += Ratio_of_length_to_width * 0.1;
		selected_directionalconnection->dx += 0.1;
		break;
	}

	case 6:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_bidirectionalconnection->dy / selected_bidirectionalconnection->dx;
		if (selected_bidirectionalconnection->dy >= (winheight - 3 * h) || selected_bidirectionalconnection->dx >= (winwidth - 30 * h))
		{
			return;
		}
		selected_bidirectionalconnection->dy += Ratio_of_length_to_width * 0.1;
		selected_bidirectionalconnection->dx += 0.1;
		break;
	}
	
	case 7:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = selected_dashline->dy / selected_dashline->dx;
		double ddx = fabs(selected_dashline->dx);
		double ddy = fabs(selected_dashline->dy);

		if (ddy >= (winheight - 3 * h) || ddx >= (winwidth - 30 * h))
		{
			return;
		}
		if (selected_dashline->dy > 0)  selected_dashline->dy += Ratio_of_dy_to_dx * 0.1;
		else if (selected_dashline->dy < 0)  selected_dashline->dy -= Ratio_of_dy_to_dx * 0.1;
		else;

		if (selected_dashline->dx > 0)        selected_dashline->dx += 0.1;
		else if (selected_dashline->dx < 0)   selected_dashline->dx -= 0.1;
		else;

		break;
	}

	case 8:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_process->height / selected_process->width;
		if (selected_process->height >= (winheight - 3 * h) || selected_process->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_process->height += Ratio_of_length_to_width * 0.1;
		selected_process->width += 0.1;
		break;
	}
	case 9:
	{

		if (selected_circle->r >= 0.5 * (winheight - 3 * h))
		{
			return;
		}

		selected_circle->r += 0.05;
		break;
	}

	case 10:
	{
		double Ratio_of_ry_to_rx;
		Ratio_of_ry_to_rx = selected_oval->ry / selected_oval->rx;
		if (selected_oval->ry >= 0.5 * (winheight - 3 * h) || selected_oval->rx >= 0.5 * (winwidth - 30 * h))
		{
			return;
		}
		selected_oval->ry += Ratio_of_ry_to_rx * 0.05;
		selected_oval->rx += 0.05;
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
		Ratio_of_length_to_width = selected_rect->height / selected_rect->width;
		if (selected_rect->height >= (winheight - 3 * h) || selected_rect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_rect->height -= Ratio_of_length_to_width * 0.1;
		selected_rect->width -= 0.1;
		break;
	}
	case 2:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_roundrect->height / selected_roundrect->width;
		if (selected_roundrect->height >= (winheight - 3 * h) || selected_roundrect->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_roundrect->height -= Ratio_of_length_to_width * 0.1;
		selected_roundrect->width -= 0.1;
		break;
	}

	case 3:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_diamond->height / selected_diamond->width;
		if (selected_diamond->height >= (winheight - 3 * h) || selected_diamond->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_diamond->height -= Ratio_of_length_to_width * 0.1;
		selected_diamond->width -= 0.1;
		break;
	}

	case 4:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = selected_line->dy / selected_line->dx;
		double ddx = fabs(selected_line->dx);
		double ddy = fabs(selected_line->dy);

		selected_line->dy -= Ratio_of_dy_to_dx * 0.1;
		selected_line->dx -= 0.1;
		break;
	}

	case 5:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_directionalconnection->dy / selected_directionalconnection->dx;
		if (selected_directionalconnection->dy >= (winheight - 3 * h) || selected_directionalconnection->dx >= (winwidth - 30 * h))
		{
			return;
		}
		selected_directionalconnection->dy -= Ratio_of_length_to_width * 0.1;
		selected_directionalconnection->dx -= 0.1;
		break;
	}

	case 6:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_bidirectionalconnection->dy / selected_bidirectionalconnection->dx;
		if (selected_bidirectionalconnection->dy >= (winheight - 3 * h) || selected_bidirectionalconnection->dx >= (winwidth - 30 * h))
		{
			return;
		}
		selected_bidirectionalconnection->dy -= Ratio_of_length_to_width * 0.1;
		selected_bidirectionalconnection->dx -= 0.1;
		break;
	}
	case 7:
	{
		double Ratio_of_dy_to_dx;
		Ratio_of_dy_to_dx = selected_dashline->dy / selected_dashline->dx;
		double ddx = fabs(selected_dashline->dx);
		double ddy = fabs(selected_dashline->dy);

		if (ddy >= (winheight - 3 * h) || ddx >= (winwidth - 30 * h))
		{
			return;
		}
		if (selected_dashline->dy > 0)  selected_dashline->dy -= Ratio_of_dy_to_dx * 0.1;
		else if (selected_dashline->dy < 0)  selected_dashline->dy += Ratio_of_dy_to_dx * 0.1;
		else;

		if (selected_dashline->dx > 0)        selected_dashline->dx -= 0.1;
		else if (selected_dashline->dx < 0)   selected_dashline->dx += 0.1;
		else;

		break;
	}

	case 8:
	{
		double Ratio_of_length_to_width;
		Ratio_of_length_to_width = selected_process->height / selected_process->width;
		if (selected_process->height >= (winheight - 3 * h) || selected_process->width >= (winwidth - 30 * h))
		{
			return;
		}
		selected_process->height -= Ratio_of_length_to_width * 0.1;
		selected_process->width -= 0.1;
		break;
	}
	case 9:
	{

		if (selected_circle->r >= 0.5 * (winheight - 3 * h))
		{
			return;
		}

		selected_circle->r -= 0.05;
		break;
	}

	case 10:
	{
		double Ratio_of_ry_to_rx;
		Ratio_of_ry_to_rx = selected_oval->ry / selected_oval->rx;
		if (selected_oval->ry >= 0.5 * (winheight - 3 * h) || selected_oval->rx >= 0.5 * (winwidth - 30 * h))
		{
			return;
		}
		selected_oval->ry -= Ratio_of_ry_to_rx * 0.05;
		selected_oval->rx -= 0.05;
		break;
	}


	}
}
