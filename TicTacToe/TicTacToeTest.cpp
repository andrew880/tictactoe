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
TEST_CASE("tictactoe method test") {
	SECTION("invalid input") {
		CHECK(TicTacToe::countXO("x..ooo.xx")[0] == 3);
		CHECK(TicTacToe::countXO("x..ooo.xx")[1] == 3);
	}
}
TEST_CASE("tictactoe test") {
	SECTION("invalid input") {
		CHECK(TicTacToeState::InvalidInput == TicTacToe::evaluateBoard("O...XX.X.."));
		CHECK(TicTacToeState::InvalidInput == TicTacToe::evaluateBoard("O...XX.X"));
	}
	
	SECTION("testRandomFilters") {
		CHECK(TicTacToeState::NoWinner == TicTacToe::evaluateBoard("O32OXtXu`"));
		CHECK(TicTacToeState::NoWinner == TicTacToe::evaluateBoard("OO2cXtXuX"));
		CHECK(TicTacToeState(NoWinner) == TicTacToe::evaluateBoard("232cftXu`"));
	}

	SECTION("noWinner") {
		CHECK(TicTacToeState(NoWinner) == TicTacToe::evaluateBoard("O...X.X.."));
		CHECK(TicTacToeState(NoWinner) == TicTacToe::evaluateBoard("O...X.X.O"));
	}

	SECTION("horizontal x win") {
		CHECK(TicTacToeState(Xwins) == TicTacToe::evaluateBoard("OX.XXXO.O"));
		CHECK(TicTacToeState(Xwins) == TicTacToe::evaluateBoard("XXXXO.OO."));
	}

	SECTION("vertical x win") {
		CHECK(TicTacToeState(Xwins) == TicTacToe::evaluateBoard("OX..XOXXO"));
		CHECK(TicTacToeState(Xwins) == TicTacToe::evaluateBoard("X.OX.OX.."));
	}

	SECTION("cross x win") {
		CHECK(TicTacToeState(Xwins) == TicTacToe::evaluateBoard("XO..XO..X"));
		CHECK(TicTacToeState(Xwins) == TicTacToe::evaluateBoard("..X.XOX.O"));
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

	SECTION("unreachable state due to invalid amount of X and O") {
		CHECK(UnreachableState == TicTacToe::evaluateBoard("O.X.X.X.."));
		CHECK(UnreachableState== TicTacToe::evaluateBoard("O.O.X...."));
		CHECK(UnreachableState == TicTacToe::evaluateBoard("O.OX.O.O."));
		CHECK(UnreachableState == TicTacToe::evaluateBoard("OOOXX..XX"));
		CHECK(UnreachableState == TicTacToe::evaluateBoard("OO.O..XXX"));
	}

	SECTION("unreachable state due to multiple winners") {
		CHECK(UnreachableState == TicTacToe::evaluateBoard("OOO.O.XXO"));
		CHECK(UnreachableState == TicTacToe::evaluateBoard("OOX.X.XXX"));
		CHECK(UnreachableState == TicTacToe::evaluateBoard("OOO...XXX"));
		CHECK(UnreachableState == TicTacToe::evaluateBoard("OOOOOOXXX"));
	}
}