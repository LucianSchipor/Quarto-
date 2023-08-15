#pragma once
#include "Piece.h"

#include <unordered_map>

class UnusedPieces {
public:
	UnusedPieces();
private:
	void GenerateUnusedPieces();
	void InsertPiece(const Piece& piece);

private:
	std::unordered_map<std::string, Piece> m_unusedPieces;
};