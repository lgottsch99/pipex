/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:46:53 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/05 19:19:39 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//   ./pipex file1 cmd1 cmd2 file2

void	exec_cmd(cmd) //already forked, redirected in/out inherited
{
	ftprintf("in exec_cmd\n");

	char *pathname;
	char *path;
	char *argexe[2];

	path = "/usr/bin/";

	pathname = ft_strjoin(path, cmd);
	ft_printf("joined path: %s\n", pathname);

	argexe = {pathname, NULL};
	execve(pathname, argv, NULL);
}