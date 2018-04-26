#include "EnemyPatternC.h"
#include "Enemy.h"
#include "BulletPatternB.h"
#include "lib\gb.h"
#include <cmath>
#include "config.h"
#include "EnemyPatternD.h"

CEnemyPatternC::CEnemyPatternC(CEnemy* pEnemy)
	: m_fStartX(pEnemy->Position().x)
	, m_fRad(0.0f)
{
	//pEnemy->ChangeBulletPattern(new CBulletPatternA);
	pEnemy->ChangeBulletPattern(new CBulletPatternB);
	pEnemy->SetColor(CEnemy::ENEMY_COLOR_MAGENTA);
}


CEnemyPatternC::~CEnemyPatternC()
{

}

//‘Ì—Í50%I
void CEnemyPatternC::Update(CEnemy* pEnemy)
{
	pEnemy->Position().x = sin(m_fRad += DEG_TO_RAD) * SCREEN_WIDTH * 0.25f + m_fStartX;

	int life = pEnemy->GetLife();
	int maxLife = pEnemy->GetMaxLife();
	float rate = (float)life / (float)maxLife;

	// 50% or lower
	if( rate < 0.5f ) {
		pEnemy->ChangeEnemyPattern(new CEnemyPatternD(pEnemy));
	} 
}
