#pragma once
#include <afxwin.h>
class CFileDecrypt :
	public CEdit
{
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDropFiles(HDROP hDropInfo);
};

