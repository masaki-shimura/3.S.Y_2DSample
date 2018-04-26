#pragma once

#include "lib\gb.h"

class CInput;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	void Init();
	void Uninit();
	void Update();
	void Draw();

	static CPlayer *Create(void);
	Vector2 GetPosition()
	{
		return m_position;
	};

private:
	CInput *m_CInput;
	Vector2 m_position;
	Vector2 m_move;
};

