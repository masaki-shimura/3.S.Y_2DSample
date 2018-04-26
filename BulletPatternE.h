#pragma once

#include "BulletPattern.h"

class CBulletManager;

class CBulletPatternE : public CBulletPattern
{
public:
	CBulletPatternE();
	virtual ~CBulletPatternE();
	virtual void Update(CEnemy* pEnemy) override;

private:
	int m_nFrameCounter;
};
