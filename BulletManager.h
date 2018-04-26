#pragma once

#include "lib\gb.h"
#include <list>

class CBullet;

class CBulletManager
{
public:
	CBulletManager();
	virtual ~CBulletManager();
	CBullet* Create(const Vector2& pos, float deg, float speed, int size, u32 color);
	void Update(void);
	void Draw(void);

private:
	std::list<CBullet*> m_Bullets;
};

