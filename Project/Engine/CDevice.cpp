#include "pch.h"
#include "CDevice.h"

CDevice::CDevice()
	: m_hMainWnd(nullptr)
	, m_RenderResolution{ 0, 0 }
	, m_Device(nullptr)
	, m_Context(nullptr)
	, m_SwapChain(nullptr)
	, m_RenderTarget(nullptr)
	, m_RTV(nullptr)
	, m_DepthStencilTex(nullptr)
	, m_DSV(nullptr)
{
	
}

CDevice::~CDevice()
{
	// DirectX Library ���� �����ϴ� ���� �Լ��� ����ؾ���.
	m_Device->Release();
	m_Context->Release();
}

int CDevice::init(HWND _hWnd, POINT _Resolution)
{
	m_hMainWnd = _hWnd;
	m_RenderResolution = _Resolution;

	// ����� ���� �������� ���� �������� �����ϸ鼭 ����� ���� �޼��� �α׸� �����
	UINT iFlag = 0;
	// ������ �з�������� Debug Layer ����� �����, ����ũ�鿡���� Ȱ��ȭ����
//#ifdef _DEBUG
//	 iFlag = D3D11_CREATE_DEVICE_DEBUG;
//#endif

	 D3D_FEATURE_LEVEL level = D3D_FEATURE_LEVEL_11_0;

	 D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE
					 , nullptr, iFlag, nullptr, 0, D3D11_SDK_VERSION
					 , &m_Device, &level, &m_Context);

	return S_OK;
}