
#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>

//fork and wait structure for 3 processes: main + 2 kids
int main (void)
{
    int id; 
	int id2;

    id = fork();
    if (id == 0)
    {
		printf("in child 1\n");

        id2 = fork();
        if (id2 == 0)
        {
            printf("in child 2\n");
        }
        else
        {
            wait(NULL);
			printf("back in child 1\n");

        }
    }
    else if (id != 0 || id2 != 0)
    {
        wait(NULL);
        printf("in parent\n");
    printf("exit b\n");
    return 0;
}
}