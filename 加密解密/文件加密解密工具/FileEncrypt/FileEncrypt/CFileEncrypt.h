#pragma once
#include <afxwin.h>
class CFileEncrypt :
	public CEdit
{
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDropFiles(HDROP hDropInfo);

	int n_test;
};

