#pragma once

#include "EnemyPattern.h"

class CEnemyPatternA : public CEnemyPattern
{
public:
	CEnemyPatternA(CEnemy* pEnemy);
	virtual ~CEnemyPatternA() {};
	virtual void Update(CEnemy* pEnemy) override;
};