#include <assert.h>
#include <sys/shm.h>

#include "Information.h"

#include "SharedMemory.h"

#include <cstring>
#include <iostream>

int main()
{
	SharedMemory shm;

	assert( shm.CreateShm(2017, sizeof(Information), SHM_R/* Read access for user */) != -1);

	shm.AttachShm();

	Information* pInfo = new Information;
	memset(pInfo, 'k', sizeof(Information));
	shm.CopyFromShm(pInfo, sizeof(Information));

	shm.DetachShm();

	//shm.RemoveShm();

	std::cout << sizeof(struct Information) << std::endl;
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
}

