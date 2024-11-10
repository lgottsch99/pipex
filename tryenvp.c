#include <stdio.h>
#include "pipex.h"
#include <unistd.h>

/*
envp hold lotttsss of info about compputer and environment, including PATH!!!
*/

int next(char *path, int i)
{
	while (path[i] != ':' && path[i])
		i++;
	return (i);
}

char *get_exec_path(char *cmd, char *path)
{
	int index;
	char *maybe;
	int  start;
	char *joined;

	start = 0;
	index = 0;
	while(path[index])
	{
		//create substr
		index = next(path, index);
		maybe = ft_substr(path, start, (index - start));
		ft_printf("maybe: %s\n", maybe);
		joined = ft_strjoin(maybe, "/");
		joined = ft_strjoin(joined, cmd);
		ft_printf("joined: %s\n", joined);

		//check if cmd file exists and access ok, if yes stop
		if (access(joined, X_OK) == 0)//success 
		{
			return (maybe);
		}
		else 
		{
			index = index + 1; //skip :
			start = index;
		}
	}
	printf("no exec\n");
	return (NULL);
}

int main (int argc, char *argv[], char *envp[])
{
	int i;
	char *path;
	char * exec_path;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		if((ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))!= NULL)
		{
			if(envp[i][0]== 'P' && envp[i][1]== 'A')
			{
				printf("path found\n");
			
			//substr final
			path = ft_substr(envp[i], 5, (ft_strlen(envp[i])));
			printf("full: %s\n", path);
			break;
			}
		}
		i++;
	}

	exec_path= get_exec_path(argv[2], path);
	printf("final exec path: %s\n", exec_path);

}