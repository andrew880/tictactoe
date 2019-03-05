#include "pch.h"
#include "tictactoe.h"
#include <string>
#include <locale>
#include <iostream>

/**
 *
 */
class TicTacToe {
	static const int SIDE_LENGTH = 3;
	static const int NUM_OF_PLAYER = 2;
	/**
		* check vertical lines made by Xs and Os
		*
		* @param boardState state of the board
		* @return number of vertical lines made by Xs and Os
		*/
	static int * checkVertiLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		for (int i = 0; i < SIDE_LENGTH; i++) {
			//check vertical wins
			if (boardState[i] == boardState[i + 3] && boardState[i] == boardState[i + 6]) {
				if (boardState[i] == 'x') {
					xoLines[0] = xoLines[0] + 1;
				}
				else if (boardState[i] == 'o') {
					xoLines[1] = xoLines[1] + 1;
				}
			}
		}
		return xoLines;
	}

	/**
		* check horizontal lines made by Xs and Os
		*
		* @param boardState state of the board
		* @return number of horizontal lines made by Xs and Os
		*/
	static int * checkHoriLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		for (int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i += SIDE_LENGTH) {
			//check horizontal wins
			if (boardState[i] == boardState[i + 1] && boardState[i] == boardState[i + 2]) {
				if (boardState[i] == 'x') {
					xoLines[0] = xoLines[0] + 1;
				}
				else if (boardState[i] == 'o') {
					xoLines[1] = xoLines[1] + 1;
				}
			}
		}
		return xoLines;
	}

	/**
		* check cross lines made by Xs and Os
		*
		* @param boardState state of the board
		* @return numbers of cross lines made by Xs and Os
		*/
	static int * checkCrossLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		bool left = false, right = false;
		if (boardState[0] == 'o' && boardState[4] == 'o' && boardState[8] == 'o') {
			xoLines[1]+=1;
		}
		if (boardState[2] == 'o' && boardState[4] == 'o' && boardState[6] == 'o') {
			xoLines[1]+=1;
		}
		if (boardState[0] == 'x' && boardState[4] == 'x' && boardState[8] == 'x') {
			xoLines[0]+=1;
		}
		if (boardState[2] == 'x' && boardState[4] == 'x' && boardState[6] == 'x') {
			xoLines[0]+=1;
		}
		
		return xoLines;
	}

	static TicTacToeState findWinner(int xoCounts[2], int xoLines[2]) {
			int xCount = xoCounts[0], oCount = xoCounts[1];
			int xLines = xoLines[0], oLines = xoLines[1];
			if (oLines == 0 && xLines == 1 && xCount == oCount + 1) {
				return TicTacToeState::Xwins;
			}
			else if (oLines == 1 && xLines == 0 && xCount == oCount) {
				return TicTacToeState::Owins;
			}
			else if (oLines == 0 && xLines == 0 && (xCount == oCount || xCount == oCount + 1)) {
				return TicTacToeState::NoWinner;
			}
			else {
				return TicTacToeState::UnreachableState;
			}
		}
	/**
		* count number of Xs and Os
		*
		* @param boardState state of the board
		* @return number of Xs and Os
		*/
	static int * countXO(std::string boardState) {
		int* count = new int[2];
		for (unsigned int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i++) {
			if (boardState[i] == 'x') {
				count[0]+=1;
			}
			else if (boardState[i] == 'o') {
				count[1]+=1;
			}
		}
		return count;
	}

	/**
		* count lines made by Xs and Os
		*
		* @param boardState state of the board
		* @return total number of lines made by Xs and Os
		*/
	static int * countLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		int * verLine = checkVertiLines(boardState);
		int * horiLine = checkHoriLines(boardState);
		int * crossLine = checkCrossLines(boardState);
		xoLines[0] += verLine[0] +horiLine[0] + crossLine[0];
		xoLines[1] += verLine[1] +horiLine[1] + crossLine[1];
		return xoLines;
	}
		/**
		* evaluate board
		*
		* @param bs board status
		* @return evaluated state of the board
		*/
	public: static TicTacToeState evaluateBoard(std::string boardString) {
		if (boardString.size() != SIDE_LENGTH * SIDE_LENGTH) {
			return TicTacToeState::InvalidInput;
		}

		for (int i = 0; boardString[i] != '\0'; i++) {
			boardString= tolower(boardString[i]);
		}

		return findWinner(countXO(boardString), countLines(boardString));
	}
};