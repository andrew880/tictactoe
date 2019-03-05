#include "TicTacToe.cpp"
#include "pch.h"
#include "tictactoe.h"
#include <string>
#include <sstream>
#include <iostream>
#include <assert.h>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "TicTacToe.cpp"

using namespace std;

/**
 * Created by Andrew
*/

TEST_CASE("tictactoe test") {
	SECTION("invalid input") {
		CHECK( InvalidInput == TicTacToe::evaluateBoard("Oc...XX.X..") );
		CHECK( InvalidInput == TicTacToe::evaluateBoard("O...XX.X."));
	}
	SECTION("testRandomFilters") {
		CHECK(NoWinner == TicTacToe::evaluateBoard("O32OXtXu`"));
		CHECK(NoWinner == TicTacToe::evaluateBoard("OO2cXtXuX"));
		CHECK(NoWinner == TicTacToe::evaluateBoard("232cftXu`"));
	}
	SECTION("noWinner") {
		CHECK(NoWinner == TicTacToe::evaluateBoard("O...X.X.."));
		CHECK(NoWinner == TicTacToe::evaluateBoard("O...X.X.O"));
	}
	SECTION("horizontal x win") {
		CHECK(Xwins == TicTacToe::evaluateBoard("OX.XXXO.O"));
		CHECK(Xwins == TicTacToe::evaluateBoard("XXXXO.OO."));
	}
	SECTION("vertical x win") {
		CHECK(Xwins == TicTacToe::evaluateBoard("OX..XOXXO"));
		CHECK(Xwins == TicTacToe::evaluateBoard("X.OX.OX.."));
	}
	SECTION("cross x win") {
		CHECK(Xwins == TicTacToe::evaluateBoard("XO..XO..X"));
		CHECK(Xwins == TicTacToe::evaluateBoard("..X.XOX.O"));
	}
	SECTION("horizontal o win") {
		CHECK(Owins == TicTacToe::evaluateBoard("OXX.XXOOO"));
		CHECK(Owins == TicTacToe::evaluateBoard("X..OOOXX."));
	}
	SECTION("vertical o win") {
		CHECK(Owins == TicTacToe::evaluateBoard("O..OXXOX."));
		CHECK(Owins == TicTacToe::evaluateBoard(".OX.OXXO."));
	}
	SECTION("cross o win") {
		CHECK(Owins == TicTacToe::evaluateBoard("O.XXOX..O"));
		CHECK(Owins == TicTacToe::evaluateBoard(".XO.OXO.X"));
	}
}
/*
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