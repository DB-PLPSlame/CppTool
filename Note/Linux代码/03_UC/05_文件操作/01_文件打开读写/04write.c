//ϵͳ����write������ʾ
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    //1.���ļ�
    int fd = open("a.txt", O_WRONLY|O_CREAT|O_EXCL, 0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    printf("���ļ��ɹ�\n");
    //2.д���ļ�
    int res = write(fd, "hello", strlen("hello"));
    if(-1 == res){
        perror("write"); 
        return -1;
    }
    printf("д���ļ��ɹ���д������ݴ�С�ǣ�%d\n", res);
    //3.�ر��ļ�
    res = close(fd);
    if(res == -1){
        perror("close");
        return -1;
    }
    printf("�ر��ļ��ɹ�\n");
    return 0;
}
