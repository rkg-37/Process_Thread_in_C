# include <stdio.h>
# include <unistd.h>
#include <signal.h>

int main(){
	int p;
	p=fork();
	if(p==0){
		while(1){
			printf("child process %d\n",getpid());
			sleep(1);
		}
	}else{
		sleep(5);
		
		if(p%2==0) {
			kill(p,SIGINT);
			printf("kill successful as pid is even\n");
		}else{
			printf("kill not performed as pid is not even\n");
			
		}
		printf("parent ends\n");
	}
	return 0;
}
