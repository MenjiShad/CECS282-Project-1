#include "OthelloGame.h"
#include <iostream>
using namespace std;

// Limit 15 lines
// Display state of the board
void PrintBoard(char board[8][8]) {

	// Labeling of the columns on top
	cout << " -  0  1  2  3  4  5  6  7  " << endl;

	for (int row = 0; row < 8; row++) {

		// Labeling of rows on left side
		cout << " " << row << " ";

		for (int col = 0; col < 8; col++) {

			// Replace 0, 1, -1 w/ game markers
			if (board[row][col] == 0)
				cout << " . ";
			else if (board[row][col] == 1)
				cout << " B ";
			else
				cout << " W ";
		}
		cout << endl; // 11 lines
	}
}

// Limit 2 lines
// return "true" if move is "in bounds"
// Row and Col BOTH must be a value from 0-7
bool InBounds(int row, int col) {
	return (row <= 7 || row >= 0) && (col <= 7 || col >= 0);
}

// Limit 3 lines
// Check for validity
// Must be "in bounds" and be an empty space
// or be (-1, -1)/"pass" turn
bool IsValidMove(char board[][8], int row, int col) {
	return (InBounds(row, col) && board[row][col] == 0)
		|| (row == -1 && col == -1);
}


// Limit 2 lines
// Read user input
void GetMove(int *row, int *col) {
	char delimReader; // Reads/Consumes () and ,
	cin >> delimReader >> *row >> delimReader >> *col >> delimReader;
}

// Limit 20 lines
// Place piece on board and go through Othello's rules
void ApplyMove(char board[][8], int row, int col, char currentPlayer) {
	board[row][col] = currentPlayer; // place piece

	int i = row, j = col; // temp position holders

	// Delta's allow for 8-directional check
	for (int rowDelta = -1; rowDelta <= 1; rowDelta++) {
		for (int colDelta = -1; colDelta <= 1; colDelta++)
		{
			// Is the piece over an enemy piece?
			if (board[row + rowDelta][col + colDelta] == -currentPlayer)
			{
				// Move over to the enemy piece
                // Resets value of i and j
				i = row + rowDelta;
				j = col + colDelta;

				// Loop that will keep stepping in one direction
				for (;;)
				{
					i += rowDelta;
					j += colDelta;

					// Stop and do nothing upon finding an empty space
					if (board[i][j] == 0)
						break;

					// If ally piece is found, begin backtracking and flipping
					if (board[i][j] == currentPlayer)
					{
						while (board[i -= rowDelta][j -= colDelta]
							== -currentPlayer)
							board[i][j] = currentPlayer;
						break; // 17 lines
					}
				}
			}
		}
	}
}

// Limit 5 lines
// Return integer value of the board
int GetValue(char board[][8]) {
	int total = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			total += board[i][j];
		}
	}
	return total; // temp value
}
