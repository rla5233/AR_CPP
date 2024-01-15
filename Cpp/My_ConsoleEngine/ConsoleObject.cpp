#include "ConsoleObject.h"
#include "EngineCore.h"

ConsoleObject::ConsoleObject()
{

}

ConsoleObject::ConsoleObject(const int2& _StartPos, char _RenderChar)
	: m_Pos(_StartPos), m_RenderChar(_RenderChar)
{

}

ConsoleObject::~ConsoleObject()
{

}

ConsoleObject* ConsoleObject::Collision(int _UpdateOrder)
{
	std::list<ConsoleObject*>& Object_List = GetCore()->m_AllUpdateObject[_UpdateOrder];
	std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
	for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); ++Object_iter)
	{
		ConsoleObject* Object = *Object_iter;

		if (Object == nullptr)
		{
			MsgBoxAssert("Object Nullptr Error.");
		}

		if (Object != this)
		{
			if (Object->GetPos() == GetPos())
			{
				return Object;
			}
		}
	}

	return nullptr;
}
