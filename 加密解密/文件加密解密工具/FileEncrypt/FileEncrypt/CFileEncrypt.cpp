#include "pch.h"
#include "CFileEncrypt.h"
BEGIN_MESSAGE_MAP(CFileEncrypt, CEdit)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


void CFileEncrypt::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT uFileCount = 0;
	UINT i = 0;
	TCHAR filepath[MAX_PATH] = { '\0' };
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	uFileCount = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	uFileCount > 1 ? 1 : uFileCount;
	for (i = 0; i < uFileCount; i++) {
		DragQueryFile(hDropInfo, i, filepath, MAX_PATH);
		SetWindowText(filepath);
	}
	DragFinish(hDropInfo);
	CEdit::OnDropFiles(hDropInfo);
}
