#include "EnemyPatternI.h"
#include "Enemy.h"
#include "BulletPatternB.h"
#include "EnemyPatternA.h"
#include "config.h"

CEnemyPatternI::CEnemyPatternI(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternB);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_RED);
}

//“P‘ÞI
void CEnemyPatternI::Update(CEnemy* pEnemy)
{
	pEnemy->Position().y -= 0.5f;

	if (pEnemy->Position().y < SCREEN_HEIGHT * -0.10f) {
		pEnemy->SetLife(1000);
		pEnemy->Position().y = SCREEN_HEIGHT * -0.10f;
		pEnemy->ChangeEnemyPattern(new CEnemyPatternA(pEnemy));
	}
}
