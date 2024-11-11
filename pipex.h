/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:31 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/11 16:55:42 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include "./full_libft/full_libft.h"
#include <sys/types.h> //fork
#include <sys/wait.h> //wait
#include <fcntl.h> //open
//#include <fcntl.h> //permissions open()

//pipex.c
void	forkto2(char *argv[], char *envp[]);
void	kid2(int fd0, int fd1, char *argv[], char *envp[]);
void	kid1(int fd0, int fd1, char *argv[], char *envp[]);
int		check_input(char *argv[]);

//pipex_help.c
void	exec_cmd(char *cmd, char *envp[]);
char *get_flags(char *cmd);


#endif