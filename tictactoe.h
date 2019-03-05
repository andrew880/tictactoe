#pragma once

#include <string>

enum TicTacToeState { UnreachableState, Xwins, Owins, NoWinner, InvalidInput };

TicTacToeState CheckTicTacToeBoard(std::string board);