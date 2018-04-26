#pragma once

#include "BulletPattern.h"

class CBulletManager;

class CBulletPatternC : public CBulletPattern
{
public:
	CBulletPatternC();
	virtual ~CBulletPatternC();
	virtual void Update(CEnemy* pEnemy) override;

private:
	int m_nFrameCounter;
};
