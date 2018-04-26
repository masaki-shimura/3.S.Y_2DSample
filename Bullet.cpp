#include "Bullet.h"
#include <cmath>
#include "config.h"

CBullet::CBullet(const Vector2& pos, float deg, float speed, int size, u32 color)
	: m_vPos(pos)
	, m_color(color)
	, m_size(size)
	, m_bDelete(false)
{
	m_vSpeed.x = cos(DEG_TO_RAD * deg) * speed;
	m_vSpeed.y = sin(DEG_TO_RAD * deg) * speed;
}


CBullet::~CBullet(void)
{
}

	
void CBullet::Update(void)
{
	m_vPos.x += m_vSpeed.x;
	m_vPos.y += m_vSpeed.y;

	if( m_vPos.x < -m_size )                    { m_bDelete = true; }
	else if( m_vPos.x > SCREEN_WIDTH + m_size ) { m_bDelete = true; }
	else if( m_vPos.y < -m_size )               { m_bDelete = true; }
	else if( m_vPos.y > SCREEN_HEIGHT + m_size ){ m_bDelete = true; }
}

void CBullet::Draw(void)
{
	gb_drawColor(m_color);
	gb_drawFastCircle(static_cast<int>(m_vPos.x), static_cast<int>(m_vPos.y), m_size);
}
