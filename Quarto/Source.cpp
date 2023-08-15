// Quarto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Piece.h"

int main()
{
	Piece piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);
	std::cout << "Full, Dark, Short, Square piece: " << piece << std::endl;
}
