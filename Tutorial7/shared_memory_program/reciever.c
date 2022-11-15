#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_SIZE 3 * sizeof(int)

int main()
{
    int fd = shm_open("/meow", O_RDONLY, 0666);
    if (fd < 0 )
    {
        printf("Error opening shm\n");
        return EXIT_FAILURE;
    }

    int* data = (int*) mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, fd, 0);

    for(int i = 0; i < 3; i++)
    {
        printf("%d",data[i]);
    }
    munmap(data, SHM_SIZE);
    close(fd);
    shm_unlink("/meow");
    return EXIT_SUCCESS;
}


