#include "BulletPatternA.h"
#include "Enemy.h"


CBulletPatternA::CBulletPatternA()
	:m_nFrameCounter(0)
{
}


CBulletPatternA::~CBulletPatternA()
{
}

void CBulletPatternA::Update(CEnemy* pEnemy)
{
	if (m_nFrameCounter++ % 30 == 0) {
		pEnemy->Shot(90, 4.0f);
	}
}
