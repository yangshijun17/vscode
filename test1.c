#include<locale.h>
#include<tlhelp32.h>
#include<stdlib.h>
#include<stdio.h>
void EnumSystemProcess();
int main()
{
    setlocale(LC_ALL, "chs");
    char *v1 = (char *)"进程枚举:";
    printf("%s\n",v1);
    EnumSystemProcess();
    system("pause");
    system("cls");
    system("pause");
}
void EnumSystemProcess()
{
    //枚举系统进程  拍摄快照
	//HANDLE SnapHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//if (SnapHandle == INVALID_HANDLE_VALUE)
	//{
	//	return;
	//}
    	//PROCESSENTRY32 必须这样初始化
	PROCESSENTRY32 ProcessEntry = { sizeof(PROCESSENTRY32) };
	//bool IsOk = ProcessFirst(SnapHandle, &ProcessEntry);

}