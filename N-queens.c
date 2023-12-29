#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void removeQueen(char ***array, int posY, int PosX)
{
	(*array)[posY][PosX] = '.';
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

int recursiveSolve(int n, int **board, int y)
{
	if (y >= n)
		return 1;
	for	(int i = 0; i < n; i++)
	{
		if(isValid(i, y, board, n))
		{
			board[i][y] = 1;
			if (recursiveSolve(n, board, y + 1))
			{
				return 1;
			}
			else
				board[i][y] = 0;
		}
	}
	return 0;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
	char ***array;
	int flag = 0;
	int x;
	int y;
	int tmpX;
	int tmpY;

	returnSize = malloc(sizeof(int));
	array = malloc(sizeof(char **) * (n + 1));
	array[n] = NULL;
	returnColumnSizes = malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
	{
        returnColumnSizes[i] = malloc(sizeof(int) * n);
        array[i] = malloc(sizeof(char *) * (n + 1));
        for (int j = 0; j < n; j++)
		{
            array[i][j] = malloc(sizeof(char) * (n + 1));
            if (j == n - 1)
			{
                *array[i][n-1] = '\0';
        	}
		}
    }
    if (recursiveSolve(n, returnColumnSizes, 0))
	{
        for (int i = 0; i < n; i++)
		{
            for (int j = 0; j < n; j++)
			{
                if (returnColumnSizes[i][j] == 1)
                    *array[i][j] = 'Q';
				else
					*array[i][j] = '.';
            }
        }
        *returnSize = n;
    }
	else
	{
        *returnSize = 0;
    }
	return (array);
}

int main()
{
	int **returnColumnSizes = NULL;
	int returnSizes;
	int n = 8;
	char ***solved = solveNQueens(n, &returnSizes, returnColumnSizes);
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
		{
            printf("{%c}", *solved[i][j]);
        }
        printf("\n");
	}
}