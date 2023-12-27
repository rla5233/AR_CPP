#pragma once
#include "B.h"

// #include에서는 순환 참조를 주의해야 한다.

class A
{
public:
	B* Ptr;

public:
	A();

};