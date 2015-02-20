#include "OthelloGame.h"
#include <iostream>
using namespace std;

// Limit 45 lines
int main(int argc, char* argv) {

	const int BOARD_SIZE = 8; // Othello is 8x8
	char board[BOARD_SIZE][BOARD_SIZE] = { 0 }; // initialize board w/ 0
	char currentPlayer = 1; // Black = 1, White = -1
	int inRow, inCol;
	bool gameOn = true; // Condition to keep game running

	// START_COORDINATE marks the first 4 spots of Othello
	const int START_COORDINATE_1 = 3, START_COORDINATE_2 = 4;
	// Initialize the first 4 markers of Othello
	board[START_COORDINATE_1][START_COORDINATE_1] = -1;
	board[START_COORDINATE_2][START_COORDINATE_2] = -1;
	board[START_COORDINATE_1][START_COORDINATE_2] = 1;
	board[START_COORDINATE_2][START_COORDINATE_1] = 1;

	do { // 10 lines
		PrintBoard(board);

		if (currentPlayer == 1)
			cout << "Black's turn." << endl;
		else
			cout << "White's turn." << endl;
		cout << "Enter your move (row, col): " << endl;
		GetMove(&inRow, &inCol);

		if (IsValidMove(board, inRow, inCol)) {
			ApplyMove(board, inRow, inCol, currentPlayer);
			currentPlayer = -currentPlayer;
		}
		else
			cout << "Invalid move. Try again" << endl;
	} while (gameOn); // 23 lines

}
