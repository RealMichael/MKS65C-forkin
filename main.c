#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
int populate(){
    int i = 0;
    int rando = open("/dev/random", O_RDONLY);
    int reada = read(rando,&i,sizeof(int));
    close(rando);
    if(i < 0){
	i = i * -1;
	}
    return (i % 16) + 5;
	}




int main(){
    
    printf("LEGO\n");

    int Orig = getpid();
    int ChildOne = fork();
    int ChildTwo;
    int status;
    int random = populate();

    //printf("LEGO\n");
	
    if(Orig == getpid()){
	ChildTwo = fork();
	}
    
    if(Orig != getpid()){
	printf("Child PID- %d\n",getpid());
	//int random = populate();
	sleep(random);
	printf("Child PID- %d done\n",getpid());
	
	}
	
    if(Orig == getpid()){
	int Orig2 = wait(&status);
	printf("My son %d slept for %d seconds\n",Orig2,random);
	printf("My turn to sleep\n");
	exit(0);
	}

	return 0;
	}