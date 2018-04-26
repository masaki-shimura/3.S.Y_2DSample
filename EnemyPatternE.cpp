#include "BulletPatternA.h"
#include "EnemyPatternE.h"
#include "BulletPatternB.h"
#include "EnemyPatternF.h"
#include "Enemy.h"
#include "config.h"
#include <stdio.h>
#include <cmath>

CEnemyPatternE::CEnemyPatternE(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternB);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_YELLOW);
}

//下に下がる
CEnemyPatternE::~CEnemyPatternE()
{
}

void CEnemyPatternE::Update(CEnemy* pEnemy)
{
	//pEnemy->Position().x = sin(m_fRad += DEG_TO_RAD) * SCREEN_WIDTH * 0.25f + m_fStartX;

	//ライフゲージの確認
	int life = pEnemy->GetLife();
	int maxLife = pEnemy->GetMaxLife();
	float rate = (float)life / (float)maxLife;//0~1

											  // 0% or lower
	if (rate < 0.3f) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternF(pEnemy));
	}
}
