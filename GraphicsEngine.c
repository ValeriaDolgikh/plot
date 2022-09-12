#include <stdio.h>
#include <string.h>
#include <math.h>
#include "DisplayDriver.h"
#include "GraphicsEngine.h"

char pen;

//void set_coord(TCoord* point1, TCoord* point2);

/*int main()
{
   
  set_pen('*');
  //point_2(60, 2);
  //line_2(1, 1, 10, 10);
  char* lab_x = "100";
  print_text(lab_x, 149, 1);

   print_screen(SIZE_OF_SCREEN_WIDTH, SIZE_OF_SCREEN_LENGTH);
   return 0;
}*/

void print_text(char* str, int x, int y)
{
	int str_len = strlen(str);
	int numb_of_str = str_len/(SIZE_OF_SCREEN_LENGTH - x) + 1;

	unsigned r_y = SIZE_OF_SCREEN_WIDTH - y;

	if(str_len > SIZE_OF_SCREEN_LENGTH - x)
	{
		for(unsigned j = r_y - numb_of_str; j < r_y; j++)  
		{
			for(unsigned i = x; i < SIZE_OF_SCREEN_LENGTH; i++)
			{
				screen[j][i] = *str++;
			}
		}
	}
	else
	{
		for(unsigned i = x; i < x + str_len; i++)
		{
			screen[r_y][i] = *str++;
		}
	}
}

void print_text_2(char* str, const TCoord* const point_coord)
{
	int str_len = strlen(str);
	int numb_of_str = str_len/(SIZE_OF_SCREEN_LENGTH - point_coord->x) + 1;

	unsigned r_y = SIZE_OF_SCREEN_WIDTH - point_coord->y;

	if(str_len > SIZE_OF_SCREEN_LENGTH - point_coord->x)
	{
		for(unsigned j = r_y - numb_of_str; j < r_y; j++)  
		{
			for(unsigned i = point_coord->x; i < SIZE_OF_SCREEN_LENGTH; i++)
			{
				screen[j][i] = *str++;
			}
		}
	}
	else
	{
		for(unsigned i = point_coord->x; i < point_coord->x + str_len; i++)
		{
			screen[r_y][i] = *str++;
		}
	}
}

void set_pen(const char a)
{
	pen = a;
}

void point(const TCoord* const point_coord)
{
	screen[SIZE_OF_SCREEN_WIDTH - point_coord->y][point_coord->x] = pen;
}

void point_2(int x, int y)
{
	screen[SIZE_OF_SCREEN_WIDTH - y][x] = pen;
}

void line(const TCoord* const point1, const TCoord* const point2)
{
	for (int xi = point1->x; xi < point2->x; xi++)
	{
		int yi = (((xi - point1->x) * (point2->y - point1->y))/(point2->x - point1->x)) + point1->y;
		point_2(xi, yi);
	}
}

void line_2(int x1, int y1, int x2, int y2)
{
	for (int xi = x1; xi < x2; xi++)
	{
		int yi = (((xi - x1) * (y2 - y1))/(x2 - x1)) + y1;
		point_2(xi, yi);
	}
}

/*void set_coord(TCoord* point1, TCoord* point2)
{
	point1->x = 1;
	point1->y = 1;
	point2->x = 10;
	point2->y = 10;
}*/

void update()
{
	print_screen(SIZE_OF_SCREEN_WIDTH, SIZE_OF_SCREEN_LENGTH);
}