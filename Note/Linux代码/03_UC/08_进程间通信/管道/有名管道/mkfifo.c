//ʹ��mkfifo�������������ܵ��ļ�
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FNAME "/home/tarena/Desktop/m.pipe"

int main(void){
    mkfifo(FNAME,664);
    return 0;
}
