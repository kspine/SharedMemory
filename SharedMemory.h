#include <sys/ipc.h>

#include <stdio.h>

class SharedMemory {
public:
	int CreateShm(key_t key, size_t size, int shmflg);

	void* AttachShm(int shmflg = 0);

	int DetachShm();

	int RemoveShm();

	int CopyToShm(void const* pInfo, size_t nSize);

	int CopyFromShm(void* pInfo, size_t nSize);

public:
	SharedMemory() : _pMem(NULL) {}

private:
	int _nId;

	void* _pMem;
};

