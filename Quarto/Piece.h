#pragma once
#include <iostream>

class Piece {
public:
	enum class Body : uint8_t {
		None,
		Full,
		Hollow
	};

	enum class Color : uint8_t
	{
		None,
		Dark,
		Light
		
	};

	enum class Height : uint8_t
	{
		None,
		Short,
		Tall
	};

	enum class Shape : uint8_t
	{
		None,
		Round,
		Square
	};

public:

	Piece();
	Piece(Body body, Color color, Height height, Shape shape);
	Piece(const Piece& otherPiece); //constructor de copiere
	Piece(Piece&& otherPiece); //constructor de mutare

	Body GetBody() const;;
	Color GetColor() const;
	Height GetHeight() const;
	Shape GetShape() const;
	Piece Intersection(const Piece& piece) const;
	bool HasAnyFeatureSet() const;

	friend std::ostream& operator << (std::ostream& os, const Piece& piece);

	Piece& operator = (const Piece& other);
	Piece& operator = (Piece&& other);

private:
	Body m_body : 1;
	Color m_color : 1;
	Height m_height : 1;
	Shape m_shape : 1;
};