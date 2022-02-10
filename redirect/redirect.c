#include "../include/minishell.h"

int	redirect(int oldfd, int newfd)
{
	int	checker;

	checker = 0;
	if (oldfd != newfd)
	{
		checker = dup2(oldfd, newfd);
		if (checker < 0)
			return (checker);
		else
			close(oldfd);
	}
	return (checker);
}
