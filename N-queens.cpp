#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
	bool isSafe(vector<string> &board, int row, int col)
	{
		if (board[row].find('Q') != string::npos)
			return (false);
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i][col] == 'Q')
				return (false);
		}
		int n = board.size();
		for (int i = 0; i < n; i++)
		{
			if (row + i < n && col + i < n && board[row + i][col + i] == 'Q')
				return (false);
			if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q')
				return (false);
			if (row + i < n && col - i >= 0 && board[row + i][col - i] == 'Q')
				return (false);
			if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q')
				return (false);
		}

		return (true);
	}
	void solve(int col, vector<string> &board, vector<vector<string>> &results)
	{
		if (col == board.size())
		{
			results.push_back(board);
			return ;
		}
		for (int i = 0; i < board.size(); i++)
		{
			if (isSafe(board, i, col))
			{
				board[i][col] = 'Q';
				solve(col + 1, board, results);
				board[i][col] = '.';
			}
		}
	}
    vector<vector<string>> solveNQueens(int n)
    {
		// create a board of size n x n
		// go through each place in a board
		// place a queen in the board
		// check if the queen is safe, if it is safe, place the queen
		// if the queen is not safe, backtrack and try another place
		// if a n number of queens are placed, add the board to the results
		// do it till all results are found, aka every possible combination of queens illegal and legal tested
        vector<vector<string>> results;
        vector <string> board (n, string(n, '.'));
		solve(0, board, results);
		return (results);
    }
};