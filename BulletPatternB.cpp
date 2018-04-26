#include "BulletPatternB.h"
#include "Enemy.h"


CBulletPatternB::CBulletPatternB()
	:m_nFrameCounter(0)
{
}


CBulletPatternB::~CBulletPatternB()
{
}

void CBulletPatternB::Update(CEnemy* pEnemy)
{
	if (m_nFrameCounter++ % 30 == 0) {
		pEnemy->Shot(90 - 15 * 4, 5.0f);
		pEnemy->Shot(90 - 15 * 3, 5.0f);
		pEnemy->Shot(90 - 15 * 2, 5.0f);
		pEnemy->Shot(90 - 15 * 1, 5.0f);
		pEnemy->Shot(90         , 5.0f);
		pEnemy->Shot(90 + 15 * 4, 5.0f);
		pEnemy->Shot(90 + 15 * 3, 5.0f);
		pEnemy->Shot(90 + 15 * 2, 5.0f);
		pEnemy->Shot(90 + 15 * 1, 5.0f);
	}
}
