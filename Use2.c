//User 2
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
    int fd;
    mkfifo("/tmp/myfifo", 0666);
    char msg[80];
    while(1){
        //reading the first
        fd=open("/tmp/myfifo", O_RDONLY);
        read(fd, msg, 80);
        printf("User1: %s", msg);
        close(fd);

        // writing the file
        fd=open("/tmp/myfifo", O_WRONLY);
        fgets(msg, 80, stdin);
        write(fd, msg, strlen(msg)+1);
        close(fd);
    }
}