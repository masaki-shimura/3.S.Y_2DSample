#pragma once

#ifndef _ENEMY_PATTERN_H_H_
#define _ENEMY_PATTERN_H_H_

#include "EnemyPattern.h"
class CEnemy;

class CEnemyPatternH : public CEnemyPattern
{
public:
	CEnemyPatternH(CEnemy* pEnemy);
	virtual ~CEnemyPatternH() {};
	virtual void Update(CEnemy* pEnemy) override;

private:
	CEnemyPatternH() {}
};

#endif // _ENEMY_PATTERN_H_H_
