#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* odd (void* arg) {
    int* var = (int*)arg;
    while (1) 
    {
        printf("bruh %d\n", *var);
        sleep(2);
        
        (*var)++;
    }

    return NULL;
}

void* even (void* arg) {
    int* var = (int*)arg;
    while (1)
    {
        printf("Yo mama so fat %d \n", *var);
        sleep(1);
        (*var)++;
    }
}


void main() {
    int a = 6;
    pthread_t __odd__, __even__;

    pthread_create(&__odd__, NULL, odd, &a);
    pthread_create(&__even__, NULL, even, &a);

    // Following statements make it so that as long as the threads want to run, they can. 
    // Otherwise when the main function wishes to exit, the threads would be forced to do the same.
    pthread_join(__odd__, NULL);
    pthread_join(__even__, NULL);
    
}