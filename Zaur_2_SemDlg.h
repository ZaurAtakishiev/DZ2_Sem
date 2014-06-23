
// Zaur_2_SemDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CZaur_2_SemDlg
class CZaur_2_SemDlg : public CDialogEx
{
// Создание
public:
	CZaur_2_SemDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_ZAUR_2_SEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	CListCtrl lcStreet;
	CListCtrl lcHouse;
	void  UpdateStreetList ();
	void  UpdateHouseList ();
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAddStreet();
	afx_msg void OnBnClickedButtonDeleteStreet();
	afx_msg void OnBnClickedButtonOtmenaStreet();
	afx_msg void OnNMDblclkListStreet(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonSaveStreet();
	afx_msg void OnNMClickListStreet(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonAddHouse();
	afx_msg void OnBnClickedButtonDeleteHouse();
	afx_msg void OnBnClickedButtonPayHouse();
};
