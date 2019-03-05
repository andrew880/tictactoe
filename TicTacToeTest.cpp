#include <TicTacToe.cpp> 
#include <tictactoe.h>
#include <string>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <cpptest-assert.h>

using namespace std;

void testInvalidInput() {
	assert(0 == 0);
	cout << TicTacToe::CheckTicTacToeBoard("O...XX.XX..");
	//cout << TicTacToe::evaluateBoard("O...XX.X..");
	//assert(TicTacToeState.InvalidInput == TicTacToe.evaluateBoard("O...XX.X.."));
	//assert(TicTacToeState.InvalidInput == TicTacToe.evaluateBoard("O...XX.."));
}
/**
 * Created by Andrew
 */
void CheckTicTacToeBoard() {
	testInvalidInput();
}
/*
TEST_CASE("explicit vector constructor test") {
	std::vector<SnakeBodySegment> sample_vector;
	LinkedList *new_list;

	SECTION("empty vector") {
		new_list = new LinkedList(sample_vector);
		REQUIRE(new_list->empty());
	}

	SECTION("basic vector") {
		for (int count = 0; count < 10; count++) {
			sample_vector.push_back(count);
		}
		SnakeBodySegment *segment0 = new SnakeBodySegment(0);
		new_list = new LinkedList(sample_vector);
		REQUIRE(new_list->size() == 10);
		REQUIRE(new_list->front() == *segment0);
	}
}
*/
/*
void testRandomFilters() throws Exception {
	//check random filters
	assertEquals(Evaluation.NoWinner, TicTacToe.evaluateBoard("O32OXtXu`"));
	assertEquals(Evaluation.NoWinner, TicTacToe.evaluateBoard("OO2cXtXuX"));
	assertEquals(Evaluation.NoWinner, TicTacToe.evaluateBoard("232cftXu`"));
}

	//check no winner
	assertEquals(Evaluation.NoWinner, TicTacToe.evaluateBoard("O...X.X.."));
	assertEquals(Evaluation.NoWinner, TicTacToe.evaluateBoard("O...X.X.O"));

	//check horizontal x win
	assertEquals(Evaluation.Xwins, TicTacToe.evaluateBoard("OX.XXXO.O"));
	assertEquals(Evaluation.Xwins, TicTacToe.evaluateBoard("XXXXO.OO."));

	//check vertical x win
	assertEquals(Evaluation.Xwins, TicTacToe.evaluateBoard("OX..XOXXO"));
	assertEquals(Evaluation.Xwins, TicTacToe.evaluateBoard("X.OX.OX.."));

	//check cross x win
	assertEquals(Evaluation.Xwins, TicTacToe.evaluateBoard("XO..XO..X"));
	assertEquals(Evaluation.Xwins, TicTacToe.evaluateBoard("..X.XOX.O"));

	//check horizontal o win
	assertEquals(Evaluation.Owins, TicTacToe.evaluateBoard("OXX.XXOOO"));
	assertEquals(Evaluation.Owins, TicTacToe.evaluateBoard("X..OOOXX."));

	//check vertical o win
	assertEquals(Evaluation.Owins, TicTacToe.evaluateBoard("O..OXXOX."));
	assertEquals(Evaluation.Owins, TicTacToe.evaluateBoard(".OX.OXXO."));

	//check cross o win
	assertEquals(Evaluation.Owins, TicTacToe.evaluateBoard("O.XXOX..O"));
	assertEquals(Evaluation.Owins, TicTacToe.evaluateBoard(".XO.OXO.X"));

	//check unreachable state due to invalid amount of X and O
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("O.X.X.X.."));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("O.O.X...."));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("O.OX.O.O."));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("OOOXX..XX"));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("OO.O..XXX"));

	//check unreachable state due to multiple winners
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("OOO.O.XXO"));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("OOX.X.XXX"));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("OOO...XXX"));
	assertEquals(Evaluation.UnreachableState, TicTacToe.evaluateBoard("OOOOOOXXX"));
}
*/