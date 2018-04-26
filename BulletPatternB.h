#pragma once

#include "BulletPattern.h"

class CBulletManager;

class CBulletPatternB : public CBulletPattern
{
public:
	CBulletPatternB();
	virtual ~CBulletPatternB();
	virtual void Update(CEnemy* pEnemy) override;

private:
	int m_nFrameCounter;
};
