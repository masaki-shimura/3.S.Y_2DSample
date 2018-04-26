#include "EnemyPatternH.h"
#include "Enemy.h"
#include "BulletPatternE.h"
#include "EnemyPatternI.h"
#include "config.h"
#include <cmath>

CEnemyPatternH::CEnemyPatternH(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternE);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_RED);
}

//‚È‚É‚à‚µ‚È‚¢
void CEnemyPatternH::Update(CEnemy* pEnemy)
{
	float sx = (SCREEN_WIDTH / 2) - pEnemy->Position().x;

	if (abs(sx) < 1.0f) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternI(pEnemy));
		return;
	}

	sx = sx / abs(sx);

	if (pEnemy->Position().x != (SCREEN_WIDTH / 2)) {
		pEnemy->Position().x += (int)sx;
	}
}
