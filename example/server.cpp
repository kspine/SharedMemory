#include <unistd.h>

#include "Information.h"

#include "SharedMemory.h"

#include <cstring>
#include <iostream>

void func_one()
{
	struct Information Info;
	memset(&Info, 'J', sizeof(struct Information));
	strcpy(Info.c1, "2");
	strcpy(Info.c2, "4");
	strcpy(Info.c3, "8");
	strcpy(Info.c4, "16");
	strcpy(Info.c5, "32");
	strcpy(Info.c6, "64");
	strcpy(Info.c7, "128");
	strcpy(Info.c8, "256");
	strcpy(Info.c9, "512");
	strcpy(Info.c10, "1024");


	std::cout << sizeof(struct Information) << std::endl;
	std::cout << Info.c1 << std::endl;
	std::cout << Info.c2 << std::endl;
	std::cout << Info.c3 << std::endl;
	std::cout << Info.c4 << std::endl;
	std::cout << Info.c5 << std::endl;
	std::cout << Info.c6 << std::endl;
	std::cout << Info.c7 << std::endl;
	std::cout << Info.c8 << std::endl;
	std::cout << Info.c9 << std::endl;
	std::cout << Info.c10 << std::endl;


	SharedMemory shm;

	shm.CreateShm(2017, sizeof(Information), IPC_CREAT | 0777);

	shm.AttachShm();

	shm.CopyToShm(&Info, sizeof(Information));


	Information* pInfo = new Information;
	memset(pInfo, 'k', sizeof(Information));
	shm.CopyFromShm(pInfo, sizeof(Information));

	std::cout << pInfo->c1 << std::endl;
	std::cout << pInfo->c2 << std::endl;
	std::cout << pInfo->c3 << std::endl;
	std::cout << pInfo->c4 << std::endl;
	std::cout << pInfo->c5 << std::endl;
	std::cout << pInfo->c6 << std::endl;
	std::cout << pInfo->c7 << std::endl;
	std::cout << pInfo->c8 << std::endl;
	std::cout << pInfo->c9 << std::endl;
	std::cout << pInfo->c10 << std::endl;


	shm.DetachShm();

	shm.RemoveShm();
}

void func_two()
{
	struct Information Info;
	memset(&Info, 'J', sizeof(struct Information));
	strcpy(Info.c1, "2");
	strcpy(Info.c2, "4");
	strcpy(Info.c3, "8");
	strcpy(Info.c4, "16");
	strcpy(Info.c5, "32");
	strcpy(Info.c6, "64");
	strcpy(Info.c7, "128");
	strcpy(Info.c8, "256");
	strcpy(Info.c9, "512");
	strcpy(Info.c10, "1024");


	std::cout << sizeof(struct Information) << std::endl;
	std::cout << Info.c1 << std::endl;
	std::cout << Info.c2 << std::endl;
	std::cout << Info.c3 << std::endl;
	std::cout << Info.c4 << std::endl;
	std::cout << Info.c5 << std::endl;
	std::cout << Info.c6 << std::endl;
	std::cout << Info.c7 << std::endl;
	std::cout << Info.c8 << std::endl;
	std::cout << Info.c9 << std::endl;
	std::cout << Info.c10 << std::endl;


	SharedMemory shm;

	shm.CreateShm(2017, sizeof(Information), IPC_CREAT | 0644);

	shm.AttachShm();

	shm.CopyToShm(&Info, sizeof(Information));

	shm.DetachShm();

system("echo sleep 5 sec...");
sleep(5);

	shm.RemoveShm();
}


int main()
{
	//func_one();

	func_two();
}
