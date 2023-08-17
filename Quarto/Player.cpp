#include "Player.h"

Player::Player(const std::string& name)
	:m_name(name)
{

}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os << player.m_name<< " ";
}
