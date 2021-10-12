#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;

typedef struct	s_student
{
	int			id;
	pthread_t	tid;
}				t_student;

void *student_behave(void *param)
{
	t_student *student;
	student = (t_student*)param;
	for(int i=0;i <10; i++)
	{
		if (i % 2 == 0)
			printf("%d (%ud) : tic\n", student->id, pthread_self());
		else
			printf("%d : toc\n", student->id);
		sleep(1);
	}
}

int main()
{
	int i;
	t_student *student;
	pthread_t tid;
	pthread_mutex_init(&mutex, NULL);
	student = (t_student*)(malloc(sizeof(t_student) * 3));
	i = 0;
	while (i < 3)
	{
		student[i].id = i;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		pthread_create(&(student[i].tid), NULL, student_behave, (void*)(&student[i]));
		printf("pthread has created\n");
		i++;
	}
	i=0;
	while (i < 3)
	{
		pthread_join(student[i].tid, NULL);
		i++;
	}
	free(student);
	printf("done\n");
	pthread_mutex_destroy(&mutex);
	return(0);
}
