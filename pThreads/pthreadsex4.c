#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//Condition Variables:

//A condition variable is a variable of type pthread_cond_t and is used with the appropriate functions for 
//waiting and later, process continuation. The condition variable mechanism allows threads to suspend execution 
//and relinquish the processor until some condition is true. A condition variable must always be associated with 
//a mutex to avoid a race condition created by one thread preparing to wait and another thread which may signal 
//the condition before the first thread actually waits on it resulting in a deadlock. The thread will be 
//perpetually waiting for a signal that is never sent. 


//Man pages of functions used in conjunction with the condition variable:

//Creating/Destroying:
//pthread_cond_init
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//pthread_cond_destroy
//Waiting on condition:
//pthread_cond_wait - unlocks the mutex and waits for the condition variable cond to be signaled.
//pthread_cond_timedwait - place limit on how long it will block.
//Waking thread based on condition:
//pthread_cond_signal - restarts one of the threads that are waiting on the condition variable cond.
//pthread_cond_broadcast - wake up all threads blocked by the specified condition variable.


pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

void *functionCount1();
void *functionCount2();
int  count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6

main()
{
   pthread_t thread1, thread2;

   pthread_create( &thread1, NULL, &functionCount1, NULL);
   pthread_create( &thread2, NULL, &functionCount2, NULL);

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   printf("Final count: %d\n",count);

   exit(0);
}

// Write numbers 1-3 and 8-10 as permitted by functionCount2()

void *functionCount1()
{
    for(;;) {
             // Lock mutex and then wait for signal to relase mutex
	pthread_mutex_lock( &count_mutex );

	// Wait while functionCount2() operates on count
	// mutex unlocked if condition varialbe in functionCount2() signaled.
	pthread_cond_wait( &condition_var, &count_mutex );
	count++;
	printf("Counter value functionCount1: %d\n",count);

	pthread_mutex_unlock( &count_mutex );

	if(count >= COUNT_DONE) return(NULL);

	}
}

	// Write numbers 4-7
void *functionCount2() {
	for(;;) {
		pthread_mutex_lock( &count_mutex );

		if( count < COUNT_HALT1 || count > COUNT_HALT2 ) {
		// Condition of if statement has been met. 
		// Signal to free waiting thread by freeing the mutex.
		// Note: functionCount1() is now permitted to modify "count".
			pthread_cond_signal( &condition_var );
		} else {
			count++;
			printf("Counter value functionCount2: %d\n",count);
		}

		pthread_mutex_unlock( &count_mutex );
		if(count >= COUNT_DONE) return(NULL);
	}

}

