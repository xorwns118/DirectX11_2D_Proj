#include "pch.h"
#include "PathMgr.h"

#include "Engine.h"

PathMgr::PathMgr()
{

}

PathMgr::~PathMgr()
{

}

void PathMgr::Init()
{
	// ���� ���(���μ����� �ִ� ����) �˾Ƴ���
	// VisualStudio �� ���ؼ� �������� ����� ���, Project �Ӽ��� �ִ� ������ ���� 
	// CurrentDirectory �� �����ȴ�.
	wchar_t szBuffer[256] = {};
	GetCurrentDirectory(256, szBuffer);

	// ���� ����(�θ�����) ��θ� �˾Ƴ���.
	int Len = wcslen(szBuffer);

	for (int i = Len-1; 0 < i; --i)
	{
		if ('\\' == szBuffer[i])
		{
			szBuffer[i] = 0;
			break;
		}
	}

	// Content �� �ٿ��ش�.
	wcscat_s(szBuffer, 256, L"\\Content\\");
		
	//SetWindowText(Engine::GetInst()->GetMainWinow(), szBuffer);

	m_ContentPath = szBuffer;
}