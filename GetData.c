#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Error.h"

int ReadData(int16_t** data, const char* name_of_file)
{
	FILE *my_file = NULL;
	my_file = fopen(name_of_file, "rb");
	if (my_file == NULL)
	{
        return ERROR_FILE_OPEN;
    }
    
    fseek(my_file, 0L, SEEK_END);
    int size = ftell(my_file); //количество байт в файле
    rewind(my_file);
    
    *data = (int16_t*) malloc(size);
    int count = size / sizeof(int16_t);  //количество чисел в файле
    
    int fread_res = fread(*data, sizeof(int16_t), count, my_file);

    /*printf("data in read data\n");
    for(unsigned i = 0; i < fread_res; i++)
    {
        printf("%d ", (*data)[i]);
    }
    printf("\n");*/

	fclose(my_file);
	return fread_res;
}