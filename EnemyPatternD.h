#pragma once

#include "EnemyPattern.h"

class CEnemyPatternD : public CEnemyPattern
{
public:
	explicit CEnemyPatternD(CEnemy* pEnemy);
	virtual ~CEnemyPatternD();
	virtual void Update(CEnemy* pEnemy) override;

private: // �f�t�H���g�R���X�g���N�^�̕���
	CEnemyPatternD() {};
};

