
// Zaur_2_Sem.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CZaur_2_SemApp:
// � ���������� ������� ������ ��. Zaur_2_Sem.cpp
//

class CZaur_2_SemApp : public CWinApp
{
public:
	CZaur_2_SemApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CZaur_2_SemApp theApp;