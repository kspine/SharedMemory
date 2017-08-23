#include "SharedMemory.h"

#include "Information.h"

#include <cstring>
#include <iostream>

int main()
{
	Information Info1;
	std::memset(&Info1, 0, sizeof(Information));

	SharedMemory shm;

	shm.CreateShm(2017, sizeof(Information), IPC_CREAT | 0777);

	shm.AttachShm();

	shm.CopyToShm(&Info1, sizeof(Information));

	Information* pInfo2 = new Information;
	std::memset(pInfo2, 0, sizeof(Information));
	shm.CopyFromShm(pInfo2, sizeof(Information));

	shm.DetachShm();

	shm.RemoveShm();
}
