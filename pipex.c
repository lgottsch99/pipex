/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:54:06 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/05 19:19:38 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>

/*
???
when to pipe when to fork? 1 fork 2 pipe to connect 
how many simultaneous processes needed? min 3: main, cmd1, cmd2

need to check if shell commands exist?????

TO DO:
Try and play with og command, see what should happen
check execve

STRATEGY:
-check if input correct, files accessible
-fork to kid2 
-in kid2: open infile, execve cmd1, write to pipe
-in kid1: wait kid2 finished, read from pipe, use it to execve cmd 2, write output to outfile (NOT STDOUT)


simulating |  https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=23

*/
//   ./pipex file1 cmd1 cmd2 file2

int	check_input(char *argv[]) //checks if files are accessible/ exist, ret 0 if ok, 1 if NOT ok
{
	int	infile;
	int outfile;

	infile = 1;
	outfile = 1;
	if (access(argv[1], F_OK) == 0) //file 1 need to exist or read
	{
		if (access(argv[1], R_OK) == 0)
			infile = 0;
	}
	if (access(argv[4], F_OK) == 0) //file 2 exist and write
	{
		if(access(argv[4], W_OK) == 0)
			outfile = 0;
	}
	return (infile + outfile);
}

void	kid1(fd0, fd1, char *argv[]) //write exec 1 to pipe
{
	ftprintf("in ft kid 1\n");

	int infile;
	int id;
	
	close(fd0); //no need to read out
	
	if ((infile = open(argv[1], O_RDONLY)) == -1) //open infile
		return 3;
	ftprintf("infile opened\n");

		
	if ((infile = dup2(infile, STDIN_FILENO)) == -1) //redirect infile to be stdin ??????needed?
		return 4;
	if ((dup2(fd1, STDOUT_FILENO)) == -1) //redirect input end of pipe to be stdout
		return 5;
	
	ftprintf("in/out redirected\n");

		
	//exec cmd1 (will use infile as input????) 
	//---- fork again! otherwise kid1 process gone
	id = fork();
	if (id == 0)
	{	//in child for execv
		ftprintf("in child for execv 1\n");

		//TO DO : somehow execve
		exec_cmd(argv[2]);
	}
	wait(NULL);
	close (fd1);
}

void	kid2(fd0, fd1, char *argv[]) //read from pipe, exec 2, write output to outfile
{
ftprintf("in ft kid 2\n");

	int id;
	int	outfile;

	close(fd1);
	
	//open outfile
	if (outfile = open(outfile, O_WRONLY) == -1)
		return 7;
	ftprintf("outfile opened\n");

	//redirect stdin to be read end pipe
	if((dup2(fd0, STDIN_FILENO)) == -1)
		return 6;
	//redirect stdout to be outfile
	if((dup2(outfile, STDOUT_FILENO)) == -1)
		return 8;

	ftprintf("in/out redirected\n");

	//exec cmd2
	id = fork();
	if (id == 0)
	{
		ftprintf("in child for execv 2\n");

		//in child for execv
		exec_cmd(argv[3]);
	}
	wait(NULL);
	close(fd0);
}

void	forkto2(char *argv[]) //fork to 2 kids total, initialize pipe
{
	int fd[2]; //fd[0] for read out , fd[1] for write in
	int	id1;

	ftprintf("in forkto2\n");

	if (pipe(fd) == -1)
		return 2;
		
	id1 = fork();
	if (id1 == 0) //in kid 1
	{
		ftprintf("in p kid 1\n");

		int	id2;

		id2 = fork();
		if(id2 == 0) //in kid 2
		{ //cmd 1 , write in pipe
			ftprintf("in p kid 2\n");

			kid1(fd[0], fd[1], argv);
			
		}
		wait(NULL);
		ftprintf("back in p kid 1\n");

		kid2(fd[0], fd[1], argv);
	}
	wait(NULL);
	
}

//    ./pipex file1 cmd1 cmd2 file2
int main(int argc, char *argv[])
{
	if (argc == 5)
	{
		ftprintf("Correct no arguments\n");

		int check; 
		
		if ((check = check_input(argv)) != 0); //checks if files are accessible/ exist
			return 1; //special error?? CHECK OG shell behaviour
		ftprintf("file permissions ok\n");

		forkto2(argv);
		
	
	}
	else
	{
		ftprintf("Not correct no arguments (should be 5)\n");
		return 0;
	}
}
