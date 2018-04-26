#include "EnemyPatternA.h"
#include "EnemyPatternB.h"
#include "Enemy.h"
#include "config.h"

CEnemyPatternA::CEnemyPatternA(CEnemy* pEnemy)
{
	
}

//‰º‚É‰º‚ª‚é
void CEnemyPatternA::Update(CEnemy* pEnemy)
{
	pEnemy->Position().y += 0.5f;

	if( pEnemy->Position().y > SCREEN_HEIGHT * 0.10f ) {
		pEnemy->Position().y = SCREEN_HEIGHT * 0.10f;

		pEnemy->ChangeEnemyPattern(new CEnemyPatternB(pEnemy));
	}
}
