#include "Player.h"
#include <iostream>

Player::Player()
{
	m_NewWeapon.SetName("Steel Sword");
	m_NewWeapon.SetAtt(5);
}

void Player::SetGold(int _Gold) { Gold = _Gold; }

void Player::RandomSetAtt()
{
	Att = (rand() % (Max_Att - Min_Att)) + Min_Att + m_NewWeapon.GetAtt();
}
