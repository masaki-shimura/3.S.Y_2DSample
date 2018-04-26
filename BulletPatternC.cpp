#include "BulletPatternC.h"
#include "Enemy.h"


CBulletPatternC::CBulletPatternC()
	:m_nFrameCounter(0)
{

}

CBulletPatternC::~CBulletPatternC()
{
}

void CBulletPatternC::Update(CEnemy* pEnemy)
{
	if (m_nFrameCounter++ % 30 == 0) {
		for (int i = 0; i < 40; i++)
		{
			pEnemy->Shot(90 + 15 * i, 5.0f);
		}
	}
}
