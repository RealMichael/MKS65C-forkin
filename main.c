#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int populate(){
    int i = 0;
    int rando = open("/dev/random", O_RDONLY);
    int reada = read(rando,&i,sizeof(int));
    close(rando);
    return i;
}

int main(){
    //int mama = getpid();
    fork();
    printf("PID %d A: %d\n",getpid(),populate());
}
