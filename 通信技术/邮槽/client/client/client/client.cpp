// client.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>

LPCWSTR  g_lpcstrSlotName = TEXT("\\\\.\\mailslot\\sample_mailslot");
LPCWSTR g_testMsg = TEXT("TestMessageformailslot");

int main()
{
	//打开邮槽
	HANDLE hFile = CreateFile(g_lpcstrSlotName,
		GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("CreateFile failed,err %d\n", GetLastError());
		return 0;
	}
	//向邮槽写数据
	unsigned int uNum = 10;
	BOOL bRet = 0;
	DWORD dwBytesWrite = 0;
	while (uNum) {
		Sleep(2000);
		uNum--;
		size_t ulen = 2*(wcslen(g_testMsg) + 1); //UNICODE宽字符，写时乘2
		bRet = WriteFile(hFile,
			g_testMsg,
			ulen,
			&dwBytesWrite,
			NULL);
		if (!bRet) {
			printf("WriteFile failed, err %d\n",GetLastError());
			return 0;
		}
		printf("WriteFile success\n");
	}

	//释放句柄
	CloseHandle(hFile);

	return 0;
}
