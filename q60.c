#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_body(void *msg){
	printf("thread body :thread message : =%s \n",(char*)msg);
	return NULL;
}


int main(){
	pthread_t th1,th2;
	char* st1="Thread 1";
	char* st2="Thread 2";
	char *p;char *q;
	// thread 1 
	int n1 = pthread_create(&th1,NULL,thread_body,(void*)st1);
	if(n1!=0){
		printf("thread creation failed\n");
		exit(1);
	}
	//thread 2
	int n2 = pthread_create(&th2,NULL,thread_body,(void*)st2);
	if(n2!=0){
		printf("thread creation failed\n");
		exit(1);
	}
	sleep(1);
	printf("waiting in main thread\n");
	if(pthread_join(th1,NULL)){
		printf("thread join failed\n");
		exit(1);
	}

	if(pthread_join(th2,NULL)){
		printf("thread join failed\n");
		exit(1);
	}
	printf("main thread exiting \n");
	return 0;
}
