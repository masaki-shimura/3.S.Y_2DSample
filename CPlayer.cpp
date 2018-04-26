#include "CPlayer.h"
#include <cmath>
#include "lib\gb.h"
#include "input.h"

//コンストラクタ
CPlayer::CPlayer()
{
	m_position.x = 320;
	m_position.y = 300;
	m_move.x = 0;
	m_move.y = 0;
}

//デストラクタ
CPlayer::~CPlayer()
{
}

//初期化
void CPlayer::Init()
{
	
}

//終了処理
void CPlayer::Uninit()
{

}

//更新
void CPlayer::Update()
{
	if (gb_inputCheckKey('D')) {
		m_move.x = 1;
	}
	if (gb_inputCheckKey('A')) {
		m_move.x = -1;
	}
	if (gb_inputCheckKey('W')) {
		m_move.y = -1;
	}
	if (gb_inputCheckKey('S')) {
		m_move.y = 1;
	}

	m_move.x = 0.9f * m_move.x;
	m_move.y = 0.9f * m_move.y;

	//位置の更新
	m_position.x = m_move.x + m_position.x;
	m_position.y = m_move.y + m_position.y;
}

//描画
void CPlayer::Draw()
{
	static const float R = 24;
	Vector2 p[3];

	for (int i = 0; i < 3; i++) {
		p[i].x = cos(DEG_TO_RAD * (150 + 120 * i)) * R + m_position.x;
		p[i].y = sin(DEG_TO_RAD * (150 + 120 * i)) * R + m_position.y;
	}

	gb_drawColor(0xFFFF0000);
	gb_drawFillTriangle(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
}

//生成
CPlayer* CPlayer::Create()
{
	CPlayer* pCPlayer;
	pCPlayer = new CPlayer;
	pCPlayer->Init();

	return pCPlayer;
}