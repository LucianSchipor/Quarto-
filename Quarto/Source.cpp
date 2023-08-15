// Quarto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Piece.h"
#include "Board.h"
#include "UnusedPieces.h"

int main()
{
	Board board;
	UnusedPieces unusedPieces;

	std::cout << "Empty board:\n" << board << std::endl;

	Piece piece1(Piece::Body::Hollow, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);
	board[{0, 1}] = piece1;
	std::cout << "Add piece to board:\n" << board << std::endl;

	return 0;
}
