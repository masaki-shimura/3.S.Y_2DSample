#include "EnemyPatternG.h"
#include "Enemy.h"
#include "BulletPatternD.h"
#include "EnemyPatternH.h"

CEnemyPatternG::CEnemyPatternG(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternD);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_DKGRAY);
}

//ŽËŒ‚ŠJŽn
void CEnemyPatternG::Update(CEnemy* pEnemy)
{
	int life = pEnemy->GetLife();
	int maxLife = pEnemy->GetMaxLife();
	float rate = (float)life / (float)maxLife;

	// 10% or lower
	if( rate < 1.0f ) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternH(pEnemy));
	}
}
