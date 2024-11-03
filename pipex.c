/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:54:06 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/03 17:34:11 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
???
when to pipe when to fork? how many simultaneous processes needed?

TO DO

1.create pipe: 
	need fd[2];
	pipe(fd);
	
	fork()
	if in child do sth
	else in parent do sth

child = first cmd
parent = 2nd


execute shell command with execve()
dup2 (duplicate some fds)

waitpid() in main process to only finish after all others are finished

simulating |  https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=23

*/

//    ./pipex file1 cmd1 cmd2 file2

int main(int argc, char * arrgv[])
{
	int fd[2]; //fds for pipe
	int id;

	id = fork(); //parent is some nr, child = 0
	if (id == 0) //we are in child 
	{
		close(fd[0]); //close end of pipe not needed
		write(fd[1],   ); //write sth to pipe
		close(fd[1]); //close one finished
		
	}
	else //in parent
	{
		close(fd[1]);
		read(fd[0],     ); //read from pipe
		
		close(fd[0]);
		
	}





	
	ft_printf("hello\n");
}