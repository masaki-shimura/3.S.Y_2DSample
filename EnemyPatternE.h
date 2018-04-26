#pragma once

#include "EnemyPattern.h"

class CEnemyPatternE : public CEnemyPattern
{
public:
	explicit CEnemyPatternE(CEnemy* pEnemy);
	virtual ~CEnemyPatternE();
	virtual void Update(CEnemy* pEnemy) override;

private: // �f�t�H���g�R���X�g���N�^�̕���
	CEnemyPatternE() {};

	float m_fStartX;
	float m_fRad;
};

