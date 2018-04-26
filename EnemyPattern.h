#pragma once

class CEnemy;
#include "config.h"

class CEnemyPattern
{
public:
	virtual ~CEnemyPattern() {}
	virtual void Update(CEnemy* pEnemy) = 0;
	int PatternCheck()
	{
		if (GetPlayr()->GetPosition().y < 200)
		{
			return 3;
		}
		if (GetPlayr()->GetPosition().x < 200)
		{
			return 1;
		}
		if (GetPlayr()->GetPosition().x > 420)
		{
			return 2;
		}
		return 0;
	}
};

class CEnemyPatternNone : public CEnemyPattern
{
public:
	virtual ~CEnemyPatternNone() {}
	virtual void Update(CEnemy* pEnemy) override {}
};
