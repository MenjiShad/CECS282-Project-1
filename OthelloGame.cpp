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
	board[row][col] = currentPlayer;

	/*
	// Fails to check if enemy pieces are surrounded by ally pieces
	for (int i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++) {
		if (board[i][col] == -currentPlayer) {
			board[i][col] = -board[i][col];
		}
		if (board[row][j] == -currentPlayer) {
			board[row][j] = -board[row][j];
		}
		if (board[i][j] == -currentPlayer) {
			board[i][j] = -board[i][j];
		}
		if (board[j][i] == -currentPlayer) {
			board[i][j] = -board[j][i];
		}
	}
	*/

	/*
	int i = row, j = col;
	// Fails when flipping more than 1 piece
	// Check down
	while (board[i + 1][col] == -currentPlayer) {
		i++;
		if (board[i + 1][col] == currentPlayer) {
			for (; i > row; i--) // Solution to flipping more than 1
				board[i][col] = currentPlayer;
		}
	}

	// Check right
	while (board[row][j + 1] == -currentPlayer) {
		j++;
		if (board[row][j + 1] == currentPlayer)
			board[row][j--] = currentPlayer;
	}

	// Check up
	while (board[i - 1][col] == -currentPlayer) {
		i--;
		if (board[i - 1][col] == currentPlayer)
			board[i++][col] = currentPlayer;
	}

	// Check left
	while (board[row][j - 1] == -currentPlayer) {
		j--;
		if (board[row][j - 1] == currentPlayer)
			board[row][j++] = currentPlayer;
	}

	i = row, j = col;
	// Check Diagonal Down-Right
	while (board[i + 1][j + 1] == -currentPlayer) {
		i++, j++;
		if (board[i + 1][j + 1] == currentPlayer) {
			board[i--][j--] = currentPlayer;
		}
	}
	*/

	/*
	while (board[row + 1 % 8][col] == -currentPlayer) {
	row++;
	if (board[row + 1 % 8][col] == currentPlayer) {
	while (board[row][col] != currentPlayer) {
	board[row][col] = currentPlayer;
	row--;
	}
	}
	}

	while (board[row][col + 1 % 8] == -currentPlayer) {
	col++;
	if (board[row][col + 1 % 8] == currentPlayer) {
	while (board[row][col] != currentPlayer) {
	board[row][col] = currentPlayer;
	col--; // 12 lines
	}
	}
	}
	*/

	/*
	for (int counter = 0; counter < 8; counter++) {
	if (board[counter][col] == currentPlayer && counter != row) {
	while (counter < row) {
	board[counter][col] = currentPlayer;
	counter++;
	}
	while (counter > row) {
	board[counter][col] = currentPlayer;
	counter--; // 9 lines
	}
	}
	if (board[row][counter] == currentPlayer && counter != col) {
	while (counter < col) {
	board[row][counter] = currentPlayer;
	counter++;
	}
	while (counter > col) {
	board[col][counter] = currentPlayer;
	counter--; // 16 lines
	}
	}
	}
	*/
}

// Limit 5 lines
// Return integer value of the board
int GetValue(char board[][8]) {
	return 0; // temp value
}
