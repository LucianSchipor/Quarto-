#pragma once
#include "Piece.h"

#include <array>
#include <optional>
#include <cstddef>

class Board {
public:
	using Position = std::pair <uint8_t, uint8_t>;

public:
	Board() = default;
	const std::optional<Piece>& operator[] (const Position& pos) const;
	std::optional<Piece>& operator[] (const Position& pos);

	friend std::ostream& operator <<(std::ostream& out, const Board& board);

private:
	static const std::size_t kWidth = 4;
	static const std::size_t kHeight = 4;
	static const std::size_t kSize = kWidth * kHeight;

	std::array<std::optional<Piece>, kSize> m_pieces;
};