typedef enum
{
	ERROR_CODE_ARGC = -2,
	ERROR_CODE_FILE_NAME = -3,
	ERROR_FILE_OPEN = -1,
	ERROR_CODE_OF_BITWIDTH = -4
}error_code;

void print_error(int code);