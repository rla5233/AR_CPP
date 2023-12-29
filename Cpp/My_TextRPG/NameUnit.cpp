#include "NameUnit.h"

void NameUnit::SetName(const char* _Name)
{
	int idx = 0;
	while (_Name[idx])
	{
		Name[idx] = _Name[idx];
		++idx;
	}
}