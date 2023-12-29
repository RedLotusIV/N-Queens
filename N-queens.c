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
		if(isValid(y, i, board, n))
		{
			board[i][y] = 1;
			if (recursiveSolve(n, board, y + 1))
				return 1;
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
	recursiveSolve(n, returnColumnSizes, 0);
	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if (returnColumnSizes[i][j])
				*array[i][j] = 'Q';
			else if (returnColumnSizes[i][j] == 0)
				*array[i][j] = '.';
		}
	}
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
		{
            printf("{%d}", returnColumnSizes[i][j]);
        }
        printf("\n");
	}
	return (array);

	// for (y = 0; y < n ; y++)
	// {
	// 	flag = 0;
	// 	for (x = 0; x < n ; x++)
	// 	{
			
	// 		if (isValid(y, x, returnColumnSizes, n))
	// 		{
	// 			tmpY = y;
	// 			tmpX = x;
	// 			*array[y][x] = 'Q';
	// 			returnColumnSizes[y][x] = 1;
	// 			flag = 1;
	// 			break;
	// 		}
	// 	}
	// 	if (!flag)
	// 	{
	// 		returnColumnSizes[tmpY][tmpX] = 0;
	// 		removeQueen(array, tmpY, tmpX);
	// 		x++;
	// 		if (x == n)
	// 		{
	// 			y -= 2;
	// 			x = 0;
	// 		}
	// 	}
	// }
	// x = 0;
	// y = 0;
	// while (y < n)
	// {
    //     flag = 0;
    //     while (x < n)
	// 	{
    //         if (isValid(y, x, returnColumnSizes, n))
	// 		{
    //             tmpY = y;
    //             tmpX = x;
    //             *array[y][x] = 'Q';
    //             returnColumnSizes[y][x] = 1;
    //             flag = 1;
    //             break;
    //         }
    //         x++;
    //     }

    //     if (!flag)
	// 	{
    //         if (y == 0 && x == n)
	// 		{
    //             break;
    //         }
    //         returnColumnSizes[tmpY][tmpX] = 0;
    //         removeQueen(array, tmpY, tmpX);
	// 		printf("Y: %d, X: %d\n", tmpY, tmpX);
    //         y -= 2 ;
	// 		x = tmpX + 1;
    //     }
	// 	else
	// 	{
    //         x = 0;
    //     }
	// 	y++;
    // }
	// 	*returnSize = n;
	// 	return (array);
}

int main()
{
	int **returnColumnSizes = NULL;
	int returnSizes;
	int n = 8;
	char ***solved = solveNQueens(n, &returnSizes, returnColumnSizes);
    // for (int i = 0; i < n; i++)
	// {
    //     for (int j = 0; j < n; j++)
	// 	{
    //         printf("{%c}", *solved[i][j]);
    //     }
    //     printf("\n");
	// }
}