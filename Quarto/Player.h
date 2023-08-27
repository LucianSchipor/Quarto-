#pragma once

#include "Board.h"
#include "UnusedPieces.h"


class Player {
public:
	Player(const std::string& name);
	Piece PickPiece(std::istream& in, UnusedPieces& unusedPieces) const;

	friend std::ostream& operator << (std::ostream& os, const Player& player);
	Board::Position PlacePiece(std::istream& in, Piece&& piece, Board& board) const;

private:
	std::string m_name;
};