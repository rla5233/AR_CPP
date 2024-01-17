﻿#include <iostream>
#include <My_ConsoleEngine/EngineCore.h>

#include "Head.h"
#include "BodyManager.h"

int main()
{
	EngineCore Engine;
	Engine.Init({ 10, 10 });

	Head* NewHead = Engine.CreateObject<Head>();
	NewHead->SetPos({ Engine.m_Screen.GetScreenX() / 2, Engine.m_Screen.GetScreenY() / 2 });


	Engine.Start();
}