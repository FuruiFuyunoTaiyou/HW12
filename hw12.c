#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



int main(){
  printf("initial message \n");
  int f0 = fork();
  int f1;
  if(f0){
    f1 = fork();
  }
  if(f0 && f1){
    int status;
    int finished = wait(&status);
    printf("finished child: %d, sleeping for %d s \n", finished, WEXITSTATUS(status));
    printf("parent process finished. \n");
  }
  if(!f1 || !f0){
    srand(time(NULL) + f0);
    printf("child pid: %d \n", getpid());
    int i = rand() % 16 + 5;
    sleep(i);
    printf("child %d finished \n", getpid());
    return i;
  }
  return 0;
}
