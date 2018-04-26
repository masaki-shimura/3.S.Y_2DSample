#include "BulletPatternC.h"
#include "EnemyPatternF.h"
#include "Enemy.h"
#include "config.h"
#include "EnemyPatternG.h"
#include <cmath>

CEnemyPatternF::CEnemyPatternF(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternC);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_CYAN);
}

//下に下がる
CEnemyPatternF::~CEnemyPatternF()
{
}

void CEnemyPatternF::Update(CEnemy* pEnemy)
{
	//ライフゲージの確認
	int life = pEnemy->GetLife();
	int maxLife = pEnemy->GetMaxLife();
	float rate = (float)life / (float)maxLife;//0~1

	if (rate < 0.2f) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternG(pEnemy));
	}
}
