#pragma once

// 데이터 영역 메모리 : 전역변수
// 프로세스 시작할 때 초기화
// 프로세스 종료 시 해제
// 프로세스 실행 도중 상시 유지되는 메모리

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
//	// 정적 멤버함수 : 객체가 없어도 호출 가능
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
	// 엔진 객체를 데이터 영역에 만들어놨기 때문에 프로그램 실행 도중 해제시킬 수 없음
	// 규모가 클 수록, 오래되었을수록 위의 동적할당 방식이 어울림 (큰 차이는 없음)
	static CEngine* GetInst()
	{
		static CEngine mgr;
		return &mgr;
	}

private:
	CEngine();
	CEngine(const CEngine& _origin) = delete;

};