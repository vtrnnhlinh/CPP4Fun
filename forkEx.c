#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid > 0) {
        sleep(100);
        printf(" ");
    }
    else {
        printf("Hi");
    }
}