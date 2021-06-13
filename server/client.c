#include"Client.h"


//向服务器发送消息
DWORD WINAPI ThreadProcedure(LPVOID Parameter)
{
	SOCKET ServerSocket;
	char BufferData[260];
	ServerSocket = *(SOCKET*)Parameter;
	printf("You can speak now:\n");
	while (1)
	{
		memset(BufferData, 0, sizeof(BufferData));
		gets(BufferData);
		//scanf("%s", BufferData);
		// 向客户端发送数据
		send(ServerSocket, BufferData, strlen(BufferData), 0);
		if (!strncmp(BufferData, "Over", strlen("Over")))
		{
			// 关闭同客户端的连接
			closesocket(ServerSocket);
			exit(0);
		}
	}
	return 0;
}

int main()
{
	//初始化套接字类库 
	//WSAStartup函数用于初始化Ws2_32.dll动态链接库。在使用套接字函数之前，一定要初始化Ws2_32.dll动态链接库 
	WSADATA v1 = { 0 };
	if (WSAStartup(MAKEWORD(2, 2), &v1) != 0)
	{
		return;
	}

	// 创建套接字
	SOCKET CommunicateSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (CommunicateSocket == INVALID_SOCKET)
	{
		printf(" Failed socket() \n");
		return;
	}

	// 填写远程地址信息
	struct sockaddr_in ServerAddress;
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_port = htons(4567);
	//此处直接使用127.0.0.1即可 就是连接到本机
	ServerAddress.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //192.168.0.106

	if (connect(CommunicateSocket, (SOCKADDR*)&ServerAddress, sizeof(ServerAddress)) == SOCKET_ERROR)
	{
		printf(" Failed connect() \n");
		return;
	}
	if (CommunicateSocket == INVALID_SOCKET)
	{
		printf("Failed accept()");
	}
	printf("连接成功！！\r\n");

	HANDLE ThreadHandle = CreateThread(NULL,
		0,
		(LPTHREAD_START_ROUTINE)ThreadProcedure,
		&CommunicateSocket,
		0,
		NULL);
	if (ThreadHandle == NULL)
	{
		return 0;
	}


	//接受来自服务器的消息
	char BufferData[260];
	while (TRUE)
	{
		memset(BufferData, 0, sizeof(BufferData));
		recv(CommunicateSocket, BufferData, sizeof(BufferData), 0);
		if (!strncmp(BufferData, "Over", strlen("Over")))
		{
			CloseHandle(ThreadHandle);
			ThreadHandle = NULL;
			break;
		}
		printf("Server Said: %s\n", BufferData);

	}
	// 关闭套节字
	closesocket(CommunicateSocket);
	WSACleanup();//与WSAStartup配合使用
	return 0;
}