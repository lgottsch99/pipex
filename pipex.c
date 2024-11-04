/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:54:06 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/04 19:20:14 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>

/*
???
when to pipe when to fork? 1 fork 2 pipe to connect 
how many simultaneous processes needed? 3: main, cmd1, cmd2

TO DO:
1. struktur prozesse: fork + wait
2. exec commands: 
3. create pipe + redirect input /output

create pipe: 
	need fd[2];
	pipe(fd);
	
	fork()
	if in child do sth
	else in parent do sth

child = first cmd
parent = 2nd


execute shell command with execve() (!!current process going to be replaced, only exec in child processes)
dup2 (replace stdout with pipe fd = redirecting output into pipe), 1. open new file 2. dup2(new file, 1) :going to close former fd + open a new one at fd

waitpid() in main process to only finish after all others are finished

simulating |  https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=23

*/
//    ./pipex file1 cmd1 cmd2 file2

int main(void) //int argc, char * argv[]
{
	int fd[2]; //fds for pipe
	int id;

	id = fork(); //parent is some nr, child = 0
	if (id == 0) //we are in child, cmd2
	{
		int id_cmd1;
		
		printf("in 1.child\n");
		id_cmd1 = fork();
		if (id_cmd1 == 0) //in child of child, cmd1
		{
			printf("in 2.child 1\n");
			return 0;

		}
		else
		{
			wait(NULL);
			printf("in 2.child 2\n");
			close(fd[0]); //close end of pipe not needed
			//write(fd[1],   ); //write sth to pipe
			close(fd[1]); //close one finished
			return 0; 

		}
	}
	else {
	//in parent

		close(fd[1]);
		//read(fd[0],     ); //read from pipe
		printf("in parent\n");

		close(fd[0]);
		
	
	}
	wait(NULL);
	wait(NULL);
	wait(NULL);

	
	ft_printf("hello\n");
		return 0; 

}