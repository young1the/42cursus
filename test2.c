#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex1;
int				stop = 0;

typedef struct	s_student
{
	int			id;
	pthread_t	tid;
}				t_student;

t_student *student;

void *cap_do(void *param)
{
	for(int i=0;i < 5; i++)
	{
		sleep(1);
	}
	stop = 1;
	pthread_mutex_lock(&mutex1);
	printf("cap : Get Out\n");
	for (int i=0; i<3;i++)
	{
		pthread_detach(student[i].tid);
	}
	pthread_mutex_unlock(&mutex1);
}

void *jol_do(void *param)
{
	t_student *student;
	student = (t_student*)param;
	for (int i=0; i < 10; i++)
	{
		pthread_mutex_lock(&mutex1);
		if (stop != 1)
			printf("jol%d : nam nam %d\n", student->id,i);
		pthread_mutex_unlock(&mutex1);
		sleep(1);
	}
}

int main()
{

	pthread_t tid;

	pthread_mutex_init(&mutex1, NULL);
	student = (t_student*)malloc(sizeof(t_student) * 2);
	for (int i =0; i <3; i++)
		student[i].id = i;
	pthread_create(&tid, NULL, cap_do, NULL);
	for (int i =0; i<3; i++)
	{
		pthread_create(&(student[i].tid), NULL, jol_do, (void*)(&student[i]));
	}
	pthread_join(tid, NULL);
	free(student);
	int j = pthread_mutex_destroy(&mutex1);
	printf("done %d\n", j);
}
