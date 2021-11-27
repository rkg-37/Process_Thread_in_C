#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_body_even(void *val){
	int x = *(int *)val;
	for(int i=0;i<x;i+=2){
		printf("from thread-body-odd : %d\n",i);		
	}
	return NULL;
}

void* thread_body_odd(void *val){
	int x = *(int *)val;
	for(int i=1;i<x;i+=2){
		printf("from thread-body-even : %d\n",i);	
	}	
	return NULL;
}


int main(){
	pthread_t th1,th2;
	int x;
	printf("enter the range\n");
	scanf("%d",&x);

	// thread 1 
	int n1 = pthread_create(&th1,NULL,thread_body_even,(void*)&x);
	if(n1!=0){
		printf("thread creation failed\n");
		exit(1);
	}

	//thread 2
	int n2 = pthread_create(&th2,NULL,thread_body_odd,(void*)&x);
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
