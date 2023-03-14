#include "main.h"
#include <stdlib.h>

/**
*alloc_grid - 2 dimensional array of integers
*@width: width of integer
*@height: height of integer
*
*Return: a pointer to 2D array
*/
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	/*check of non-valid input*/
	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	/*allocates memory for the rows of the grid*/
	grid = (int **)malloc(height * sizeof(int *));

	if (grid == NULL)
	{
		return (NULL);
	}

	/*Allocate memory for the columns of each row*/
	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(width * sizeof(int));
	}
	if (grid[i] == NULL)
	{
	/*Free previously allocated memory and return NULL on failure*/
	for (j = 0; j < i; j++)
	{
	free(grid[j]);
	}
	free(grid);
		return (NULL);
	}
	/*Initialize each element of the grid to 0*/
	for (j = 0; j < width; j++)
	{
		grid[i][j] = 0;
	}
	return (grid);
}
