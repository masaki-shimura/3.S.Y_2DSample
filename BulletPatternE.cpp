#include "BulletPatternE.h"
#include "Enemy.h"
#include <stdlib.h>

CBulletPatternE::CBulletPatternE()
	:m_nFrameCounter(0)
{
}


CBulletPatternE::~CBulletPatternE()
{
}

void CBulletPatternE::Update(CEnemy* pEnemy)
{
	if (m_nFrameCounter++ % 30 == 0) {
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
		pEnemy->Shot(90 - rand()%45, 5.0f);
	}
	if (m_nFrameCounter++ % 50 == 0) {
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f + rand() % 30);
		pEnemy->Shot(90 - rand() % 45, 5.0f+rand()%30);
	}
}
