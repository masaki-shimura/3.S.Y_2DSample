#include "BulletManager.h"
#include <algorithm>
#include "Bullet.h"
#include "lib\gb.h"

CBulletManager::CBulletManager()
{
}


CBulletManager::~CBulletManager()
{
	std::_For_each(m_Bullets.begin(), m_Bullets.end(), [](CBullet* p) { delete p; });
}

CBullet* CBulletManager::Create(const Vector2& pos, float deg, float speed, int size, u32 color)
{
	CBullet* pRet = new CBullet(pos, deg, speed, size, color);

	m_Bullets.push_back(pRet);

	return pRet;
}

void CBulletManager::Update(void)
{
	m_Bullets.erase(std::remove_if(m_Bullets.begin(), m_Bullets.end(), 
		[](CBullet* p) -> bool {
			p->Update();
			if( p->isDelete() ) {
				delete p;
				return true;
			}
			return false;
		}
	), 
	m_Bullets.end());
}

void CBulletManager::Draw(void)
{
	std::_For_each(m_Bullets.begin(), m_Bullets.end(), [](CBullet* p) { p->Draw(); });
}
