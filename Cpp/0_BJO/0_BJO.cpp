#include <iostream>
#include <vector>
using namespace std;

class MiniFantasyWar
{
public:
	MiniFantasyWar() {}

	void SetCharacterCount() { cin >> m_CharacterCount; }
	int GetCharacterCount()	{ return m_CharacterCount; }

private:
	int m_CharacterCount = 0;
};

class Character
{
public:
	Character() {}
	
	void SetHp() { cin >> m_Hp; }
	void SetMp() { cin >> m_Mp; }
	void SetAtt() { cin >> m_Att; }
	void SetArm() { cin >> m_Arm; }
	void WearingEquipment()
	{
		int ChangeHp = 0, ChangeMp = 0, ChangeAtt = 0, ChangeArm = 0;
		cin >> ChangeHp >> ChangeMp >> ChangeAtt >> ChangeArm;

		m_Hp += ChangeHp;
		if (m_Hp < 1) { m_Hp = 1; }

		m_Mp += ChangeMp;
		if (m_Mp < 1) { m_Mp = 1; }

		m_Att += ChangeAtt;
		if (m_Att < 0) { m_Att = 0; }

		m_Arm += ChangeArm;
	}

	void SetCombatPower() 
	{
		m_CombatPower = m_Hp + (5 * m_Mp) + (2 * m_Att) + (2 * m_Arm);
	}

	int GetCombatPower() { return m_CombatPower; }

private:
	int m_Hp = 0;
	int m_Mp = 0;
	int m_Att = 0;
	int m_Arm = 0;

	int m_CombatPower = 0;
};

void Problem_12790();

// 12790
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Problem_12790();

	return 0;
}

void Problem_12790()
{
	MiniFantasyWar NewGame = MiniFantasyWar();
	NewGame.SetCharacterCount();
	vector<Character> CharacterList(NewGame.GetCharacterCount(), Character());

	for (int i = 0; i < CharacterList.size(); i++)
	{
		CharacterList[i].SetHp();
		CharacterList[i].SetMp();
		CharacterList[i].SetAtt();
		CharacterList[i].SetArm();
		CharacterList[i].WearingEquipment();
		CharacterList[i].SetCombatPower();
		cout << CharacterList[i].GetCombatPower() << "\n";
	}
}