# include <stdio.h>
# include <unistd.h>
#include <signal.h>

int g=0;
void hdlr(int x){
	printf("signal occured %d for pid %d",x,getpid());
	if(x==17){
		g=1;
		printf("g==1\n");
	}else{
		g=0;
	}
}

int main(){
	signal(SIGCHLD,hdlr);
	int p;
	p=fork();
	if(p==0){
		while(1){
			printf("child process %d , parent process  %d\n",getpid(),getppid());
			sleep(1);
		}
	}else{
		sleep(2);
		if(g==1){
			printf("child over by itself\n");
		}else{
			printf("child process %d , parent process  %d\n",p,getpid());
			printf("child terminated forecefully\n");
			kill(p,SIGINT);
		}
		printf("parent ends\n");
	}
	return 0;
}
