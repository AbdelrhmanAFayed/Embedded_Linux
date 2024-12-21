#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>




int main(void)
{

	
	key_t key = ftok("progfile", 65);
	
	int shmid ;
	
	shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        perror("shmget failed");
        return 1;
    }

      char *shared_memory = (char *)shmat(shmid, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat failed");
        return 1;
    }
    strcpy(shared_memory, "Too many tasks");
    printf("Data written to shared memory: %s\n", shared_memory);


    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        return 1;
    }

    return 0;









}
