#include "pch.h"
#include "tictactoe.h"
#include <string>
#include <locale>

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
			bool lineFormed = true;
			for (int j = 1; j < SIDE_LENGTH; j++) {
				if (boardState.at(i) != boardState.at(i + j * SIDE_LENGTH)) {
					lineFormed = false;
					break;
				}
			}

			if (lineFormed) {
				if (boardState.at(i) == 'x') {
					xoLines[0]++;
				}
				else if (boardState.at(i) == 'o') {
					xoLines[1]++;
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
			bool lineFormed = true;
			for (int j = 1; j < SIDE_LENGTH; j++) {
				if (boardState.at(i) != boardState.at(i + j)) {
					lineFormed = false;
					break;
				}
			}

			if (lineFormed) {
				if (boardState.at(i) == 'x') {
					xoLines[0]++;
				}
				else if (boardState.at(i) == 'o') {
					xoLines[1]++;
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
		if (boardState[0] == 'o' && boardState[4] == 'o' && boardState[9] == 'o') {
			xoLines[1]++;
		}
		if (boardState[2] == 'o' && boardState[4] == 'o' && boardState[6] == 'o') {
			xoLines[1]++;
		}
		if (boardState[0] == 'x' && boardState[4] == 'x' && boardState[9] == 'x') {
			xoLines[0]++;
		}
		if (boardState[2] == 'x' && boardState[4] == 'x' && boardState[6] == 'x') {
			xoLines[0]++;
		}
		
		return xoLines;
	}

	static TicTacToeState findWinner(int *xoCounts, int *xoLines) {
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
		int count[10];
		for (unsigned int i = 0; i < boardState.size(); i++) {
			if (boardState.at(i) == 'x') {
				count[0]++;
			}
			else if (boardState.at(i) == 'o') {
				count[1]++;
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
		xoLines[0] += verLine[0] + horiLine[0] + crossLine[0];
		xoLines[1] += verLine[1] + horiLine[1] + crossLine[1];
		return xoLines;
	}
		/**
		* evaluate board
		*
		* @param bs board status
		* @return evaluated state of the board
		*/
	public: static TicTacToeState evaluateBoard(std::string boardString) {
		if (boardString.empty() || boardString.size() != SIDE_LENGTH * SIDE_LENGTH) {
			return TicTacToeState::InvalidInput;
		}
		
		//for (int i = 0; boardString[i] != '\0'; i++) {
			//boardString[i] = tolower(boardString[i]);
		//}

		int*  xoCounts = countXO(boardString);
		int* xoLines = countLines(boardString);
		return findWinner(xoCounts, xoLines);
	}
};