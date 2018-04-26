#include "Enemy.h"
#include "BulletManager.h"
#include "BulletPattern.h"
#include "EnemyPatternA.h"
#include <cmath>
#include "lib\gb.h"

//�R���X�g���N�^
CEnemy::CEnemy(CBulletManager* pBulletManager, int maxLife)
	: m_pBulletManager( pBulletManager )
	, m_pEnemyPattern( new CEnemyPatternA(this) )
	, m_pBulletPattern( new CBulletPatternNull )
	, m_maxLife( maxLife )
	, m_life( maxLife )
{
	m_vPosition.x = 320;
	m_vPosition.y = -64;
	SetColor(CEnemy::ENEMY_COLOR_YELLOW);
}

//�f�X�g���N�^
CEnemy::~CEnemy()
{
	delete m_pBulletPattern;
	delete m_pEnemyPattern;
}

//�X�V����
void CEnemy::Update(void)
{
	m_pEnemyPattern->Update(this);
	m_pBulletPattern->Update(this);
}

//�`�揈��
void CEnemy::Draw(void)
{
	static const float R = 48;
	Vector2 p[3];

	for (int i = 0; i < 3; i++) {
		p[i].x = cos(DEG_TO_RAD * (90 + 120 * i)) * R + m_vPosition.x;
		p[i].y = sin(DEG_TO_RAD *( 90 + 120 * i)) * R + m_vPosition.y;
	}
	
	gb_drawColor(m_collar);
	gb_drawFillTriangle(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
}

//�e���ˏ���
void CEnemy::Shot(float deg, float speed)
{
	Vector2 ShotPos = m_vPosition;
	ShotPos.y += 48.0f;

	m_pBulletManager->Create(ShotPos, deg, speed, 16, 0xFFFF700F);
}

//�p�^�[���o���b�g
void CEnemy::ChangeBulletPattern(CBulletPattern* pBulletPattern)
{
	delete m_pBulletPattern;
	m_pBulletPattern = pBulletPattern;
}

//�G�l�~�[�p�^�[���ؑ֏���
void CEnemy::ChangeEnemyPattern(CEnemyPattern * pEnemyPattern)
{
	delete m_pEnemyPattern;
	m_pEnemyPattern = pEnemyPattern;
}
