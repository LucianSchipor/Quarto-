#include "Board.h"

const char kEmptyBoardCell[] = "____";
const std::optional<Piece>& Board::operator[](const Position& position) const {
	const auto& [line, column] = position;
	return m_pieces[line * kWidth + column];
}

std::optional<Piece>& Board::operator[](const Position& pos)
{
	const auto& [line, column] = pos;
	return m_pieces[line * kWidth + column];
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	Board::Position position;
	auto& [line, column] = position;
	for (line = 0; line < Board::kHeight; ++line)
	{
		for (column = 0; column < Board::kWidth; ++column) {
			if (board[position]) {
				os << *board[position];
				os << ' ';
			}
			else
			{
				os << kEmptyBoardCell;
				os << ' ';
			}
		}
		os << std::endl;

	}
	return os;

}


