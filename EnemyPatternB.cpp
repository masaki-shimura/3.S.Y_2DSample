#include "EnemyPatternB.h"
#include "Enemy.h"
#include "BulletPatternA.h"
#include "EnemyPatternC.h"
#include "BulletPatternD.h"
#include "BulletPatternE.h"
#include "BulletPatternC.h"

CEnemyPatternB::CEnemyPatternB(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternA);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_GREEN);
}

//ŽËŒ‚ŠJŽn
void CEnemyPatternB::Update(CEnemy* pEnemy)
{
	int life = pEnemy->GetLife();
	int maxLife = pEnemy->GetMaxLife();
	float rate = (float)life / (float)maxLife;

	// 80% or lower
	if( rate < 0.8f ) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternC(pEnemy));
	}

	static int check;
	if (PatternCheck() == 1 && check != PatternCheck())
	{
		check = 1;
		pEnemy->ChangeBulletPattern(new CBulletPatternD);
	}
	if (PatternCheck() == 2 && check != PatternCheck())
	{
		check = 2;
		pEnemy->ChangeBulletPattern(new CBulletPatternE);
	}
	if (PatternCheck() == 0 && check != PatternCheck())
	{
		check = 0;
		pEnemy->ChangeBulletPattern(new CBulletPatternA);
	}
	if (PatternCheck() == 3 && check != PatternCheck())
	{
		check = 3;
		pEnemy->ChangeBulletPattern(new CBulletPatternC);
	}
}
