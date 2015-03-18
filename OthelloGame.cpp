#include "OthelloGame.h"
#include <iostream>
using namespace std;

// Limit 15 lines
// Display state of the board
void PrintBoard(char board[][BOARD_SIZE]) {

	// Labeling of the columns on top
	cout << " -  0  1  2  3  4  5  6  7  " << endl;

	for (int row = 0; row < BOARD_SIZE; row++) {

		// Labeling of rows on left side
		cout << " " << row << " ";

		for (int col = 0; col < BOARD_SIZE; col++) {

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
	return (row < BOARD_SIZE && row >= 0) && (col < BOARD_SIZE && col >= 0);
}

// Limit 3 lines
// Check for validity
// Must be "in bounds" and be an empty space
// or be (-1, -1)/"pass" turn
bool IsValidMove(char board[][BOARD_SIZE], int row, int col) {
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
void ApplyMove(char board[][BOARD_SIZE], int row, int col,
	char currentPlayer) {
	board[row][col] = currentPlayer; // place piece

	// Delta's allow for 8-directional check
	for (int rowDelta = -1; rowDelta <= 1; rowDelta++) {
		for (int colDelta = -1; colDelta <= 1; colDelta++) {

			// If the check goes out-of-bounds, don't run
			if (InBounds(row + rowDelta, col + colDelta)) {

				// Check for enemy piece one space away
				// If the deltas = 0, don't need to run
				if (board[row + rowDelta][col + colDelta] == -currentPlayer 
					&& !(rowDelta == 0 && colDelta == 0)) {

					// Move over to the enemy piece
					// Resets value of i and j
					int i = row + rowDelta;
					int j = col + colDelta;

					// As long as there is an enemy piece
					// Keep moving in that direction
					do {
						i += rowDelta;
						j += colDelta;

						// When an ally piece is found,
						// Backtrack and flip pieces
						if (board[i][j] == currentPlayer) {
							while (board[i -= rowDelta][j -= colDelta]
								== -currentPlayer)
								board[i][j] = currentPlayer;
							break;
						}
					} while (board[i][j] == -currentPlayer); // 19 lines
				}
			}
		}
	}
}

// Limit 5 lines
// Return integer value of the board
int GetValue(char board[][BOARD_SIZE]) {
	int total = 0; // temp value

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			total += board[i][j];
		}
	}
	return total; // 5 lines
}
