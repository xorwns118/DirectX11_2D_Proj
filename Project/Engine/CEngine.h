#pragma once

// ������ ���� �޸� : ��������
// ���μ��� ������ �� �ʱ�ȭ
// ���μ��� ���� �� ����
// ���μ��� ���� ���� ��� �����Ǵ� �޸�

// Singleton Pattern
//class CEngine
//{
//private:
//	static CEngine* g_This;
//
//private:
//	HWND	m_hMainWnd; 
//
//public:
//	// ���� ����Լ� : ��ü�� ��� ȣ�� ����
//	static CEngine* GetInst()
//	{
//		if (g_This == nullptr)
//		{
//			g_This = new CEngine;
//		}
//
//		return g_This;
//	}
//
//	static void Destroy()
//	{
//		if (g_This != nullptr)
//		{
//			delete g_This;
//			g_This = nullptr;
//		}
//	}
//
//private:
//	CEngine();
//};


class CEngine
{
private:
	HWND		m_hMainHwnd;
	POINT		m_Resolution;

public:
	int init(HWND _hWnd, POINT _Resolution);

public:
	// ���� ��ü�� ������ ������ �������� ������ ���α׷� ���� ���� ������ų �� ����
	// �Ը� Ŭ ����, �����Ǿ������� ���� �����Ҵ� ����� ��︲ (ū ���̴� ����)
	static CEngine* GetInst()
	{
		static CEngine mgr;
		return &mgr;
	}

private:
	CEngine();
	CEngine(const CEngine& _origin) = delete;

};