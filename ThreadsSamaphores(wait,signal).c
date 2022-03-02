#include<stdio.h>
#include<pthread.h>
#include<math.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex1;
sem_t mutex2;

void* Name(void *u) {
 sem_wait(&mutex1);
 
 //signal the other
 sem_post(&mutex2);
 sem_post(&mutex1);
 
}
void* Booking(void *u) {
  sem_wait(&mutex2);
  sem_wait(&mutex1);
 
 
  
}

int main ()
{

int seat;
char name[20];
printf("Enter your name:");
scanf("%c",name);
fflush(stdin);
printf("Enter seats for booking:");
scanf("%d",&seat);

sem_init(&mutex1,0,1);
sem_init(&mutex2,0,0);



pthread_t tid1, tid2;
pthread_create(&tid1, NULL,&Name,NULL);
pthread_create(&tid2, NULL,&Booking,NULL);


pthread_join(tid1,NULL);
pthread_join(tid2, NULL);



sem_destroy(&mutex1);
sem_destroy(&mutex2);

return 0;
}
