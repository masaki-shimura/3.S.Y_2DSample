#include "LifeBar.h"
#include "lib\gb.h"

void CLifeBar::Draw(int dx, int dy)
{
	Vector2 v[] = { (float)dx, (float)dy, (float)dx + m_width, (float)dy, (float)dx + m_width, (float)dy + m_height, (float)dx, (float)dy + m_height };
	float f = (float)m_Life / m_MaxLife;

	if( f >= 0.8f ) {
		gb_drawColor(0xFF00FF00);
	}
	else if( f >= 0.3f ) {
		gb_drawColor(0xFFFFFF00);
	}
	else {
		gb_drawColor(0xFFFF0000);
	}

	gb_drawFillRect((float)dx, (float)dy, (int)(m_width * f), (int)m_height);

	gb_drawColor(0xFFFFFFFF);
	gb_drawPolygon(4, v);
}
