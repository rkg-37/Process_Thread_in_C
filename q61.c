#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 40

int thread_body_sum(void *val){
	//int x = *(int *)val;
	int sum=0;
	for(int i=1;i<=*(int*)val;i++){
		sum=sum+*((int*)val+i);	
	}
	return sum;
}

void* thread_body_prime(void *val){
	//int x = *(int *)val;
	int flag=1;
	for(int i=2;i<=*(int *)val;i++){
		for(int j=2;j<*((int *)val+i);j++){
			if(*((int *)val+i)%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1){
			printf("prime number %d\n",i);
		}else{
			flag=1;
		}
	}
	printf("\n");
	return NULL;
}


int main(){
	pthread_t th1,th2;
	int range[MAX];
	int p;
	printf("enter the range\n");
	scanf("%d",&range[0]);

	printf("enter the range\n");
	for(int i=1;i<=range[0];i++){
		scanf("%d",&range[i]);
	}

	// thread 1 
	int n1 = pthread_create(&th1,NULL,(void*)&thread_body_sum,(void*)range);
	if(n1!=0){
		printf("thread creation failed\n");
		exit(1);
	}

	//thread 2
	int n2 = pthread_create(&th2,NULL,thread_body_prime,(void*)range);
	if(n2!=0){
		printf("thread creation failed\n");
		exit(1);
	}
	sleep(1);


	if(pthread_join(th1,(void **)&p)){
		printf("thread join failed\n");
		exit(1);
	}

	if(pthread_join(th2,NULL)){
		printf("thread join failed\n");
		exit(1);
	}
	printf("sum of ranges is %d \n",p);

	printf("main thread ends\n");
	return 0;
}
