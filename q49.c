# include <stdio.h>
# include <unistd.h>
#include <signal.h>

void hdlr(int x){
	printf("ctrl+c pressed by user\n");
}

int main(){
	signal(SIGINT,hdlr);
	while(1){
		printf("inside main()\n");
		sleep(2);
	}
	return 0;
}
