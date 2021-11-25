# include <stdio.h>
# include <unistd.h>
#include <signal.h>

int g=0;
void hdlr(int x){
	printf("signal %d occured for process %d\n",x,getpid());
	if(x==17){
		g=1;
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
		printf("child process %d -- parent process  %d\n",getpid(),getppid());
		sleep(1);}
	}else{
		sleep(5);
		printf("child process %d -- parent process  %d\n",p,getpid());
		if(g==1){
			printf("child ended by itself\n");
		}else{
			printf("child running still\n");
		}
		printf("parent ends\n");
	}
	return 0;
}
