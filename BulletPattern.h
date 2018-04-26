#pragma once

class CEnemy;
class CBulletPattern
{
public:
	virtual ~CBulletPattern() {}
	virtual void Update(CEnemy* pEnemy) = 0;
};

class CBulletPatternNull : public CBulletPattern
{
	virtual void Update(CEnemy* pEnemy) override {}
};