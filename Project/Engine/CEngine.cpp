#include "pch.h"
#include "CEngine.h"
#include "CDevice.h"

#include "CDevice.h"

// CEngine* CEngine::g_This = nullptr;

CEngine::CEngine()
	: m_hMainHwnd(nullptr)
	, m_Resolution{ 0, 0 }
{
}

int CEngine::init(HWND _hWnd, POINT _Resolution)
{
	m_hMainHwnd = _hWnd;
	m_Resolution = _Resolution;

	// ������ ũ�� ����
	RECT rt = { 0, 0, m_Resolution.x, m_Resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false); // �޴��ٰ� ���� ������ ũ�� ���
	SetWindowPos(m_hMainHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);

	// DirectX11
	if (FAILED(CDevice::GetInst()->init(m_hMainHwnd, m_Resolution)))
	{
		MessageBox(m_hMainHwnd, L"Device �ʱ�ȭ ����", L"���� �ʱ�ȭ ����", MB_OK);
		return E_FAIL;
	}


	return S_OK;
}