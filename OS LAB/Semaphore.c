#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h> /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h> /* Semaphore */

/* prototype for thread routine */
void shop1( void *ptr );
void shop2( void *ptr );
void shop3( void *ptr );

int icerem = 0;
sem_t mutex;

int main() {

	int n;
	printf("Enter No Of Ice Cream: ");
	scanf("%d",&n);
	icerem=n;
	int i[3] = {1, 2, 3};
	pthread_t t1,t2,t3;
	sem_init(&mutex, 0, 1);
	pthread_create(&t1, 0, (void *) &shop1, (void *) &i[0]);
	pthread_create(&t2, 0, (void *) &shop2, (void *) &i[1]);
	pthread_create(&t3, 0, (void *) &shop3, (void *) &i[2]);	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	sem_destroy(&mutex);
	return 0;
}

void shop1(void *ptr) {
	int x = *((int*)ptr);
	while(icerem>0){
	printf("Person %d Waiting to Get Icecream. \n", x);
	sem_wait(&mutex);
	sleep(0.5); 
            printf("Person %d Gets Icecream \n", x);
		printf("Person %d gets icecream Number %d.\n",x,icerem--);
		printf("Person %d Leaving Shop.\n", x);
	sem_post(&mutex);}
	pthread_exit(0);
}
void shop2(void *ptr) {
        int x = *((int*)ptr);
	while(icerem>0){
        printf("Person %d Waiting to Get Icecream. \n", x);
        sem_wait(&mutex); 
            printf("Person %d Gets Icecream \n", x);
        sleep(0.5);       
	 printf("Person %d gets icecream Number %d.\n",x,icerem--);
                printf("Person %d Leaving Shop.\n", x);
        sem_post(&mutex);}
        pthread_exit(0);
}

void shop3(void *ptr) {
        int x = *((int*)ptr);
	while(icerem>0){
        printf("Person %d Waiting to Get Icecream. \n", x);
        sem_wait(&mutex); 
            printf("Person %d Gets Icecream \n", x);
	sleep(0.5);                
printf("Person %d gets icecream Number %d.\n",x,icerem--);
                printf("Person %d Leaving Shop.\n", x);
        sem_post(&mutex);}
        pthread_exit(0);
}


