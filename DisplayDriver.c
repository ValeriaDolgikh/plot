#include <stdio.h>
#include <stdlib.h>
#include "DisplayDriver.h"

char screen[SIZE_OF_SCREEN_WIDTH][SIZE_OF_SCREEN_LENGTH];

void null_screen(int row, int col)
{
  for(unsigned i = 0; i < row; i++)
  {
    for(unsigned j = 0; j < col; j++)
    {
      *(&screen[0][0] + i * col * sizeof(char) + j * sizeof(char)) = ' ';
    }
  }
}

void print_screen(int row, int col)
{
  for(unsigned i = 0; i < row; i++)
  {
    for(unsigned j = 0; j < col; j++)
    {
      printf("%c", *(&screen[0][0] + i * col * sizeof(char) + j * sizeof(char)));
    }
    printf("\n");
  }
}