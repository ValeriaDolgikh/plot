#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "DisplayDriver.h"
#include "DataProcessing.h"
#include "Plot.h"

void convert_data(int16_t* data, int* new_data, int size)
{
	int16_t y_max = yMax(data, size);
  	int h = (y_max * 2) / SIZE_OF_SCREEN_WIDTH;

	for(unsigned i = 0; i < size; i++)
	{
		new_data[i] = (data[i] / h) + (SIZE_OF_SCREEN_WIDTH / 2) - 1;
	}
	SetData(new_data, size);
}

int16_t yMax (int16_t* data, int size)
{
	int16_t y_max = 0;
	for(unsigned i = 0; i < size; i++)
	{
		if (data[i] > y_max)
		{
			y_max = data[i];
		}
	}
	return y_max;
}

/*int16_t yMin (int16_t* data, int size)
{
	int16_t y_min = 0;
	for(unsigned i = 0; i < size; i++)
	{
		if (data[i] < y_min)
		{
			y_min = data[i];
		}
	}
	return y_min;
}

int period_count (int16_t* data, int size)
{
	int16_t y_max = yMax(data, size);
	int count = 0;

	for(unsigned i = 0; i < size; i++)
	{
		if(data[i] == y_max)
		{
			count += 1;
		}
	}
	return count;
}*/