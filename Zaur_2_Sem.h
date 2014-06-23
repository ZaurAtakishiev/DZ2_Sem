
// Zaur_2_Sem.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CZaur_2_SemApp:
// О реализации данного класса см. Zaur_2_Sem.cpp
//

class CZaur_2_SemApp : public CWinApp
{
public:
	CZaur_2_SemApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CZaur_2_SemApp theApp;