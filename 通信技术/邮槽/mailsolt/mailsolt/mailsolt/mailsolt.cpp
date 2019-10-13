// mailsolt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>

#pragma warning (disable:4996)

void processMessage();

HANDLE  g_hSlot;
LPCWSTR  g_lpcstrSlotName = TEXT("\\\\.\\mailslot\\sample_mailslot");
int main()
{
	//创建邮槽
	g_hSlot = CreateMailslot(g_lpcstrSlotName,
		0,
		MAILSLOT_WAIT_FOREVER,
		NULL);
	if (g_hSlot == INVALID_HANDLE_VALUE) {
		printf("CreateMailslot failed, err:%d\n", GetLastError());
	}
	else {
		printf("CreateMailslot success\n");
	}

	//等待接收消息
	processMessage();

	return 0;
}

void processMessage()
{
	TCHAR achID[80] = {'\0'};
	while (TRUE) {
		//从邮槽读消息
		DWORD dwMaxMessageSize, dwNextSize, dwMessageCount, dwReadTimeout;
		dwMaxMessageSize = dwNextSize = dwMessageCount = dwReadTimeout = 0;
		BOOL bRet;
		bRet = GetMailslotInfo(g_hSlot,
			NULL, //无最大消息限制
			&dwNextSize, //下一条消息大小
			&dwMessageCount, //消息数量
			NULL); //无时限
		if (!bRet) {
			printf("GetMailslotInfo failed, err:%d\n", GetLastError());
			return;
		}
		//没有消息，过3s再读
		if (dwNextSize == MAILSLOT_NO_MESSAGE) {
			printf("There is no next message.\n");
			Sleep(3000);
			continue;
		}
		//循环读消息
		dwMaxMessageSize = dwMessageCount;
		while (dwMessageCount != 0) {
			//提示信息
			wsprintf(achID, TEXT("\nMessage #%d of %d\n"), dwMaxMessageSize - dwMessageCount + 1, dwMaxMessageSize);
			//读取消息
			TCHAR buffer[1024] = { '\0' };
			DWORD dwBytesRead = 0;
			BOOL bRet;
			bRet = ReadFile(g_hSlot,
				buffer,
				dwNextSize,
				&dwBytesRead,
				NULL);
			if (!bRet) {
				printf("ReadFile failed, err:%d\n", GetLastError());
				return;
			}
			//输出消息
			lstrcat(buffer, achID);
			printf("from client:%ls\n", buffer);
			//计算剩余的消息数，如果为0，,退出子循环
			bRet = GetMailslotInfo(g_hSlot,
				NULL,
				&dwNextSize,
				&dwMessageCount,
				NULL);
			if (!bRet) {
				printf("GetMailslotInfo failed,err:%d\n", GetLastError());
				return;
			}
		}
	}
}