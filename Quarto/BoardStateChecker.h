#pragma once
#include "Board.h"

class BoardStateChecker {
public:
	enum class State {
		Playing,
		Win,
		Draw
	};

public:
	static State Check(const Board& board, const Board::Position& position);
};
