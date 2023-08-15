#include "UnusedPieces.h"
#include <array>
#include <algorithm>
#include <sstream>


UnusedPieces::UnusedPieces()
{
	GenerateUnusedPieces();
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
	m_unusedPieces.insert(std::make_pair(stringStream.str(), piece));
}


