#pragma once
#include "CPlayer.h"
#include "lib/gb.h"

#include <d3dx9.h>						// d3d9.h もインクルードされる
#define DIRECTINPUT_VERSION  (0x0800)	//順番大事
#include <dinput.h>						//インプット系で使用

#pragma comment(lib,"dinput8.lib")		//ダイレクトインプット

namespace {
	static const u32 SCREEN_WIDTH  = 640; // 画面横幅
	static const u32 SCREEN_HEIGHT = 480; // 画面縦幅
}

CPlayer *GetPlayr();