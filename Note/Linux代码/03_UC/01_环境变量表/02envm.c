//main����������ĵ���������ʡ�Ե���,��������׵�ַ
#include <stdio.h>

int main(int argc, char *argv[], char *env[]){
    int i = 0;
    //����ʹ��env++
    for(; *(env+i); i++){
        printf("%s\n", *(env+i));
    }
}
