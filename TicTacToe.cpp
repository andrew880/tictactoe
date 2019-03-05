#include <tictactoe.h>
#include <string>
#include <locale>

/**
 *
 */
class TicTacToe {
	static const int SIDE_LENGTH = 3;
	static const int NUM_OF_PLAYER = 2;


	/**
		* evaluate board
		*
		* @param bs board status
		* @return evaluated state of the board
		*/
	static enum::TicTacToeState evaluateBoard(std::string boardSize) {
		if (boardSize.empty() || boardSize.length() != SIDE_LENGTH * SIDE_LENGTH) {
			return TicTacToeState::InvalidInput;
		}
		std::locale loc;
		std::string boardState = std::tolower(boardSize, loc);

		int*  xoCounts = countXO(boardState);
		int* xoLines = countLines(boardState);
		return findWinner(xoCounts, xoLines);
	}


	static enum::TicTacToeState TicTacToe::findWinner(int *xoCounts, int *xoLines) {
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
	static int * TicTacToe::countXO(std::string boardState) {
		int count[10];
		for (int i = 0; i < boardState.length(); i++) {
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
	static int * TicTacToe::countLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		int * verLine = checkVertiLines(boardState);
		int * horiLine = checkHoriLines(boardState);
		int * crossLine = checkCrossLines(boardState);
		xoLines[0] += verLine[0] + horiLine[0] + crossLine[0];
		xoLines[1] += verLine[1] + horiLine[1] + crossLine[1];
		return xoLines;
	}

	/**
		* check vertical lines made by Xs and Os
		*
		* @param boardState state of the board
		* @return number of vertical lines made by Xs and Os
		*/
	static int * TicTacToe::checkVertiLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		for (int i = 0; i < SIDE_LENGTH; i++) {
			//check vertical wins
			boolean lineFormed = true;
			for (int j = 1; j < SIDE_LENGTH; j++) {
				if (boardState.charAt(i) != boardState.charAt(i + j * SIDE_LENGTH)) {
					lineFormed = false;
					break;
				}
			}

			if (lineFormed) {
				if (boardState.charAt(i) == 'x') {
					xoLines[0]++;
				}
				else if (boardState.charAt(i) == 'o') {
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
	static int * TicTacToe::checkHoriLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		for (int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i += SIDE_LENGTH) {
			//check horizontal wins
			boolean lineFormed = true;
			for (int j = 1; j < SIDE_LENGTH; j++) {
				if (boardState.charAt(i) != boardState.charAt(i + j)) {
					lineFormed = false;
					break;
				}
			}

			if (lineFormed) {
				if (boardState.charAt(i) == 'x') {
					xoLines[0]++;
				}
				else if (boardState.charAt(i) == 'o') {
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
	static int * TicTacToe::checkCrossLines(std::string boardState) {
		int * xoLines = new int[NUM_OF_PLAYER];
		bool left = false, right = false;
		for (int i = 1; i < SIDE_LENGTH; i++) {
			if (boardState.charAt(0) == boardState.charAt(i + i * SIDE_LENGTH)) {
				if (left) {
					if (boardState.charAt(0) == 'x') {
						xoLines[0]++;
					}
					else if (boardState.charAt(0) == 'o') {
						xoLines[1]++;
					}
				}
				left = true;
			}

			if (boardState.charAt(SIDE_LENGTH - 1) == boardState.charAt((i + 1) * SIDE_LENGTH - i - 1)) {
				if (right) {
					if (boardState.charAt(SIDE_LENGTH - 1) == 'x') {
						xoLines[0]++;
					}
					else if (boardState.charAt(SIDE_LENGTH - 1) == 'o') {
						xoLines[1]++;
					}
				}
				right = true;
			}
		}
		return xoLines;
	}

	public: static TicTacToeState CheckTicTacToeBoard(std::string board)
	{
		return TicTacToeState::InvalidInput;
	}

};