
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// int	isValid(int posY, int posX, char **queens)
// {
// 	int columns = 0;
// 	int rows = 0;
// 	for (int i = 0 ; queens[i] ; i++)
// 		for(int j = 0; queens[i][j] ; j++)
// 		{

// 		}

// }

// char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
// {
// 	char **array;
// 	int columns = n;
// 	int rows = n;
// 	array = malloc(sizeof(char *) * (n + 1));

// 	for (int y = 0 ; y < columns ; y++)
// 		for (int x = 0 ; x < rows ; x++)
// 		{
// 			if(isValid(y, x, array))
// 			{
// 				array[y][x] = 'Q';
// 				for (int tmp = x + 1 ; tmp < rows ; tmp++)
// 					array[y][x] = '.';
// 				break;
// 			}
// 			else
// 				array[y][x] = '.';
// 		}
// 		return (&array);
// }

int main()
{
	int n = 4;
	char **array = malloc(sizeof(char *) * (n + 1));
	for(int i = 0 ; i < n ;i++)
	{
		strcpy();
	}
	int columns = n;
	int rows = n;
	array = malloc(sizeof(char *) * (n + 1));

	for (int y = 0 ; y < columns ; y++)
		for (int x = 0 ; x < rows ; x++)
		{
			if(isValid(y, x, array))
			{
				array[y][x] = 'Q';
				for (int tmp = x + 1 ; tmp < rows ; tmp++)
					array[y][x] = '.';
				break;
			}
			else
				array[y][x] = '.';
		}
}