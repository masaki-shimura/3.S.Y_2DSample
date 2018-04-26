#pragma once

#include "lib/gb.h"


class CBullet
{
public:
	CBullet(const Vector2& pos, float deg, float speed, int size, u32 color);
	virtual ~CBullet(void);
	void Update(void);
	void Draw(void);
	bool isDelete(void) { return m_bDelete; }

private:
	CBullet(void) {}

private:
	Vector2 m_vSpeed;
	Vector2 m_vPos;
	int m_size;
	u32 m_color;
	bool m_bDelete;
};

