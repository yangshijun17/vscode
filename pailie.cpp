#pragma once
#include<stdio.h>
//#include<iostream>  这是C语言头文件
//Windows头文件必须在tlhelp32.h的前面，才能识别
#include<Windows.h>
#include <tlhelp32.h>

//using namespace std;  这是C++里面的东西



VOID EnumSystemProcess();
BOOL ProcessFirst(HANDLE SnapHandle, PPROCESSENTRY32 ProcessEntry);
BOOL ProcessNext(HANDLE SnapHandle, PPROCESSENTRY32 ProcessEntry);




int main()
{

	//设置地域化信息，设置中文，能够识别中文
	setlocale(LC_ALL, "chs");
	char* v1 = (char*)("进程枚举:");
	printf("%s\n", v1);
	//枚举进程的函数
	EnumSystemProcess();
	system("pause");
	system("cls");
	system("pause");
	return 0;
	
}


void EnumSystemProcess()
{
	//枚举系统进程  拍摄快照
	HANDLE SnapHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (SnapHandle == INVALID_HANDLE_VALUE)
	{
		return;
	}
	//PROCESSENTRY32 必须这样初始化
	PROCESSENTRY32 ProcessEntry = { sizeof(PROCESSENTRY32) };
	bool IsOk = ProcessFirst(SnapHandle, &ProcessEntry);

	//索引 为了统计当前进程总数
	int  Index = 0;
	for (; IsOk; IsOk = ProcessNext(SnapHandle, &ProcessEntry))
	{
		char BufferData[1024];
		//c:\\windows\\hello.exe  寻找'\\'最后出现的位置
		char* ProcessName = strrchr(ProcessEntry.szExeFile, '\\');
		if (ProcessName == NULL)
		{
			ProcessName = ProcessEntry.szExeFile;
		}
		else
		{
			ProcessName++;   //越过反斜杠
		}
		sprintf(BufferData, "%-50s%     (0x%08X)", ProcessName, ProcessEntry.th32ProcessID);

		printf("%s\n", BufferData);
		Index++;
	}
	printf("当前系统进程总共有 %d 个\n", Index);
}
BOOL ProcessFirst(HANDLE SnapHandle, PPROCESSENTRY32 ProcessEntry)
{

	BOOL IsOk = Process32First(SnapHandle, ProcessEntry);
	if (IsOk && (ProcessEntry->th32ProcessID == 0))
	{
		//如果PID = 0，那就byebye  继续去找下一个进程的ProcessEntry
		IsOk = ProcessNext(SnapHandle, ProcessEntry);
	}
	return IsOk;
}
BOOL ProcessNext(HANDLE SnapHandle, PPROCESSENTRY32 ProcessEntry)
{

	BOOL IsOk = Process32Next(SnapHandle, ProcessEntry);
	if (IsOk && (ProcessEntry->th32ProcessID == 0))
	{
		//递归调用
		IsOk = ProcessNext(SnapHandle, ProcessEntry);
	}
	return IsOk;
}