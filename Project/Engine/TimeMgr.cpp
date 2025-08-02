#include "pch.h"
#include "TimeMgr.h"


TimeMgr::TimeMgr()
	: m_Frequency{}
	, m_CurCount{}
	, m_PrevCount{}
	, m_FrameCount(0)
	, m_String{}
	, m_DeltaTime(0.f)
	, m_AccTime(0.f)
{
	// �ʴ� ī���� Ƚ��
	QueryPerformanceFrequency(&m_Frequency);

	// ���� ī����
	QueryPerformanceCounter(&m_PrevCount);
}

TimeMgr::~TimeMgr()
{
}

void TimeMgr::Tick()
{
	++m_FrameCount;

	// WindowOS �� ���μ����� ����� �������� 1�ʿ� 1000�� ī����
	// ���� ī���ð� ��������
	// GetTickCount()
	
	// ������ ���� �������� 1�ʿ� 10000000 �� ī����
	// ���� ī���� �� ��������
	QueryPerformanceCounter(&m_CurCount);
	
	m_DeltaTime = (float)(m_CurCount.QuadPart - m_PrevCount.QuadPart) / (float)m_Frequency.QuadPart;
			
	// DT �� 1/60 �� �̻��̸� ������ 1/60 ���� �������ش�.
	// DT ���� Ŀ���� �̻����� �߻��ϴ� ���� ����(ex �� ���)
	if (m_DeltaTime > 1.f / 60.f)
		m_DeltaTime = 1.f / 60.f;

	m_PrevCount = m_CurCount;

	m_AccTime += m_DeltaTime;

	// 1�ʿ� �ѹ��� ���� ����
	if (m_AccTime >= 1.f)
	{	
		swprintf_s(m_String, 256, L"FrameCount : %d, DeltaTime : %f", m_FrameCount, m_DeltaTime);
		m_FrameCount = 0;
		m_AccTime = 0.f;
	}
}

void TimeMgr::Render(HDC _dc)
{
	TextOut(_dc, 10, 10, m_String, wcslen(m_String));
}