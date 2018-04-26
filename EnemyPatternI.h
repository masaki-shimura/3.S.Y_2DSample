#pragma once

#ifndef _ENEMY_PATTERN_I_H_
#define _ENEMY_PATTERN_I_H_

#include "EnemyPattern.h"
class CEnemy;

class CEnemyPatternI : public CEnemyPattern
{
public:
	CEnemyPatternI(CEnemy* pEnemy);
	virtual ~CEnemyPatternI() {};
	virtual void Update(CEnemy* pEnemy) override;

private:
	CEnemyPatternI() {}
};

#endif // _ENEMY_PATTERN_I_H_
