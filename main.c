#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Plot.h"
#include "DataProcessing.h"
#include "GetData.h"
#include "Error.h"

/*агрументы:
1. имя файла (C:\Users\UserPC\Desktop\c++\sin_gen\data.txt)*/

//gcc DisplayDriver.c GraphicsEngine.c Plot.c DataProcessing.c GetData.c Error.c main.c

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error(ERROR_CODE_ARGC);
		return ERROR_CODE_ARGC;
	}

	char* name_of_file = argv[1];

	int16_t* data;

	int is_read = ReadData(&data, name_of_file);	
	if(is_read == ERROR_FILE_OPEN)
	{
		print_error(ERROR_FILE_OPEN);
		return ERROR_FILE_OPEN;
	}
  	
  	int real_data[is_read];
  	int* p_real_data = real_data;

  	convert_data(data, p_real_data, is_read);

  	char* lab_x = "t, c";
  	char* amp_y = "U, V";

  	SetYLabel(amp_y);
  	SetXLabel(lab_x);

/*  	int y_max = yMax(data, is_read);
  	char amp_numb[10];
  	printf("%s", itoa(y_max, amp_numb, 10));*/

  	Print();
 	free(data);
	return 0;
}