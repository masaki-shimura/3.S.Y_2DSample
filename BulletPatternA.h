#pragma once

#include "BulletPattern.h"

class CBulletManager;

class CBulletPatternA : public CBulletPattern
{
public:
	CBulletPatternA();
	virtual ~CBulletPatternA();
	virtual void Update(CEnemy* pEnemy) override;

private:
	int m_nFrameCounter;
};
