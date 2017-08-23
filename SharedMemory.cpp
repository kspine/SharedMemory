#include "SharedMemory.h"

#include <sys/types.h>
#include <sys/shm.h>

#include <cstring>
#include <iostream>

int SharedMemory::CreateShm(key_t key, size_t size, int shmflg)
{
	_nId = shmget(key, size, shmflg);
	if (_nId == -1)
		std::cerr << "Failed to shmget, errno: " << errno << std::endl;
	else
		std::cout << "shmid: " << _nId << std::endl;
	return _nId;
}

void* SharedMemory::AttachShm(int shmflg)
{
	_pMem = shmat(_nId, NULL, shmflg);
	if (*(int *)_pMem == -1)
		std::cerr << "Failed to AttachShm, errno:" << errno << std::endl;
	return _pMem;
}

int SharedMemory::DetachShm()
{
	int nRet = shmdt(_pMem);
	if (nRet == -1)
		std::cerr << "Failed to DetachShm, errno: " << errno << std::endl;
	_pMem = NULL;
	return nRet;
}

int SharedMemory::RemoveShm()
{
	int nRet = shmctl(_nId, IPC_RMID, NULL);
	if (nRet == -1)
		std::cerr << "Failed to removeShm, errno: " << errno << std::endl;
	return nRet;
}

int SharedMemory::CopyToShm(void const* pInfo, size_t nSize)
{
	int nRet;
	struct shmid_ds buf;

	nRet = shmctl(_nId, IPC_STAT, &buf);
	if (nRet == -1)
		goto fail_one;

	nRet = shmctl(_nId, SHM_LOCK, NULL);
	if (nRet == -1)
		goto fail_two;

	std::memcpy(_pMem, pInfo, nSize);

	nRet = shmctl(_nId, SHM_UNLOCK, NULL);
	if (nRet == -1)
		goto fail_three;

	return nRet;

	fail_one:std::cerr << "Failed to CopyToShm(IPC_SET), errno: " << errno << std::endl;return -1;
	fail_two:std::cerr << "Failed to CopyToShm(SHM_LOCK), errno: " << errno << std::endl;return -1;
	fail_three:std::cerr << "Failed to CopyToShm(SHM_UNLOCK), errno: " << errno << std::endl;return -1;
}

int SharedMemory::CopyFromShm(void* pInfo, size_t nSize)
{
	int nRet;
	struct shmid_ds buf;

	nRet = shmctl(_nId, IPC_STAT, &buf);
	if (nRet == -1)
		goto fail_one;

	nRet = shmctl(_nId, SHM_LOCK, NULL);
	if (nRet == -1)
		goto fail_two;

	std::memcpy(pInfo, _pMem, nSize);

	nRet = shmctl(_nId, SHM_UNLOCK, NULL);
	if (nRet == -1)
		goto fail_three;

	return nRet;

	fail_one:std::cerr << "Failed to CopyFromShm(IPC_STAT), errno: " << errno << std::endl;return -1;
	fail_two:std::cerr << "Failed to CopyFromShm(SHM_LOCK), errno: " << errno << std::endl;return -1;
	fail_three:std::cerr << "Failed to CopyFromShm(SHM_UNLOCK), errno: " << errno << std::endl;return -1;
}

