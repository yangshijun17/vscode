#include "Server.h"

//相当于一个发送消息模块
DWORD WINAPI ThreadProcedure(LPVOID Parameter)
{
	SOCKET ClientSocket;
	char BufferData[260];
	ClientSocket = *(SOCKET *)Parameter;
	printf("You can speak now:\n");
	while (1)
	{
		memset(BufferData, 0, sizeof(BufferData));
		gets(BufferData);
		//scanf("%s", BufferData);
		// 向客户端发送数据
		send(ClientSocket, BufferData, strlen(BufferData), 0);
		if (!strncmp(BufferData, "Over", strlen("Over")))
		{
			// 关闭同客户端的连接
			closesocket(ClientSocket);
			exit(0);
		}
	}
	return 0;
}
int main()
{
	//初始化套接字类库
	//WSAStartup函数用于初始化Ws2_32.dll动态链接库。
	//在使用套接字函数之前，一定要初始化Ws2_32.dll动态链接库
	WSADATA WsaData = {0};
	if (WSAStartup(MAKEWORD(2, 2), &WsaData) != 0)
	{
		return 0;
	}
	// 创建监听套接字
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET)
	{
		printf("Failed socket() \n");
		return 0;
	}
	// 填充sockaddr_in结构
	struct sockaddr_in ServerAddress;
	ServerAddress.sin_family = AF_INET;				 //Ipv4协议家族
	ServerAddress.sin_port = htons(4567);			 //端口号
	ServerAddress.sin_addr.S_un.S_addr = INADDR_ANY; //客户端是本地地址
	// 绑定套接字
	if (bind(ListenSocket, (LPSOCKADDR)&ServerAddress, sizeof(ServerAddress)) == SOCKET_ERROR)
	{
		printf("Failed bind() \n");
		return 0;
	}
	// 进入监听模式  监听队列  最大连接数设置为 2
	if (listen(ListenSocket, 2) == SOCKET_ERROR)
	{
		printf("Failed listen() \n");
		return 0;
	}
	//用于接受客户端连接的IP地址等信息
	struct sockaddr_in ClientAddress;
	int AddressLength = sizeof(ClientAddress); //计算这个长度在accept处使用
	SOCKET ClientSocket;
	printf("等待客户端连接：\n");
	// 接受一个新连接
	ClientSocket = accept(ListenSocket, (SOCKADDR *)&ClientAddress, &AddressLength);
	if (ClientSocket == INVALID_SOCKET)
	{
		printf("Failed accept()");
	}
	printf("接收到连接：%s \r\n", inet_ntoa(ClientAddress.sin_addr));
	HANDLE ThreadHandle = CreateThread(NULL,
									   0,
									   (LPTHREAD_START_ROUTINE)ThreadProcedure,
									   &ClientSocket,
									   0,
									   NULL);
	if (ThreadHandle == NULL)
	{
		return 0;
	}
	//用于接收数据
	char BufferData[260];
	while (TRUE)
	{
		memset(BufferData, 0, sizeof(BufferData));
		recv(ClientSocket, BufferData, sizeof(BufferData), 0);
		if (!strncmp(BufferData, "Over", strlen("Over")))
		{
			CloseHandle(ThreadHandle);
			ThreadHandle = NULL;
			break;
		}
		printf("Client Said: %s\n", BufferData);
	}
	// 关闭监听套节字
	closesocket(ListenSocket);
	WSACleanup();
	return 0;
}