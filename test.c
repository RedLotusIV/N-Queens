#include <stdio.h>
#include <stdlib.h>

int isValid(int posY, int posX, int **queens, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
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

int recursiveSolve(int n, int **board, int x, int y)
{
	if (x >= n)
		return 1;
	for (int i = y; i < n; i++)
	{
		if (isValid(i, x, board, n) && i == 0)
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
int	main()
{
	int n = 4;
	int **board = malloc(sizeof(int *) * n);
	for (int i = 0 ; i < n ; i++)
		board[i] = malloc(sizeof(int) * n);
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
			board[i][j] = 0;
	}
	for(int l = 0; l < n ; l++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (recursiveSolve(n, board, j, l))
			{
				for (int y = 0; y < n; y++)
				{
					for (int x = 0; x < n; x++)
					{
						printf("{%d}", board[y][x]);
					}
					printf("\n");
				}
				printf("\n\n");
			}
		}
	}
}