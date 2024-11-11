/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:46:53 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/11 18:53:50 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//   ./pipex file1 cmd1 cmd2 file2
/*

TO DO 
parse for flags and create array (wahrsch nur eine var after - ok) -NO Mehrere need to work too!!!!!!!

Strategy to make execv work:
	//get all possible path combos and check if executable with access??
	//then execute the one that works

*/

int get_index(char *cmd)
{
	int index;
	
	index = 0;
	while (cmd[index] != ' ' && cmd[index])
		index++;
	ft_printf("index flags: %i\n", index);

	return (index);

}

char *get_path(char *envp[]) //find path in envp and extract full path
{
	int i;
	char *fullpath;
	
	i = 0;
	while (envp[i])
	{
		//ft_printf("%s\n", envp[i]);
		if((ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))!= NULL)
		{
			if(envp[i][0]== 'P' && envp[i][1]== 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
			{
				ft_printf("path found\n");
				fullpath = ft_substr(envp[i], 5, (ft_strlen(envp[i])));
				//ft_printf("%s\n", fullpath);
				return (fullpath);
			}
		}
		i++;
	}
	return (NULL);
}

int next(char *path, int i)//get location next : in path
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
		index = next(path, index);
		maybe = ft_substr(path, start, (index - start));
		joined = ft_strjoin(maybe, "/");
		joined = ft_strjoin(joined, cmd);
		//ft_printf("joined: %s\n", joined);
		if (access(joined, X_OK) == 0)//success 
			return (joined);
		else 
		{
			index = index + 1; //skip :
			start = index;
		}
	}
	ft_printf("no exec\n");
	return (NULL);
}


void	exec_cmd(char *cmd, char *envp[]) //already forked, redirected in/out inherited
{
	ft_printf("in exec_cmd, cmd: %s\n", cmd);

	char *path;
	char *exec_path;
	char **argexe;

	argexe = ft_split(cmd, ' ');

	path = get_path(envp);
	ft_printf("path: %s\n", path);

	exec_path = get_exec_path(argexe[0], path);
	ft_printf("executable path: %s\n", exec_path);

	//check with access() if cmd is executable
	if ((access(exec_path, X_OK)) == -1)
		exit(1);

	if(execve(exec_path, argexe, NULL) == -1)
		exit(1);
}
