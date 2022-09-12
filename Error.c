#include <stdio.h>

typedef enum
{
	ERROR_CODE_ARGC = -2,
	ERROR_CODE_FILE_NAME = -3,
	ERROR_FILE_OPEN = -1,
	ERROR_CODE_OF_BITWIDTH = -4
}error_code;

void print_error(int code);

void print_error(int code)
{
	switch(code)
	{
		case ERROR_CODE_ARGC:
		{
			printf("wrong number of arguments\n");
			break;
		}
		case ERROR_CODE_FILE_NAME:
		{
			printf("wrong name of file\n");
			break;
		}
		case ERROR_FILE_OPEN:
		{
			printf("file is not open\n");
			break;
		}
		case ERROR_CODE_OF_BITWIDTH:
		{
			printf("wrong bitwidth argument\n");
			break;
		}
	}
}