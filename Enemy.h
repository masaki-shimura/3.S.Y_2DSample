#pragma once

#include "lib\gb.h"

class CBulletManager;
class CBulletPattern;
class CEnemyPattern;

class CEnemy
{
public:
	enum ENEMY_COLOR {
		ENEMY_COLOR_RED,//8
		ENEMY_COLOR_BLUE,//1
		ENEMY_COLOR_GREEN,//2
		ENEMY_COLOR_YELLOW,//0
		ENEMY_COLOR_MAGENTA,//3
		ENEMY_COLOR_WHITE,	//4
		ENEMY_COLOR_GRAY,	//5
		ENEMY_COLOR_CYAN,	//6
		ENEMY_COLOR_DKGRAY	//7
	};

	//コンストラクタ・デストラクタ
	explicit CEnemy(CBulletManager* pBulletManager, int maxLife);
	virtual ~CEnemy();
	
	//基本関数
	void Update(void);
	void Draw(void);

	//要素メンバ
	void Shot(float deg, float speed);
	void Damage(int val) { m_life -= val; };
	void ChangeEnemyPattern(CEnemyPattern* pEnemyPattern);
	void ChangeBulletPattern(CBulletPattern* pBulletPattern);

	//Get・Set
	const int GetLife(void) const { return Life(); }
	const int GetMaxLife(void) const { return MaxLife(); }
	void SetLife(int life) { m_life = life; }
public: // プロパティ
	Vector2& Position(void) { return m_vPosition; }
	const int& Life(void) const { return m_life; }
	const int& MaxLife(void) const { return m_maxLife; }
	void SetColor(ENEMY_COLOR col) 
	{
		switch (col) {
		case ENEMY_COLOR::ENEMY_COLOR_BLUE:
			m_collar = 0xFF0000FF;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_GREEN:
			m_collar = 0xFF00FF00;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_RED:
			m_collar = 0xFFFF0000;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_YELLOW:
			m_collar = 0xFFFFFF00;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_MAGENTA:
			m_collar = 0xffff00ff;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_WHITE:
			m_collar = 0xffffffff;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_GRAY:
			m_collar = 0xff888888;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_CYAN:
			m_collar = 0xff00ffff;
			break;
		case ENEMY_COLOR::ENEMY_COLOR_DKGRAY:
			m_collar = 0xff000000;
			break;
		}
	};
private: // デフォルトコンストラクタの使用禁止
	CEnemy() {}

private:
	CBulletManager* m_pBulletManager;
	CEnemyPattern* m_pEnemyPattern;
	CBulletPattern* m_pBulletPattern;
	Vector2 m_vPosition;
	int m_life;
	int m_maxLife;
	u32 m_collar;
};

