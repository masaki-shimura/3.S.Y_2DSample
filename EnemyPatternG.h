#pragma once

#ifndef _ENEMY_PATTERN_G_H_
#define _ENEMY_PATTERN_G_H_

#include "EnemyPattern.h"
class CEnemy;

class CEnemyPatternG : public CEnemyPattern
{
public:
	CEnemyPatternG(CEnemy* pEnemy);
	virtual ~CEnemyPatternG() {};
	virtual void Update(CEnemy* pEnemy) override;

private:
	CEnemyPatternG() {}
};

#endif // _ENEMY_PATTERN_G_H_
