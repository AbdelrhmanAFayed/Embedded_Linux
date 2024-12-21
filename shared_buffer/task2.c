#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key;
    int shmid;

    key = ftok("progfile", 65);


    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    char *shared_memory = (char *)shmat(shmid, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat failed");
        return 1;
    }

    printf("Data read from shared memory: %s\n", shared_memory);

    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        return 1;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl failed");
        return 1;
    }

    return 0;

}
