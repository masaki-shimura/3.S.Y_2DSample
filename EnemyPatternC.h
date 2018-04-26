#pragma once

#include "EnemyPattern.h"

class CEnemyPatternC : public CEnemyPattern
{
public:
	explicit CEnemyPatternC(CEnemy* pEnemy);
	virtual ~CEnemyPatternC();
	virtual void Update(CEnemy* pEnemy) override;

private: // デフォルトコンストラクタの封印
	CEnemyPatternC() {};

private:
	float m_fStartX;
	float m_fRad;
};

