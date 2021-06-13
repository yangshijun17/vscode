

#define  _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
//#include "struct_link.h"
#define SERVER_PORT 6789 //侦听端口

#pragma comment(lib,"ws2_32.lib")

int K1 = -1, K2 = -1, K3 = -1, K4 = -1, K5 = -1;
void MenuOperate(void);

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int ret, length;
	int recv_len = 0;
	SOCKET sListen, sServer; //侦听套接字，连接套接字
	struct sockaddr_in saServer, saClient; //地址信息
	char* ptr;//用于遍历信息的指针
	//WinSock初始化
	wVersionRequested = MAKEWORD(2, 2); //希望使用的WinSock DLL 的版本
	ret = WSAStartup(wVersionRequested, &wsaData);
	if (ret != 0)
	{
		printf("WSAStartup() failed!\n");
		return -1;
	}
	//创建Socket,使用TCP协议
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		WSACleanup();
		printf("socket() faild!\n");
		return -1;
	}
	//构建本地地址信息
	saServer.sin_family = AF_INET; //地址家族
	saServer.sin_port = htons(SERVER_PORT); //注意转化为网络字节序
	saServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //使用INADDR_ANY 指示任意地址

	//绑定
	ret = bind(sListen, (struct sockaddr*) & saServer, sizeof(saServer));
	if (ret == SOCKET_ERROR)
	{
		printf("bind() faild! code:%d\n", WSAGetLastError());
		closesocket(sListen); //关闭套接字
		WSACleanup();
		return -1;
	}

	//侦听连接请求
	ret = listen(sListen, 5);
	if (ret == SOCKET_ERROR)
	{
		printf("listen() faild! code:%d\n", WSAGetLastError());
		closesocket(sListen); //关闭套接字
		return -1;
	}

	printf("Waiting for client connecting!\n");
	printf("Tips: Ctrl+c to quit!\n");
	//阻塞等待接受客户端连接
	while (1)//循环监听客户端
	{
		length = sizeof(saClient);
		sServer = accept(sListen, (struct sockaddr*) & saClient, &length);
		if (sServer == INVALID_SOCKET)
		{
			printf("accept() faild! code:%d\n", WSAGetLastError());
			closesocket(sListen); //关闭套接字
			WSACleanup();
			return -1;
		}
		printf("accept is success!\n");
		printf("receive connect ip is %s ", inet_ntoa(saClient.sin_addr));
#if 0
		char receiveMessage[1024];
		ptr = (char*)&receiveMessage;
#else
		char* receiveMessage = (char*)calloc(2048, 0);
		ptr = receiveMessage;
#endif
		while (1)
		{
			//接收数据
			recv_len = recv(sServer, ptr, 1024, 0);
			switch (recv_len)
			{
			case 3:
				K1 = 0;
				printf("date is K1 ");
				break;
			case 4:
				K2 = 0;
				printf("date is K2 ");
				break;
			case 5:
				K3 = 0;
				printf("date is K3 ");
				break;
			default:
				K4 = 0;
				printf("date is too long\r\n ");
				break;
			}

			receiveMessage[recv_len] = 0;
			if (recv_len == SOCKET_ERROR)
			{
				printf("recv() failed!\n");
				return -1;
			}
			if (recv_len == 0) //客户端已经关闭连接
			{
				printf("Client has closed the connection\n");
				break;
			}
			char* sendData = "hello callback send data";
			send(sServer, sendData, strlen(sendData), 0);
			//            printf("recv is %s\n", ptr);
			memset(receiveMessage, 0, sizeof(receiveMessage));
		}
	}
}

