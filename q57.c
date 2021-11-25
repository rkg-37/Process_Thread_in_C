# include <stdio.h>
# include <unistd.h>
#include <signal.h>

void hdlra(int x){
	if(x==SIGUSR1){
		printf("from process a\n");
		printf("i am awake\n");
	}
	if(x==SIGUSR2){
		printf("from process b\n");
		printf("i am awake\n");		
	}
}

int main(){
	signal(SIGUSR1,hdlra);
	signal(SIGUSR2,hdlra);
	int p_a,p_b;
	p_a=fork();
	if(p_a==0){
		while(1){
			printf("child process %d , parent process  %d\n",getpid(),getppid());
			sleep(2);
		}
	}else{
		p_b=fork();
		if(p_b==0){
			while(1){
				printf("child process %d , parent process  %d\n",getpid(),getppid());
				sleep(2);
			
			}
		}
		else{
			while(1){printf("from parent\n");	
			sleep(2);
			kill(p_a,SIGUSR1);
			sleep(2);
			kill(p_b,SIGUSR2);
			}

		}
	}
	return 0;
}
