#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>
/*
NOTES: 
pipe = kind of a file

immer 1. pipe 2. fork, damit connection von kids inherited wird

sending arrays: 
    child: 1. send nr of elements in array 2. send array itself
    parent: 1. read nr of elements 2. read array itself

ACHTUNG: KEIN ERROR CHECKING pipe, fork, read, write !!!!!!!!!
*/


//try create and write and read from pipe

int main (void)
{
    int id;
    int fd[2]; //ends of pipe
                //fd[0] read out ALWAYS
                //fd[1] write in ALWAYS
    pipe(fd); //returns -1 on err

    id = fork();
    if (id == 0)//child, write in pipe
    {
        int len;
        char *str = "Hello there\n";

        close(fd[0]); //no need to read
        len = (int)ft_strlen(str);
        ft_printf("len: %i\n", len);

        write(fd[1], &len, sizeof(int)); //nr of elements in array

        write(fd[1], str, len); //array itself

        close(fd[1]); //finished using
    }
    else
    {
        int len;
        char *buf;

        wait(NULL);
        close(fd[1]); //no need to write

        read(fd[0], &len, sizeof(int)); //get len of str
        ft_printf("len in p: %i\n", len);
        buf = (char *)malloc(sizeof(char) * len); //make space to read into

        read(fd[0], buf, len); //get str itself
        ft_printf("buf: %s\n", buf);
        close(fd[0]); //finished reading 
    }
    wait(NULL);
    return 0;
}