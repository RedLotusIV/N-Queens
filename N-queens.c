
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int	isValid(int posY, int posX, int **queens, int n)
{
	int columns = 0;
	int rows = 0;
	for (int i = 0 ; i < n, queens[i]; i++)
	{
		for(int j = 0; i < n, queens[i][j] ; j++)
		{
			if (queens[i][j] == 1 && ((posY - i == posX - j) ||
							(posX == j) || (posY == i) ||
							(posX - 1 == j && posY - 1 == i) ||
							(posX + 1 == j && posY + 1 == i)))
				return 0;
		}
	}
	return 1;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
	char ***array;
	int columns = n;
	int rows = n;
	int x = 0;
	int y = 0;

	returnSize = malloc(sizeof(int));
	array = malloc(sizeof(char **) * (n + 1));
	array[n] = NULL;
	returnColumnSizes = malloc(sizeof(int *) * n);

	for (int i = 0; i < n; i++)
	{
		returnColumnSizes[i] = malloc(sizeof(int) * n);
		array[i] = malloc(sizeof(char) * (n + 1));
		for (int j = 0; j < n; j++)
		{
      		array[i][j] = malloc(sizeof(char) * (n + 1));
		}
	}
	for (; y < columns ; y++)
		for (x = 0; x < rows ; x++)
		{
			if(isValid(y, x, returnColumnSizes, n))
			{
				array[y][x][0] = 'Q';
				returnColumnSizes[y][x] = 1;
				for (int tmp = x ; tmp < rows - 1; tmp++)
				{
					array[y][tmp + 1][0] = '.';
					returnColumnSizes[y][tmp + 1] = 0;
				}
				break;
			}
			else
			{
				array[y][x][0] = '.';
				returnColumnSizes[y][x] = 0;
			}
		}
		*returnSize = n;
		return (array);
}

int main()
{
	int **returnColumnSizes;
	int returnSizes;
	int n = 8;
	char ***solved = solveNQueens(n, &returnSizes, returnColumnSizes);
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++) {
            printf("%c", solved[i][j][0]);
        }
        printf("\n");
	}
}