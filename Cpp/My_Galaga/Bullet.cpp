#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Update()
{
	if (GetPos().Y < 0)
	{
		// 모든건 관리되는 구조안에서 지워져야 하기 때문에
		// 엔진은 이러한 인터페이스를 우리에게 내려줘야 한다.
		// 내가 직접 지우는 것이 아니다!
		// delete this;
		Destroy();
		return;
	}

	AddPos(Up);
}