// Windowsヘッダのインクルード
#include <windows.h>

// GBヘッダのインクルード
#include "lib/gb.h"
#include "config.h"
#include <list>
#include "Enemy.h"
#include "BulletManager.h"
#include "BulletPatternA.h"
#include "LifeBar.h"
#include "CPlayer.h"

// 定数
#define FRAME_RATE    (60)  // 1秒間に何回画面を描きかえるか

CBulletManager bullets;
CEnemy enemy(&bullets, 1000);
CLifeBar lifeBar(enemy.MaxLife(), 600.f, 32.f); 
CPlayer *g_player;
// Windowsプログラムのmain関数
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // GBの初期化
	if( !gb_init(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_MODE, 1, "GBS...test", "GameBaseSystem...") ) {
		gb_errorMessage("GBの初期化に失敗しました");
	}

	// ここにゲームの初期化
	gb_alphaBlendEnable(true);
	g_player = CPlayer::Create();

    // ゲームループ
    while( gb_processMessage() ){

        // アプリケーションがアクティブでない場合強制ポーズ
        if( !gb_getActive() ) {
            continue;
        }

        // 時間調整
        if( !gb_wait(FRAME_RATE) ) {
            continue;
        }        


		// ここにゲームの更新処理
		gb_inputGet();

		if( gb_inputCheckKey('X') ) {
			enemy.Damage(1);
		}

		enemy.Update();
		bullets.Update();
		lifeBar.Life() = enemy.Life();
		g_player->Update();

		// ここにゲームの描画処理

		// 描画の開始
		gb_drawBegin();

		// 画面の初期化
		gb_clear(COLOR_ARGB(255, 0, 0, 0));

		g_player->Draw();
		enemy.Draw();
		bullets.Draw();
		lifeBar.Draw(20, 440);


		// 描画の終了
		gb_drawEnd();
	}

	// ここにゲームの終了処理


    // GBの終了処理
    gb_end();

	return 0;
}

CPlayer *GetPlayr()
{
	return g_player;
}