#include "main.h"
#include <stdlib.h>

/**
*free_grid - frees a 2-D grid
*@grid: dimensional array
*@height: height of the grid
*
*Return: Always 0
*/
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
