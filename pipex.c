/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:54:06 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/10 17:51:43 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>


/*
???
parsing for cmd flags

TO DO:
Try and play with og command, see what should happen
change execve: parsing for flags and creating array of str
check error handling of og

OK handling output file


STRATEGY:
-check if input correct, files accessible
-fork to kid2 
-in kid2: open infile, execve cmd1, write to pipe
-in kid1: wait kid2 finished, read from pipe, use it to execve cmd 2, write output to outfile (NOT STDOUT)

NOTES:
stderr writes to terminal by default
< is input redirection 
> output redirection, out file is created if does not already exist / overwritten if exists!
PATH holds all important paths 


simulating |  https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=23

*/
//   ./pipex file1 cmd1 cmd2 file2

int	check_input(char *argv[]) //checks if files are accessible/ exist, ret 0 if ok, 1 if NOT ok
{
	//if infile does not exist, < will NOT create it -> error msg
	int	infile;
	int outfile;

	infile = 1;
	outfile = 1;
	if (access(argv[1], F_OK) == 0) //file 1 need to exist or read
	{
		if (access(argv[1], R_OK) == 0)
			infile = 0;
	}

	
	// if (access(argv[4], F_OK) == 0) //file 2 exist and write ?? check needed?
	// {
	// 	if(access(argv[4], W_OK) == 0)
	// 		outfile = 0;
	// }
	//return (infile + outfile);
	return (infile );
}

void	kid2(int fd0, int fd1, char *argv[], char *envp[]) //write exec 1 to pipe
{
	ft_printf("in ft kid 2\n");

	int infile;
	int id;
	int pipefile;
	
	close(fd0); //no need to read out
	close (fd1); //testing only 
	
	if ((infile = open(argv[1], O_RDONLY)) == -1) //open infile
	{
		ft_printf("error open infile\n");
		return;
	}
	ft_printf("infile opened\n");

///------------------------------here it continues in pipe
		
	if ((pipefile = open("pipefile", O_WRONLY)) == -1) //testing only: write to pipefile instead of pipe
	{
		ft_printf("error open pipefile\n");
		return;
	}
	
	if ((infile = dup2(infile, STDIN_FILENO)) == -1) //redirect infile to be stdin ??????needed?
	{
		ft_printf("error dup2 stdin\n");
		return;
	}
	close (infile);
	if ((dup2(pipefile, STDOUT_FILENO)) == -1) //redirect input end of pipe to be stdout
	{
		ft_printf("error dup2 pipefile\n");
		return;
	}
	ft_printf("in/out redirected\n"); //in pipe OK


		
	//exec cmd1 (will use infile as input????) 
	//---- fork again! otherwise kid1 process gone
	id = fork();
	if (id == 0)
	{	//in child for execv
		//ft_printf("in child for execv 1\n");  //in pipe OK

		//TO DO : somehow execve
		exec_cmd(argv[2], envp);
	}
	wait(NULL);
	//close (fd1);
}

void	kid1(int fd0, int fd1, char *argv[], char *envp[]) //read from pipe, exec 2, write output to outfile
{
ft_printf("in ft kid 1\n");

	int id;
	int	outfile;
	int pipefile;

	close(fd1);
	close(fd0);//for testing only 
	
	//open outfile
	if ((outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR|S_IWUSR)) == -1) //create if does  not exist, overwrite if exists?
	{
		ft_printf("error open outfile\n");
		return;
	}
	//ft_printf("outfile opened\n");
	if ((pipefile = open("pipefile", O_RDONLY)) == -1) //testing only!!!
	{
		ft_printf("error open pipefile\n");
		return;
	}

	//--------------------here it goes to outfile

	//redirect stdin to be read end pipe
	if((dup2(pipefile, STDIN_FILENO)) == -1)
	{
		ft_printf("error dup2 stdin\n");
		return;
	}
	//redirect stdout to be outfile
	if((dup2(outfile, STDOUT_FILENO)) == -1)
	{
		ft_printf("error dup2 stdout\n");
		return;
	}
	close(outfile);

	ft_printf("in/out redirected\n");

	//exec cmd2
	id = fork();
	if (id == 0)
	{
		ft_printf("in child for execv 2\n");

		//in child for execv
		exec_cmd(argv[3], envp);
	}
	wait(NULL);
	//close(fd0);
}

void	forkto2(char *argv[], char *envp[]) //fork to 2 kids total, initialize pipe
{
	int fd[2]; //fd[0] for read out , fd[1] for write in
	int	id1;

	ft_printf("in forkto2\n");

	if (pipe(fd) == -1)
	{
		ft_printf("error pipe\n");
		return;
	}

			
	id1 = fork();
	if (id1 == 0) //in kid 1
	{
		ft_printf("in p kid 1\n");

		int	id2;

		id2 = fork();
		if(id2 == 0) //in kid 2
		{ //cmd 1 , write in pipe
			ft_printf("in p kid 2\n");

			kid2(fd[0], fd[1], argv, envp);
			
		}
		wait(NULL);
		ft_printf("back in p kid 1\n");

		kid1(fd[0], fd[1], argv, envp);
	}
	wait(NULL);
	ft_printf("back in p parent\n");

	return;
}

//    ./pipex file1 cmd1 cmd2 file2
int main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
	{
		ft_printf("Correct no arguments\n");

		int check;
		
		if ((check = check_input(argv)) != 0) //checks if files are accessible/ exist
			return 1; //special error?? CHECK OG shell behaviour
		ft_printf("file permissions ok\n");

		forkto2(argv, envp);
		
		ft_printf("back in main\n");

	}
	else
	{
		ft_printf("Not correct no arguments (should be 5)\n");
		return 0; //??
	}
}
