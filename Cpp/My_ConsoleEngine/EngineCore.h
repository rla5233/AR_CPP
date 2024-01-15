#pragma once
#include <map>
#include <list>

#include "ConsoleScreen.h"
#include "ConsoleObject.h"

class EngineCore
{
	friend class ConsoleObject;

public:
	// 어차피 자신의 멤버변수는 자기 스스로 알아서 지키겠지
	ConsoleScreen m_Screen = ConsoleScreen();

	void Init(int2 _ScreenSize);
	void Start();

	// 오브젝트를 만들고 반환하는 템플릿 함수 (오버로딩)
	template<typename ObjectType, typename EnumType>
	ObjectType* CreateObject(EnumType _Order)
	{
		return CreateObject<ObjectType>(_Order, _Order);
	}

	// 오브젝트를 만들고 반환하는 템플릿 함수 (오버로딩) (업데이트와 렌더순서를 enum class 로 지정)
	template<typename ObjectType, typename UpdateEnumType, typename RenderEnumType>
	ObjectType* CreateObject(UpdateEnumType _UpdateOrder, RenderEnumType _RenderOrder)
	{
		return CreateObject<ObjectType>(static_cast<int>(_UpdateOrder), static_cast<int>(_RenderOrder));
	}

	template<typename ObjectType>
	ObjectType* CreateObject(int _UpdateOrder, int _RenderOrder)
	{
		ObjectType* NewObject = new ObjectType();

		// 코어세팅(충돌 확인을 위해 ConsoleObject 클래스에서 m_AllUpdateObject 확인하기 위해)
		NewObject->ConsoleObject::SetCore(this);
		m_AllUpdateObject[_UpdateOrder].push_back(NewObject);
		m_AllRenderObject[_RenderOrder].push_back(NewObject);
		return NewObject;
	}

	void EngineEnd()
	{
		m_EngineUpdate = false;
	}

	// UpdateGroup 리스트를 가져오는 기능
	// 함수 friend 이용하거나 값을 반환하는 함수를 사용해야함 -> 클라에서는 원본에 접근할 수 없게 하기 위해
	// 보통 엄청 무거운 함수가 된다.
	std::list<ConsoleObject*> GetUpdateGroup(int _Order)
	{
		return m_AllUpdateObject[_Order];
	}

private:
	std::map<int, std::list<ConsoleObject*>> m_AllUpdateObject;
	std::map<int, std::list<ConsoleObject*>> m_AllRenderObject;
	bool m_EngineUpdate = true;
};