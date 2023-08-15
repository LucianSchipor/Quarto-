#include "UnusedPieces.h"
#include <array>
#include <algorithm>
#include <sstream>


UnusedPieces::UnusedPieces()
{
	GenerateUnusedPieces();
}

Piece UnusedPieces::PickPiece(const std::string& name)
{
	auto node = m_pool.extract(name);
	if (node) {
		return std::move(node.mapped());
	}
	else
	{
		throw "Piece not found";
	}
}

void UnusedPieces::GenerateUnusedPieces()
{
	const uint8_t kPermutationPoolSize = 8;
	std::array <uint8_t, kPermutationPoolSize> permutationPool = { 0, 0, 0, 0, 1, 1, 1, 1 };
	const uint8_t kMaxPermutations = 5;
	const uint8_t kPermutationSize = 4;

	for (uint8_t currentPermutation = 0; currentPermutation < kMaxPermutations; ++currentPermutation) {
		auto itPoolBegin = permutationPool.begin() + currentPermutation;
		auto itPoolEnd = permutationPool.begin() + currentPermutation + kPermutationSize;

		do {
			InsertPiece(Piece(
				static_cast<Piece::Body>(*itPoolBegin),
				static_cast<Piece::Color>(*(itPoolBegin + 1)),
				static_cast<Piece::Height>(*(itPoolBegin + 2)),
				static_cast<Piece::Shape>(*(itPoolBegin + 3))
			));
		} while (std::next_permutation(itPoolBegin, itPoolEnd));
	}
}

void UnusedPieces::InsertPiece(const Piece& piece) {
	std::stringstream stringStream;
	stringStream << piece;
	m_pool.insert(std::make_pair(stringStream.str(), piece));
}

void UnusedPieces::EmplacePiece(Piece&& piece)
{
	std::stringstream stringstream;
	stringstream << piece;
	m_pool.insert(std::make_pair(stringstream.str(), std::forward<Piece&&>(piece)));
}

std::ostream& operator<<(std::ostream& os, const UnusedPieces& unusedPieces)
{
	for (const auto& [pieceName, piece] : unusedPieces.m_pool)
		os << pieceName << " ";
	return os;
}
