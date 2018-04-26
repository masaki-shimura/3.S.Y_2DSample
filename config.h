#pragma once
#include "CPlayer.h"
#include "lib/gb.h"

#include <d3dx9.h>						// d3d9.h ���C���N���[�h�����
#define DIRECTINPUT_VERSION  (0x0800)	//���ԑ厖
#include <dinput.h>						//�C���v�b�g�n�Ŏg�p

#pragma comment(lib,"dinput8.lib")		//�_�C���N�g�C���v�b�g

namespace {
	static const u32 SCREEN_WIDTH  = 640; // ��ʉ���
	static const u32 SCREEN_HEIGHT = 480; // ��ʏc��
}

CPlayer *GetPlayr();