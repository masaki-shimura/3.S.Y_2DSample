#pragma once

#include "BulletPattern.h"

class CBulletManager;

class CBulletPatternD : public CBulletPattern
{
public:
	CBulletPatternD();
	virtual ~CBulletPatternD();
	virtual void Update(CEnemy* pEnemy) override;

private:
	int m_nFrameCounter;
};
