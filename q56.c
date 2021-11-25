# include <stdio.h>
# include <unistd.h>
#include <signal.h>

void hdlr(int x){
	printf("\nsignal occured %d \n",x);
	if(x==SIGINT){
		printf("\nsigint called\n");
		printf("************************");
	}
}

int main(){
	signal(SIGINT,hdlr);
	while(1){
		printf("inside parent\n");
		printf("process id %d\n",getpid());
		printf("\n");
		sleep(2);
	}
	return 0;
}
