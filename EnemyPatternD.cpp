#include "EnemyPatternD.h"
#include "BulletPatternA.h"
#include "Enemy.h"
#include "config.h"
#include <cmath>
#include "EnemyPatternE.h"


CEnemyPatternD::CEnemyPatternD(CEnemy* pEnemy)
{
	pEnemy->ChangeBulletPattern(new CBulletPatternA);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_WHITE);
}


CEnemyPatternD::~CEnemyPatternD()
{
}

//’†‰›‚És‚­
void CEnemyPatternD::Update(CEnemy* pEnemy)
{
	float sx = (SCREEN_WIDTH / 2) - pEnemy->Position().x;

	if( abs(sx) < 1.0f ) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternE(pEnemy));
		return;
	}

	sx = sx / abs(sx);

	if( pEnemy->Position().x != (SCREEN_WIDTH/2) ) {
		pEnemy->Position().x += (int)sx;
	}
}
