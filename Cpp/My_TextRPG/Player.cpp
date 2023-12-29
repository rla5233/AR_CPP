#include "Player.h"
#include <iostream>

Player::Player()
{
	m_NewWeapon.SetName("Steel Sword");
	m_NewWeapon.SetAtt(5);
}

void Player::RandomSetAtt()
{
	Att = (rand() % Size_Att) + Min_Att + m_NewWeapon.GetAtt();
}
