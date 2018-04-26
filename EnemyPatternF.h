#pragma once

#include "EnemyPattern.h"

class CEnemyPatternF : public CEnemyPattern
{
public:
	explicit CEnemyPatternF(CEnemy* pEnemy);
	virtual ~CEnemyPatternF();
	virtual void Update(CEnemy* pEnemy) override;

private: // デフォルトコンストラクタの封印
	CEnemyPatternF() {};
	float m_fStartX;
	float m_fRad;
};

