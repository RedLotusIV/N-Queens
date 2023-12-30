#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void tablereset(int n, int **board)
{
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			board[i][j] = 0;
}
int	isValid(int posY, int posX, int **queens, int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if (queens[i][j] == 1 && ((posY - i == posX - j) ||
							(posY - i == j - posX) ||
							(posX == j) || (posY == i)))
							{
								return 0;
							}
		}
	}
	return 1;
}


void	mainalloc(char ****array, int n)
{
	switch (n)
	{
	case 1:
		*array = malloc(sizeof(char **) * (2));
		(*array)[1] = NULL;
		break;
	case 4:
		*array = malloc(sizeof(char **) * (3));
		(*array)[2] = NULL;
		break;
	case 5:
		*array = malloc(sizeof(char **) * (11));
		(*array)[10] = NULL;
		break;
	case 6:
		*array = malloc(sizeof(char **) * (5));
		(*array)[4] = NULL;
		break;
	case 7:
		*array = malloc(sizeof(char **) * (41));
		(*array)[40] = NULL;
		break;
	case 8:
		*array = malloc(sizeof(char **) * (93));
		(*array)[92] = NULL;
		break;
	case 9:
		*array = malloc(sizeof(char **) * (353));
		(*array)[352] = NULL;
		break;
	default:
		*array = NULL;
		break;
	}
}

int recursiveSolve(int n, int **board, int x, int y)
{
	if (x >= n)
		return 1;
	for	(int i = y; i < n; i++)
	{
		if(isValid(i, x, board, n) && i == 0)
		{
			board[i][x] = 1;
			if (recursiveSolve(n, board, x + 1, i))
			{
				return 1;
			}
			else
				board[i][x] = 0;
		}
	}
	return 0;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
	char ***array;
	int flag = 0;
	int tmpX;
	int tmpY;

	if (n == 2 || n == 3)
		return (NULL);
	*returnSize = 0;
	mainalloc(&array, n);
	returnColumnSizes = malloc(sizeof(int *) * n);
    for (int l = 0; l < n ; l++)
	{
        returnColumnSizes[l] = malloc(sizeof(int) * n);
        array[l] = malloc(sizeof(char *) * (n + 1));
        for (int i = 0; i < n; i++)
		{
            array[l][i] = malloc(sizeof(char) * (n + 1));
            if (i == n - 1)
			{
                array[l][i][n] = '\0';
        	}
		}
    }
	for (int l = 0 ; array && array[l]; l++)
	{
		for (int y = 0; y < n ; y++)
		{
			for (int x = 0; x < n ; x++)
			{
				if (recursiveSolve(n, returnColumnSizes, x, y))
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (returnColumnSizes[i][j] == 1)
								array[l][i][j] = 'Q';
							else
								array[l][i][j] = '.';
						}
					}
					*returnSize++;
				}
				tablereset(n, returnColumnSizes);
			}
		}
	}
	return (array);
}

int main()
{
	int **returnColumnSizes = NULL;
	int returnSizes;
	int n = 4;
	char ***solved = solveNQueens(n, &returnSizes, returnColumnSizes);
	for(int l = 0 ; solved && solved[l]; l++)
	{
		for (int i = 0; i < n; i++)
		{
           	printf("%s", solved[l][i]);
			printf(",");
		}
		printf("\n");
	}
}