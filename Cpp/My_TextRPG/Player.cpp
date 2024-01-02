#include "Player.h"
#include <iostream>

Player::Player()
{
	m_NewWeapon.SetName("Steel Sword");
	m_NewWeapon.SetAtt(5);
}

void Player::SetGold(int _Gold) { Gold = _Gold; }

void Player::Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _LevelUpExp)
{
	SetName("Player");
	SetMinAtt(_MinAtt);
	SetMaxAtt(_MaxAtt);
	SetMaxHp(_MaxHp);
	SetHp(_MaxHp);
	SetAtt(_MinAtt);
	SetLevelUpExp(_LevelUpExp);
}

void Player::StatusRenderStart()
{
	printf_s("\n·¹º§ %d (Exp : %d / %d)", Level, Exp, LevelUpExp);
}

void Player::StatusRenderBase()
{
	printf_s("\n");
	printf_s("°ø°Ý·Â %d ~ %d\n", Min_Att + m_NewWeapon.GetAtt(), Max_Att + m_NewWeapon.GetAtt());
	printf_s("Ã¼·Â %d / %d\n", Hp, Max_Hp);
	printf_s("¼ÒÁö±Ý %d Gold\n", Gold);
}

void Player::FightStart(FightUnit& _Player)
{

}

void Player::FightEnd(FightUnit& _Other)
{
	// °ñµå È¹µæ
	Gold += _Other.GetGold();
	printf_s("\n%d Gold ¸¦ È¹µæÇÏ¿´½À´Ï´Ù!", _Other.GetGold());

	// °æÇèÄ¡ È¹µæ
	Exp += _Other.GetExp();
	LevelUpCheck();
}

void Player::LevelUpCheck()
{
	while (GetExp() >= LevelUpExp)
	{
		++Level;
		Max_Hp = Level * 100;
		Min_Att += 5;
		Max_Att += 5;
		HpReset();
		Exp -= LevelUpExp;
		LevelUpExp = Level * 100;
	}
}

void Player::RandomSetAtt()
{
	Att = (rand() % (Max_Att - Min_Att)) + Min_Att + m_NewWeapon.GetAtt();
}
