#pragma once
#include <map>
#include <list>

#include "ConsoleScreen.h"
#include "ConsoleObject.h"

class EngineCore
{
	friend class ConsoleObject;

public:
	// ������ �ڽ��� ��������� �ڱ� ������ �˾Ƽ� ��Ű����
	ConsoleScreen m_Screen = ConsoleScreen();

	void Init(int2 _ScreenSize);
	void Start();

	// ������Ʈ�� ����� ��ȯ�ϴ� ���ø� �Լ� (�����ε�)
	template<typename ObjectType, typename EnumType>
	ObjectType* CreateObject(EnumType _Order)
	{
		return CreateObject<ObjectType>(_Order, _Order);
	}

	// ������Ʈ�� ����� ��ȯ�ϴ� ���ø� �Լ� (�����ε�) (������Ʈ�� ���������� enum class �� ����)
	template<typename ObjectType, typename UpdateEnumType, typename RenderEnumType>
	ObjectType* CreateObject(UpdateEnumType _UpdateOrder, RenderEnumType _RenderOrder)
	{
		return CreateObject<ObjectType>(static_cast<int>(_UpdateOrder), static_cast<int>(_RenderOrder));
	}

	template<typename ObjectType>
	ObjectType* CreateObject(int _UpdateOrder, int _RenderOrder)
	{
		ObjectType* NewObject = new ObjectType();

		// �ھ��(�浹 Ȯ���� ���� ConsoleObject Ŭ�������� m_AllUpdateObject Ȯ���ϱ� ����)
		NewObject->ConsoleObject::SetCore(this);
		m_AllUpdateObject[_UpdateOrder].push_back(NewObject);
		m_AllRenderObject[_RenderOrder].push_back(NewObject);
		return NewObject;
	}

	void EngineEnd()
	{
		m_EngineUpdate = false;
	}

	// UpdateGroup ����Ʈ�� �������� ���
	// �Լ� friend �̿��ϰų� ���� ��ȯ�ϴ� �Լ��� ����ؾ��� -> Ŭ�󿡼��� ������ ������ �� ���� �ϱ� ����
	// ���� ��û ���ſ� �Լ��� �ȴ�.
	std::list<ConsoleObject*> GetUpdateGroup(int _Order)
	{
		return m_AllUpdateObject[_Order];
	}

private:
	std::map<int, std::list<ConsoleObject*>> m_AllUpdateObject;
	std::map<int, std::list<ConsoleObject*>> m_AllRenderObject;
	bool m_EngineUpdate = true;
};