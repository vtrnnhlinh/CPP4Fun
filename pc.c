#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_ITEMS 5
#define THREADS 1 // 2 producers and 2 consumers
#define LOOPS 2 * MAX_ITEMS // variable

// Initiate shared buffer
int buffer[MAX_ITEMS];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;
sem_t mutex; // Protects put() and get()

void put(int value) {
  buffer[fill] = value; // line f1
  fill = (fill + 1) % MAX_ITEMS; // line f2
}

int get() {
  int tmp = buffer[use]; // line g1
  use = (use + 1) % MAX_ITEMS; // line g2
  return tmp;
}

void * producer(void * arg) {
  int i;
  int tid = (int) arg;
  for (i = 0; i < LOOPS; i++) {
    sem_wait(&empty);
    sem_wait(&mutex);
    put(i); // line P2
    printf("Producer %d put data %d\n", tid, i);
    sem_post(&mutex);
    sem_post(&full);
    sleep(1);
  }
  pthread_exit(NULL);
}

void * consumer(void * arg) {
  int i, tmp = 0;
  int tid = (int) arg;
  while (tmp != -1) {
    sem_wait(&full);
    sem_wait(&mutex);
    tmp = get(); // line C2
    printf("Consumer %d get data %d\n", tid, tmp);
    sem_post(&mutex);
    sem_post(&empty);
    sleep(1);
  }
  pthread_exit(NULL);
}

int main(int argc, char ** argv) {
  int i, j;
  int tid[THREADS];
  pthread_t producers[THREADS];
  pthread_t consumers[THREADS];

  sem_init(&empty, 0, MAX_ITEMS);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1); // mutex = 1 because it is a lock

  for (i = 0; i < THREADS; i++) {
    tid[i] = i;
    // Create producer thread
    pthread_create( & producers[i], NULL, producer, (void * ) tid[i]);

    // Create consumer thread
    pthread_create( & consumers[i], NULL, consumer, (void * ) tid[i]);
  }

  for (i = 0; i < THREADS; i++) {
    pthread_join(producers[i], NULL);
    pthread_join(consumers[i], NULL);
  }

  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&mutex);

  return 0;
}
