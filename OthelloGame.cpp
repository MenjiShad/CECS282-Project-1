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
