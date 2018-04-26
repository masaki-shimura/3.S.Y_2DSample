#pragma once

#include "EnemyPattern.h"

class CEnemyPatternC : public CEnemyPattern
{
public:
	explicit CEnemyPatternC(CEnemy* pEnemy);
	virtual ~CEnemyPatternC();
	virtual void Update(CEnemy* pEnemy) override;

private: // �f�t�H���g�R���X�g���N�^�̕���
	CEnemyPatternC() {};

private:
	float m_fStartX;
	float m_fRad;
};

