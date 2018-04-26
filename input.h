//=============================================================================
//
// 入力処理 [input.h]
// Author : AKIRA TANAKA
//
//=============================================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "config.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	NUM_KEY_MAX		(256)	// キー最大数

//*********************************************************
// 入力クラス
//*********************************************************
class CInput
{
public:
	CInput();
	virtual ~CInput();

	virtual HRESULT Init(HINSTANCE hInst, HWND hWnd);
	virtual void Uninit(void);
	virtual void Update(void) = 0;		// ---> 純粋仮想関数化

	//static LPDIRECTINPUTDEVICE8 GetDevice() { return m_pDIDevice; }
	static LPDIRECTINPUT8 GetInputDevice() { return m_pDInput; }

protected:
	static LPDIRECTINPUT8 m_pDInput;	// DirectInputオブジェクト
	LPDIRECTINPUTDEVICE8 m_pDIDevice;	// Deviceオブジェクト(入力に必要)
};

//*********************************************************
// キーボード入力クラス
//*********************************************************
class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();

	HRESULT Init(HINSTANCE hInst, HWND hWnd);
	void Uninit(void);
	void Update(void);

	BOOL GetKeyPress(int nKey);
	BOOL GetKeyTrigger(int nKey);
	BOOL GetKeyRelease(int nKey);
	BOOL GetKeyRepeat(int nKey);
	void FlushKeyTrigger(int nKey);

private:
	BYTE	m_aKeyState[NUM_KEY_MAX];			// キーボードの状態を受け取るワーク
	BYTE	m_aKeyStateTrigger[NUM_KEY_MAX];	// トリガーワーク
	BYTE	m_aKeyStateRelease[NUM_KEY_MAX];	// リリースワーク
	BYTE	m_aKeyStateRepeat[NUM_KEY_MAX];		// リピートワーク
	int		m_aKeyStateRepeatCnt[NUM_KEY_MAX];	// リピートカウンタ
};

//*********************************************************
// マウスクラス
//*********************************************************
class CInputMouse :public CInput
{
public:
	CInputMouse() {};
	~CInputMouse() {};

	HRESULT Init(HINSTANCE hInst, HWND hWnd);
	void Uninit(void);
	void Update(void);

	static CInputMouse *Create(HINSTANCE hInst, HWND hWnd);

	BOOL GetLeftPress(void);
	BOOL GetLeftTrigger(void);
	BOOL GetLeftRelease(void);

	BOOL GetRightPress(void);
	BOOL GetRightTrigger(void);
	BOOL GetRightRelease(void);

	BOOL GetCenterPress(void);
	BOOL GetCenterTrigger(void);
	BOOL GetCenterRelease(void);

	LONG GetAxisX(void);
	LONG GetAxisY(void);
	LONG GetWheel(void);

	POINT *GetPosWorld(void) { return &m_posMouseWorld; }

private:
	DIMOUSESTATE2 m_mouseState;         //マウスのワーク
	DIMOUSESTATE2 m_mouseStateTrigger;	//マウストリガーのワーク
	DIMOUSESTATE2 m_mouseStateRelease;	//マウスリリースのワーク
	POINT m_posMouseWorld;
};

class CCreateInput:public CInput
{
public:
	CCreateInput() {};
	~CCreateInput() {};

	enum INPUT_TYPE {
		INPUT_TYPE_KEYBOARD = 0,
		INPUT_TYPE_MOUTH,
		INPUT_TYPE_PS4
	};

	//インターフェースを取得する関数
	static CInput* GetInputInterface(INPUT_TYPE type);
};
#endif