#pragma once

#include "EnemyPattern.h"

class CEnemyPatternE : public CEnemyPattern
{
public:
	explicit CEnemyPatternE(CEnemy* pEnemy);
	virtual ~CEnemyPatternE();
	virtual void Update(CEnemy* pEnemy) override;

private: // デフォルトコンストラクタの封印
	CEnemyPatternE() {};

	float m_fStartX;
	float m_fRad;
};

