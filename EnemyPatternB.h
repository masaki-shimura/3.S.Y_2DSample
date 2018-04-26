#pragma once

#ifndef _ENEMY_PATTERN_B_H_
#define _ENEMY_PATTERN_B_H_

#include "EnemyPattern.h"
class CEnemy;

class CEnemyPatternB : public CEnemyPattern
{
public:
	CEnemyPatternB(CEnemy* pEnemy);
	virtual ~CEnemyPatternB() {};
	virtual void Update(CEnemy* pEnemy) override;

private:
	CEnemyPatternB() {}
};

#endif // _ENEMY_PATTERN_B_H_
