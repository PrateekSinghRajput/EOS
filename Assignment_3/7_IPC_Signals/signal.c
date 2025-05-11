#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGUSR2) //SIGUSR1 = -10 ; SIGUSR2 = -12
  
     printf("received SIGINT\n");
     
     for(int i = 0; i<20; printf("%d ", i++));
     printf("\n");
}

int main(void)
{

  int ret;
  ret = signal(SIGUSR2, sig_handler);
  
  if (ret == SIG_ERR)
  
  printf("\ncan't catch SIGINT\n");
  // A long long wait so that we can easily issue a signal to this process
  printf("PID: %d\n", getpid());
  
  while(1){
  
    printf("Enjoing the while ???\n");
    sleep(1);
    }
    
  return 0;
}
