//ʹ��getpid,getppid����,��ȡ�ӽ��̺͸�����ID
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    printf("self pid %d\n",getpid());
    printf("parent pid %d\n",getppid());
    getchar();
    return 0;
}
