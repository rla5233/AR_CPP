#pragma once
class NameUnit
{
public:
	void SetName(const char* _Name);
	inline const char* GetName() { return Name; }

private:
	char Name[100] = "None";

};

