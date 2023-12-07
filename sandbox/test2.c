#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int back () {
    long num_processors = sysconf(_SC_NPROCESSORS_ONLN);

    num_processors = -1;
    
    if (num_processors == -1) {
        errno = 3;
        perror("sysconf");
        return -1;
    }
    
    printf("Number of processors available: %ld\n", num_processors);
    
    return 0;
}

int main () {
    for (int i = 0; i < 130; i++)
    {
        errno = i;
        printf("%d", i);
        perror("");
        printf("\n");
    }
}
