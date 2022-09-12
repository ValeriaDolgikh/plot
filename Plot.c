#include <stdio.h>
#include <string.h>
#include "DisplayDriver.h"
#include "GraphicsEngine.h"
#include "Plot.h"

/*void Array(unsigned int*, int);

int main()
{
	char* amp = "U, V";
  	char* lab_x = "t, c";
  	SetYLabel(amp);
  	SetXLabel(lab_x);

  	unsigned arr[SIZE_OF_SCREEN_LENGTH];
	unsigned int* p_arr = arr;

  	Array(p_arr, SIZE_OF_SCREEN_LENGTH);
  	
  	SetData(p_arr, SIZE_OF_SCREEN_LENGTH);

  	Print();
  	
 	return 0;
}

void Array(unsigned int* p_arr, int size)
{
	for (unsigned i = 0; i < size - 1; i += 4)
	{
		*(p_arr + i) = 6;
		*(p_arr + i + 1) = 6;
		*(p_arr + i + 2) = 30;
		*(p_arr + i + 3) = 30;
	}
	p_arr[size - 1] = 6;
}*/

void AxisPaint()
{
	set_pen('|');
	for(unsigned i = 2; i < SIZE_OF_SCREEN_WIDTH; i++)
	{
		point_2(0, i);
	}
	set_pen('_');
	line_2(1, 2, SIZE_OF_SCREEN_LENGTH, 2);
}

void SinAxisPaint ()
{
	set_pen('|');
	for(unsigned i = 2; i < SIZE_OF_SCREEN_WIDTH; i++)
	{
		point_2(0, i);
	}
	set_pen('_');
	line_2(1, SIZE_OF_SCREEN_WIDTH / 2, SIZE_OF_SCREEN_LENGTH, SIZE_OF_SCREEN_WIDTH / 2);
}

void SetYLabel(char* label_y)
{
	int str_len = strlen(label_y);
	print_text(label_y, 0, SIZE_OF_SCREEN_WIDTH);
}

void SetXLabel(char* label_x)
{
	int str_len = strlen(label_x);
	//print_text(label_x, SIZE_OF_SCREEN_LENGTH - str_len, 1);                          //обе оси положительные
	print_text(label_x, SIZE_OF_SCREEN_LENGTH - str_len, SIZE_OF_SCREEN_WIDTH / 2 - 1); //ось y отрицательная
}

void SetData(int* data, int size)
{
	set_pen('*');

	for(unsigned i = 0; i < size; i++)
	{
		point_2(i + 1, *(data + i) + 1);
	}
}

void Print()
{
	//AxisPaint();
	SinAxisPaint();
	update();
}