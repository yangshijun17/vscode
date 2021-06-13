#pragma once
#include<WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>//必须在<WinSock2.h>的下面包含，否则编译不通过
#pragma comment(lib,"WS2_32.lib")//要包含WinSock2.h必须要包这个库
