#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Update()
{
	if (GetPos().Y < 0)
	{
		// ���� �����Ǵ� �����ȿ��� �������� �ϱ� ������
		// ������ �̷��� �������̽��� �츮���� ������� �Ѵ�.
		// ���� ���� ����� ���� �ƴϴ�!
		// delete this;
		Destroy();
		return;
	}

	AddPos(Up);
}