#include "BoardStateChecker.h"
#include <numeric>

BoardStateChecker::State BoardStateChecker::Check(const Board& board, const Board::Position& position)
{
	Board& b = const_cast<Board&>(board);
	const auto& [lineIndex, columnIndex] = position;
	auto reducer = [](const Piece& p1, const std::optional<Piece>& p2) {
		return p1.Intersection(p2.value());
	};

	{
		auto[first,last] =
	}


};
