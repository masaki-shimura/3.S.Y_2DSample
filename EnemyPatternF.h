#pragma once

#include "EnemyPattern.h"

class CEnemyPatternF : public CEnemyPattern
{
public:
	explicit CEnemyPatternF(CEnemy* pEnemy);
	virtual ~CEnemyPatternF();
	virtual void Update(CEnemy* pEnemy) override;

private: // �f�t�H���g�R���X�g���N�^�̕���
	CEnemyPatternF() {};
	float m_fStartX;
	float m_fRad;
};

