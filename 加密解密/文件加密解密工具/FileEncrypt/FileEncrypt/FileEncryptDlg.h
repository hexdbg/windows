﻿
// FileEncryptDlg.h: 头文件
//

#pragma once
#include "CFileDecrypt.h"
#include "CFileEncrypt.h"


// CFileEncryptDlg 对话框
class CFileEncryptDlg : public CDialogEx
{
// 构造
public:
	CFileEncryptDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEENCRYPT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditEncrypt();
	afx_msg void OnEnChangeEditDecrypt();
	afx_msg void OnBnClickedButtonEncrypt();
	afx_msg void OnBnClickedButtonDecrypt();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void DoEncrypt(CString filepath);
	afx_msg void DoDecrypt(CString filepath);
	CFileDecrypt m_editFileDecrypt;
	CFileEncrypt m_editFileEncrypt;
};
