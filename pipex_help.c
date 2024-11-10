/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:46:53 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/10 17:51:47 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//   ./pipex file1 cmd1 cmd2 file2
/*

TO DO 
parse for flags and create array (wahrsch nur eine var after - ok)
exec_cmd anpassen sodass path + argv correct

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

char *get_realcmd(char *cmd)
{
	char *realcmd;
	int index;

	realcmd = NULL;
	index = get_index(cmd);
	if (index < (int)ft_strlen(cmd))
		realcmd = ft_substr(cmd, 0, index);
	
	return (realcmd);

}



char *get_flags(char *cmd)//not executing????
{
	//cmd can be sth like "ls -lf" or "wc" or "grep abc", return flags only if there, else empty str
	char *flags;
	int index;

	flags = NULL;
	//count until ' ' space only, minus nicht zwingend
	index = get_index(cmd);
	
	if (index < (int)ft_strlen(cmd))
	{
		//substr -begins at start and max len len
		flags = ft_substr(cmd, index + 1, ft_strlen(cmd)); 
	}
	return(flags);
}

char *get_path(char *envp[]) //find path in envp and extract full path
{
	int i;
	char *fullpath;
	
	i = 0;
	while (envp[i])
	{
		ft_printf("%s\n", envp[i]);
		if((ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))!= NULL)
		{
			if(envp[i][0]== 'P' && envp[i][1]== 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
			{
				ft_printf("path found\n");
				fullpath = ft_substr(envp[i], 5, (ft_strlen(envp[i])));
				ft_printf("%s\n", fullpath);
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
		ft_printf("joined: %s\n", joined);
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
	ft_printf("in exec_cmd\n");

	char *path;
	char *exec_path;
	char *flags;
	char *real_cmd;
	char *argexe[2];
	//how to know how big argexe should be?
	//[0] should be command itself, [1] flags, [2] NULL

//parse for flags
	flags = get_flags(cmd);
	ft_printf("flags: %s\n", flags);

	real_cmd = get_realcmd(cmd);
	ft_printf("real cmd: %s\n", real_cmd);


	path = get_path(envp);
	exec_path = get_exec_path(cmd, path);
	
	ft_printf("executable path: %s\n", exec_path);

	argexe[0] = exec_path;

	
	
	//ft_printf("argexe array 0: %s\n", argexe[0]);
	argexe[1] = NULL;
	
	execve(exec_path, argexe, NULL);
}