
// Zaur_2_SemDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Zaur_2_Sem.h"
#include "Zaur_2_SemDlg.h"
#include "afxdialogex.h"
#include "City.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

City My_City;

int Street_Selected = -1;
int House_Selected = -1;
bool First_Clicked_Del_Street = 0;
bool First_Clicked_Del_House = 0;
bool First_Clicked_Pay_House = 0;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CZaur_2_SemDlg



CZaur_2_SemDlg::CZaur_2_SemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CZaur_2_SemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZaur_2_SemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CZaur_2_SemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Add_Street, &CZaur_2_SemDlg::OnBnClickedButtonAddStreet)
	ON_BN_CLICKED(IDC_BUTTON_Delete_Street, &CZaur_2_SemDlg::OnBnClickedButtonDeleteStreet)
	ON_BN_CLICKED(IDC_BUTTON_Otmena_Street, &CZaur_2_SemDlg::OnBnClickedButtonOtmenaStreet)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_Street, &CZaur_2_SemDlg::OnNMDblclkListStreet)
	ON_BN_CLICKED(IDC_BUTTON_Save_Street, &CZaur_2_SemDlg::OnBnClickedButtonSaveStreet)
	ON_NOTIFY(NM_CLICK, IDC_LIST_Street, &CZaur_2_SemDlg::OnNMClickListStreet)
	ON_BN_CLICKED(IDC_BUTTON_Add_House, &CZaur_2_SemDlg::OnBnClickedButtonAddHouse)
	ON_BN_CLICKED(IDC_BUTTON_Delete_House, &CZaur_2_SemDlg::OnBnClickedButtonDeleteHouse)
	ON_BN_CLICKED(IDC_BUTTON_Pay_House, &CZaur_2_SemDlg::OnBnClickedButtonPayHouse)
END_MESSAGE_MAP()


// обработчики сообщений CZaur_2_SemDlg

BOOL CZaur_2_SemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	lcStreet.SubclassDlgItem	(IDC_LIST_Street, this);
	lcHouse.SubclassDlgItem (IDC_LIST_House, this);
	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	lcStreet.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );
	lcStreet.InsertColumn (0, _T("№"), LVCFMT_CENTER, 40);
	lcStreet.InsertColumn (1, _T("Название"), LVCFMT_LEFT, 300);

	lcHouse.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );
	lcHouse.InsertColumn (0, _T("№"), LVCFMT_CENTER, 30);
	lcHouse.InsertColumn (1, _T("Оплачен"), LVCFMT_LEFT, 150);
	lcHouse.InsertColumn (1, _T("Счет"), LVCFMT_LEFT, 70);
	lcHouse.InsertColumn (1, _T("Жители"), LVCFMT_LEFT, 150);
	lcHouse.InsertColumn (1, _T("Номер"), LVCFMT_LEFT, 150);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CZaur_2_SemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CZaur_2_SemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CZaur_2_SemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CZaur_2_SemDlg::UpdateStreetList ()
{
	int i, j;
	CString StrName1, StrKol_vo;
	int Kol_vo;
	CString s;
	list< Street* >::iterator it = My_City.List_Street.begin();
	Street* TMP_Street;
	lcStreet.DeleteAllItems();
	for (i = 0; i < My_City.List_Street.size(); i ++)
	{
		TMP_Street = *it;
		s.Format (_T("%i"), i + 1);
		j = lcStreet.InsertItem (i, s);
		lcStreet.SetItemText (j, 1, TMP_Street->Name);
		lcStreet.SetItemData (j, (DWORD) TMP_Street);
		it++;
	};
	if( My_City.List_Street.size() > 0 )
	{
		if( Street_Selected >= My_City.List_Street.size() )
		{
			Street_Selected = My_City.List_Street.size() - 1;
		}
		StrName1 = My_City.Get_Street( Street_Selected )->Name;
		Kol_vo = My_City.Get_Street( Street_Selected )->List_House.size();
		StrKol_vo.Format (_T("%i"), Kol_vo ); 
		GetDlgItem( IDC_Street_Name )->SetWindowTextW( StrName1  );
		GetDlgItem( IDC_Street_Kol_vo )->SetWindowTextW( StrKol_vo  );
		UpdateHouseList ();
	}
	else
	{
		lcHouse.DeleteAllItems();
	}
}

void CZaur_2_SemDlg::UpdateHouseList ()
{
	int i, j;
	CString FIO_Str, Number_Of_Inhabitants_Str, Oklad_Str, Paid_Str;
	CString s;
	Street* Street = My_City.Get_Street( Street_Selected );
	House* TMP_House;
	list< House* >::iterator it = Street->List_House.begin();	
	lcHouse.DeleteAllItems();
	for (i = 0; i < Street->List_House.size(); i ++)
	{
		TMP_House = *it;
		s.Format (_T("%i"), i + 1);
		j = lcHouse.InsertItem (i, s);
		lcHouse.SetItemText (j, 1, TMP_House->Number );
		Number_Of_Inhabitants_Str.Format( _T("%i"), TMP_House->Number_Of_Inhabitants  );
		lcHouse.SetItemText (j, 2, Number_Of_Inhabitants_Str );
		Oklad_Str.Format( _T("%i"), TMP_House->Account  );
		if( TMP_House->Paid )
		{
			Paid_Str = (_T("Да"));
		}
		else
		{
			Paid_Str = (_T("Нет"));
		}
		lcHouse.SetItemText (j, 3, Oklad_Str );
		lcHouse.SetItemText (j, 4, Paid_Str );
		it++;
	}
}

void CZaur_2_SemDlg::OnBnClickedButtonAddStreet()
{
	My_City.Add();
	GetDlgItem ( IDC_BUTTON_Delete_Street ) ->EnableWindow(TRUE);	
	UpdateStreetList ();
}

void CZaur_2_SemDlg::OnBnClickedButtonDeleteStreet()
{
	if( !First_Clicked_Del_Street )																		// Это первое нажатие
	{
		First_Clicked_Del_Street = TRUE;																	// Активируется подтверждение нажатия
		lcStreet.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );	// Появляются Check_Boxes
		GetDlgItem ( IDC_BUTTON_Otmena_Street )->ShowWindow( SW_SHOW );							// Появляется кнопка "ОТМЕНА"
		GetDlgItem ( IDC_BUTTON_Add_Street ) ->EnableWindow(FALSE);								// Добавить департамент теперь невозможно 
	}
	else
	{
		First_Clicked_Del_Street = FALSE;																	// Деактивируется подтверждение
		for( int i = lcStreet.GetItemCount () - 1; i >= 0; i-- )									// В цикле удаляются выбранные эллементы
		{
			if( (lcStreet.GetItemState (i, LVIS_STATEIMAGEMASK) & 0x2000) != 0 )
			{
				My_City.Delete_Street( i + 1 );
			}
		}
		lcStreet.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );						// Убираются Check_Boxes
		GetDlgItem ( IDC_BUTTON_Otmena_Street )->ShowWindow( SW_HIDE );							// Прячется кнопка "ОТМЕНА"
		GetDlgItem ( IDC_BUTTON_Add_Street ) ->EnableWindow(TRUE);									// Появляется кнопка "Добавить отдел"
		UpdateStreetList ();																			// Обновляется список департаментов
	}
	if( My_City.List_Street.size() == 0 )															// Если количество департаментов равно 0 убирается кнопка удаления и слияния
	{
		GetDlgItem ( IDC_BUTTON_Delete_Street ) ->EnableWindow(FALSE);
	}
}

void CZaur_2_SemDlg::OnBnClickedButtonOtmenaStreet()
{
	if( First_Clicked_Del_Street )																			// Если это было нажатие на кнопку "Удалить"
	{
		First_Clicked_Del_Street = FALSE;																	// Отмена нажатия
		GetDlgItem ( IDC_BUTTON_Add_Street ) ->EnableWindow(TRUE);									// Появляется кнопка "Добавить отдел"
		GetDlgItem ( IDC_BUTTON_Otmena_Street )->ShowWindow( SW_HIDE );							// Прячется кнопка "ОТМЕНА"
		lcStreet.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );						// Убираются Check_Boxes
	}
}



void CZaur_2_SemDlg::OnNMDblclkListStreet(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	if( My_City.List_Street.size() )
	{
		GetDlgItem ( IDC_BUTTON_Save_Street )->ShowWindow( SW_SHOW );										// Появляются кнопки отмена и сохранение
		GetDlgItem ( IDC_BUTTON_Cancel_Street )->ShowWindow( SW_SHOW );

		OnBnClickedButtonOtmenaStreet();															// виртуально нажимается кнопка "отмена" для удаления и слияния департаментов и рабочих
		//OnBnClickedButtonCancelWorker();
		GetDlgItem ( IDC_LIST_Street ) ->EnableWindow(FALSE);										// Все окна становятся неактивными
		GetDlgItem ( IDC_LIST_House ) ->EnableWindow(FALSE);	
		GetDlgItem ( IDC_BUTTON_Add_Street ) ->EnableWindow(FALSE);	
		GetDlgItem ( IDC_BUTTON_Delete_Street ) ->EnableWindow(FALSE);	
		GetDlgItem ( IDC_BUTTON_Add_House ) ->EnableWindow(FALSE);	
		GetDlgItem ( IDC_BUTTON_Delete_House ) ->EnableWindow(FALSE);	
		GetDlgItem ( IDC_BUTTON_Pay_House ) ->EnableWindow(FALSE);
		//GetDlgItem ( IDC_BUTTON_Delete_Worker ) ->EnableWindow(FALSE);
		((CEdit *) GetDlgItem( IDC_Street_Name ))->SetReadOnly(FALSE);
		((CEdit *) GetDlgItem( IDC_Street_Name ))->EnableWindow(TRUE);
	}
}


void CZaur_2_SemDlg::OnBnClickedButtonSaveStreet()
{
	CString IN_Name;
	list< Street* >::iterator it = My_City.List_Street.begin();
	Street* TMP_Street;
	GetDlgItem( IDC_Street_Name )->GetWindowTextW( IN_Name );
	int Size = My_City.List_Street.size();
	for( int i = 0; i < Size; i++ )
	{
		TMP_Street = *it;
		My_City.Get_Street( Street_Selected )->Name = IN_Name;
		it++;
	}

	GetDlgItem ( IDC_BUTTON_Save_Street )->ShowWindow( SW_HIDE );										// Убираются кнопки отмена и сохранение
	GetDlgItem ( IDC_BUTTON_Cancel_Street )->ShowWindow( SW_HIDE );
	GetDlgItem ( IDC_BUTTON_Save_House )->ShowWindow( SW_HIDE );										
	GetDlgItem ( IDC_BUTTON_Cancel_House )->ShowWindow( SW_HIDE );

	GetDlgItem ( IDC_LIST_Street ) ->EnableWindow(TRUE);									// Все окна становятся неактивными
	GetDlgItem ( IDC_LIST_House ) ->EnableWindow(TRUE);	
	GetDlgItem ( IDC_BUTTON_Add_Street ) ->EnableWindow(TRUE);	
	GetDlgItem ( IDC_BUTTON_Delete_Street ) ->EnableWindow(TRUE);	
	GetDlgItem ( IDC_BUTTON_Add_House ) ->EnableWindow(TRUE);	
	GetDlgItem ( IDC_BUTTON_Delete_House ) ->EnableWindow(TRUE);	
	GetDlgItem ( IDC_BUTTON_Pay_House ) ->EnableWindow(TRUE);
	//GetDlgItem ( IDC_BUTTON_Delete_Worker ) ->EnableWindow(TRUE);

	((CEdit *) GetDlgItem( IDC_House_Number ))->SetReadOnly(TRUE);							// Возможно только чтение поля про ФИО работника. Изменение возможно только при двойном щелчке на соответствующей строке списка
	((CEdit *) GetDlgItem( IDC_House_Kol_vo ))->SetReadOnly(TRUE);							// Возможно только чтение поля про должность работника. Изменение возможно только при двойном щелчке на соответствующей строке списка
	((CEdit *) GetDlgItem( IDC_House_Sum ))->SetReadOnly(TRUE);						// Возможно только чтение поля про оклад работника. Изменение возможно только при двойном щелчке на соответствующей строке списка
	((CEdit *) GetDlgItem( IDC_Street_Name ))->SetReadOnly(TRUE);	


	UpdateStreetList();

}


void CZaur_2_SemDlg::OnNMClickListStreet(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;
	//if ((pNMLV->uChanged & LVIF_STATE) != 0)														// клик на департаменте
	//	if (lcStreet.GetItemState (pNMLV->iItem, LVIS_SELECTED) != 0)
	//	{
			CString StrName, StrKol_vo;
			int Kol_vo;
			//StrName = DEPARTAMENTS.GetDepartament( pNMLV->iItem )->Name_Str;
			StrName = My_City.Get_Street( pNMLV->iItem )->Name;
			Kol_vo = My_City.Get_Street( pNMLV->iItem )->List_House.size();
			StrKol_vo.Format (_T("%i"), Kol_vo );	
			//((CEdit *) GetDlgItem( IDC_EDIT_Departament_Name ))->SetReadOnly(TRUE);						// Возможно только чтение поля про название департамента. Изменение возможно только при двойном щелчке на этой клавише
			GetDlgItem( IDC_Street_Name )->SetWindowTextW( StrName  );									// Поле начинает выводить название выбранного департамента
			//GetDlgItem( IDC_STATIC_Departament_Kol_vo_Chislo )->SetWindowTextW( StrKol_vo );			// Поле начинает выводить, сколько человек работает в данном департаменте
			//GetDlgItem( IDC_EDIT_Departament_Name )->EnableWindow(TRUE);								// Включаем поле, которое показывает название департамента
			//GetDlgItem( IDC_STATIC_Departament_Kol_vo_Chislo )->EnableWindow(TRUE);						// Включаем поле, которое показывает, сколько человек работает в данно департаменте
			GetDlgItem( IDC_BUTTON_Add_House )->EnableWindow(TRUE);										// Включаем кнопку добавления рабочего
			Street_Selected = pNMLV->iItem;													// Записываем в переменную Departament_Selected номер выбранного департамента
			UpdateHouseList ();																			// Обновляем список работников( т.к. при переключении между отделами список работников должен так же меняться )
			//OnBnClickedButtonCancelWorker();															// Сбрасываем все с работников( начатое удаление или оплата )
	//	}
	
}


void CZaur_2_SemDlg::OnBnClickedButtonAddHouse()
{
	My_City.Get_Street( Street_Selected )->Add( );													// Функция добавления
	UpdateHouseList ();																				// Обновляем список сотрудников
	GetDlgItem ( IDC_BUTTON_Delete_House ) ->EnableWindow(TRUE);										// Активируется кнопка удаления сотрудника
	GetDlgItem ( IDC_BUTTON_Pay_House ) ->EnableWindow(TRUE);		
}


void CZaur_2_SemDlg::OnBnClickedButtonDeleteHouse()
{
	if( !First_Clicked_Del_House )																		// Кнопка нажата в первый раз
	{
		First_Clicked_Del_House = TRUE;																	// Активируется подтверждение нажатия
		lcHouse.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );		// Появляются Check_Boxes
		GetDlgItem ( IDC_BUTTON_Otmena_House )->ShowWindow( SW_SHOW );									// Появляется кнопка "ОТМЕНА"
		GetDlgItem ( IDC_BUTTON_Add_House ) ->EnableWindow(FALSE);										// Добавить работника теперь невозможно 
	}
	else																								// Кнопка нажата не в первый раз
	{
		First_Clicked_Del_House = FALSE;																	// Деактивируется подтверждение
		for( int i = lcHouse.GetItemCount () - 1; i >= 0; i-- )										// В цикле удаляются выбранные эллементы
		{
			if( (lcHouse.GetItemState (i, LVIS_STATEIMAGEMASK) & 0x2000) != 0 )
			{
				My_City.Get_Street( Street_Selected )->Delete_House( i + 1 );
			}
		}
		lcHouse.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );							// Убираются Check_Boxes
		GetDlgItem ( IDC_BUTTON_Otmena_House )->ShowWindow( SW_HIDE );									// Прячется кнопка "ОТМЕНА"
		GetDlgItem ( IDC_BUTTON_Add_House ) ->EnableWindow(TRUE);										// Появляется кнопка "Нанять рабочего"
		UpdateHouseList ();																			// Обновляется список рабочих
	}
}


void CZaur_2_SemDlg::OnBnClickedButtonPayHouse()
{
	if( !First_Clicked_Pay_House )																		// Кнопка нажата в первый раз
	{
		First_Clicked_Pay_House = TRUE;																	// Активируется подтверждение нажатия
		lcHouse.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );		// Появляются Check_Boxes
		GetDlgItem ( IDC_BUTTON_Otmena_House )->ShowWindow( SW_SHOW );									// Появляется кнопка "ОТМЕНА"
		GetDlgItem ( IDC_BUTTON_Add_House ) ->EnableWindow(FALSE);										// Добавить работника теперь невозможно 
	}
	else																								// Кнопка нажата не в первый раз
	{
		First_Clicked_Pay_House = FALSE;																	// Деактивируется подтверждение
		for( int i = lcHouse.GetItemCount () - 1; i >= 0; i-- )										// В цикле изменяются выбранные эллементы
		{
			if( (lcHouse.GetItemState (i, LVIS_STATEIMAGEMASK) & 0x2000) != 0 )
			{
				My_City.Get_Street( Street_Selected )->Get_House( i )->Pay();
			}
		}
		lcHouse.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );							// Убираются Check_Boxes
		GetDlgItem ( IDC_BUTTON_Otmena_House )->ShowWindow( SW_HIDE );									// Прячется кнопка "ОТМЕНА"
		GetDlgItem ( IDC_BUTTON_Add_House ) ->EnableWindow(TRUE);										// Появляется кнопка "Нанять рабочего"
		UpdateHouseList ();																			// Обновляется список рабочих
	}
}
