// Windows�w�b�_�̃C���N���[�h
#include <windows.h>

// GB�w�b�_�̃C���N���[�h
#include "lib/gb.h"
#include "config.h"
#include <list>
#include "Enemy.h"
#include "BulletManager.h"
#include "BulletPatternA.h"
#include "LifeBar.h"
#include "CPlayer.h"

// �萔
#define FRAME_RATE    (60)  // 1�b�Ԃɉ����ʂ�`�������邩

CBulletManager bullets;
CEnemy enemy(&bullets, 1000);
CLifeBar lifeBar(enemy.MaxLife(), 600.f, 32.f); 
CPlayer *g_player;
// Windows�v���O������main�֐�
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // GB�̏�����
	if( !gb_init(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_MODE, 1, "GBS...test", "GameBaseSystem...") ) {
		gb_errorMessage("GB�̏������Ɏ��s���܂���");
	}

	// �����ɃQ�[���̏�����
	gb_alphaBlendEnable(true);
	g_player = CPlayer::Create();

    // �Q�[�����[�v
    while( gb_processMessage() ){

        // �A�v���P�[�V�������A�N�e�B�u�łȂ��ꍇ�����|�[�Y
        if( !gb_getActive() ) {
            continue;
        }

        // ���Ԓ���
        if( !gb_wait(FRAME_RATE) ) {
            continue;
        }        


		// �����ɃQ�[���̍X�V����
		gb_inputGet();

		if( gb_inputCheckKey('X') ) {
			enemy.Damage(1);
		}

		enemy.Update();
		bullets.Update();
		lifeBar.Life() = enemy.Life();
		g_player->Update();

		// �����ɃQ�[���̕`�揈��

		// �`��̊J�n
		gb_drawBegin();

		// ��ʂ̏�����
		gb_clear(COLOR_ARGB(255, 0, 0, 0));

		g_player->Draw();
		enemy.Draw();
		bullets.Draw();
		lifeBar.Draw(20, 440);


		// �`��̏I��
		gb_drawEnd();
	}

	// �����ɃQ�[���̏I������


    // GB�̏I������
    gb_end();

	return 0;
}

CPlayer *GetPlayr()
{
	return g_player;
}