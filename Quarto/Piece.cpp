#include "Piece.h"

Piece::Piece(Body body, Color color, Height height, Shape shape) :
	m_body(body),
	m_color(color),
	m_height(height),
	m_shape(shape)
{
	static_assert(sizeof(*this) <= 1, "Clasa ar trebui sa fie de dimensiune 1 byte.");
}

Piece::Body Piece::GetBody() const
{
	return m_body;
}

Piece::Color Piece::GetColor() const
{
	return m_color;
}

Piece::Height Piece::GetHeight() const
{
	return m_height;
}

Piece::Shape Piece::GetShape() const
{
	return m_shape;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	return os <<
		static_cast<int>(piece.m_body) <<
		static_cast<int>(piece.m_color) <<
		static_cast<int>(piece.m_height) <<
		static_cast<int>(piece.m_shape);
}
