#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int	main()
{
	struct timeval time;
	unsigned int	start_time;
	unsigned int	end_time;

	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	for (int i=0;i<3;i++)
	{
		if (i % 2 == 0)
			printf("tic\n");
		else
			printf("tac\n");
		sleep(1);
	}
	gettimeofday(&time, NULL);
	end_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("it takes %d ms\n", end_time - start_time);
}
