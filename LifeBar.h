#pragma once
class CLifeBar
{
public:
	CLifeBar(int maxLife, float length, float height)
		: m_MaxLife(maxLife), m_Life(maxLife), m_width(length), m_height(height) {}
	virtual ~CLifeBar(void) {};

	void Draw(int dx, int dy);

public:
	int& Life(void) { return m_Life; }

private:
	int m_MaxLife;
	int m_Life;
	float m_width;
	float m_height;
};

