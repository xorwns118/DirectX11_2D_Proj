#include "pch.h"
#include "KeyMgr.h"

#include "Engine.h"

int KeyData[KEY_END] =
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',

	'W',
	'S',
	'A',
	'D',

	'Z',
	'X',
	'C',
	'V',

	VK_RETURN,
	VK_MENU,
	VK_CONTROL,
	VK_SPACE,
	VK_LSHIFT,
	VK_ESCAPE,
	VK_END,

	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	VK_LBUTTON,
	VK_RBUTTON,
};


KeyMgr::KeyMgr()
{
	m_vecKeys.resize(KEY_END);
}

KeyMgr::~KeyMgr()
{
}

void KeyMgr::Tick()
{
	for (size_t i = 0; i < m_vecKeys.size(); ++i)
	{
		// ���� �����ִ��� üũ
		if (GetAsyncKeyState(KeyData[i]))
		{
			// ���� �����ӿ� ���Ⱦ���.
			if (m_vecKeys[i].PrevPressed)
			{
				m_vecKeys[i].State = PRESSED;
			}

			// ���� �����ӿ��� �ȴ����־���.
			else
			{
				m_vecKeys[i].State = TAP;
			}

			m_vecKeys[i].PrevPressed = true;
		}

		// ���� �������� �ʴ�.
		else
		{
			// ���� �����ӿ��� �����־���.
			if (m_vecKeys[i].PrevPressed)
			{
				m_vecKeys[i].State = RELEASED;
			}

			// ���� �����ӿ��� �ȴ����־���.
			else
			{
				m_vecKeys[i].State = NONE;
			}

			m_vecKeys[i].PrevPressed = false;
		}
	}

	// ���콺 ��ǥ ���
	POINT ptMouse = {};

	// Screen ��ǥ��	
	GetCursorPos(&ptMouse); 

	// Screen ��ǥ�� -> Client ���� ��ǥ��
	ScreenToClient(Engine::GetInst()->GetMainWnd(), &ptMouse); 

	m_PrevMouse = m_MousePos;

	m_MousePos = Vec2((float)ptMouse.x, (float)ptMouse.y);

	m_MouseDragDir = m_MousePos - m_PrevMouse;
}