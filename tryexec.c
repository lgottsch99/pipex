#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>

/*
NOTES

how to know where ALL shell cmds are stored?

need to fork before execve

*/


// try to execute a shell cmd with file

int main(int argc, char *argv[])
{
	if (argc >= 1)
	{
		int id;

		id = fork();
		if (id == 0)
		{
			//bsp: ls - l 
			char *pathname = "/usr/bin/";
			char *cmd1 = argv[1];
			pathname = ft_strjoin(pathname, cmd1);
			ft_printf("%s\n", pathname);
			char *argv[]= {pathname, NULL};

			execve(pathname, argv, NULL); // !! overwriting current process
		}
		else
		{
			wait(NULL);
			ft_printf("hello after execve\n");
		}
	}
}