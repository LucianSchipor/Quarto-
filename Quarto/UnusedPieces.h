#pragma once
#include "Piece.h"

#include <unordered_map>

class UnusedPieces {
public:
	UnusedPieces();
	Piece PickPiece(const std::string& name);

	friend std::ostream& operator <<(std::ostream& os, const UnusedPieces& unusedPieces);
private:
	void GenerateUnusedPieces();
	void InsertPiece(const Piece& piece);
	void EmplacePiece(Piece&& piece);

private:

	std::unordered_map<std::string, Piece> m_pool;
};