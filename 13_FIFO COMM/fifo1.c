// Process 1
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main() {
    int fd1, fd2;
    char *myfifo1 = "file1", str1[100], str2[100];
    char *myfifo2 = "file2";

    // create FIFO pipes (files)
    fd1 = mkfifo(myfifo1, 0666);
    fd2 = mkfifo(myfifo2, 0666);

    // read data to write on first fifo file
    printf("\nEnter the sentence: ");
    fgets(str1, 100, stdin);

    // write data on first FIFO pipe
    fd1 = open(myfifo1, O_WRONLY);
    write(fd1, str1, strlen(str1) + 1);
    close(fd1);

    // read data from second pipe
    fd2 = open(myfifo2, O_RDONLY);
    read(fd2, str2, 100);

    // print output
    printf("\nmessage from fifo2 process: \n %s", str2);
    close(fd2);

}