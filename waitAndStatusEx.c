#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int return_code;
    int status;
    /* create a new process */
    return_code = fork();
    if (return_code > 0) {
        int id = wait(&status);
        printf("Parent process: child's pid = %d with returned value %d \n", id, WEXITSTATUS(status));
        printf("child's pid = %d with raw returned value = %d \n", id, status);
        printf("Pid of child %d \n", return_code);
        return 0;
    }
    else if (return_code == 0) {
        printf("This is child process \n");
        return 10; //exit(10);
    }
    else {
        printf("Fork error \n");
        return 1;
    }
}