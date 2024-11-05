/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:31 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/05 19:19:35 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include "./full_libft/full_libft.h"
#include <sys/types.h> //fork
#include <fcntl.h> //open

//pipex.c
void	forkto2(char *argv[]);
void	kid2(fd0, fd1, char *argv[]);
void	kid1(fd0, fd1, char *argv[]);
int		check_input(char *argv[]);


//pipex_help.c
void	exec_cmd(cmd1);




#endif