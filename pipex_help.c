/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:46:53 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/06 17:26:18 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//   ./pipex file1 cmd1 cmd2 file2

//for exec1 OK: if cmd path exists is executing and directing output to pipefile

void	exec_cmd(char *cmd) //already forked, redirected in/out inherited
{
	ft_printf("in exec_cmd\n");

	char *pathname;
	char *path;
	char *argexe[2]; //[0] should be command itself, [1] flags, [2] NULL

	path = "/usr/bin/";

	pathname = ft_strjoin(path, cmd);
	ft_printf("joined path: %s\n", pathname);

	argexe[0] = pathname;
	ft_printf("argexe array 0: %s\n", argexe[0]);
	argexe[1] = NULL;
	
	execve(pathname, argexe, NULL);
}