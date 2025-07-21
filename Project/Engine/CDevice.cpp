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
	// DirectX Library 에서 제공하는 해제 함수를 사용해야함.
	m_Device->Release();
	m_Context->Release();
}

int CDevice::init(HWND _hWnd, POINT _Resolution)
{
	m_hMainWnd = _hWnd;
	m_RenderResolution = _Resolution;

	// 디버그 모드로 만들어놨을 때에 렌더링을 수행하면서 생기는 에러 메세지 로그를 출력함
	UINT iFlag = 0;
	// 윈도우 패러렐즈에서는 Debug Layer 사용이 어려움, 데스크톱에서만 활성화하자
//#ifdef _DEBUG
//	 iFlag = D3D11_CREATE_DEVICE_DEBUG;
//#endif

	 D3D_FEATURE_LEVEL level = D3D_FEATURE_LEVEL_11_0;

	 D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE
					 , nullptr, iFlag, nullptr, 0, D3D11_SDK_VERSION
					 , &m_Device, &level, &m_Context);

	return S_OK;
}