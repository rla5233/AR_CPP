#pragma once
class StatusUnit
{
public:
	void SetName(const char* _Name);
	void StatusRender();

protected:
	char Name[100] = "None";
	int Hp = 100;
	int Att = 10;
	int Gold = 0;

	int Min_Att = 0;
	int Size_Att = 10;
};

