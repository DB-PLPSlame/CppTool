//����ָ�붨��
//������gdb����(gcc -g)
//p,*p,arr,&arr
#include <stdio.h>

int main(){
    int arr[] = {1,2,3};
    int brr[2][3] = {1,2,3,4,5,6};
    //ָ��һά����
    int (*p)[3] = &arr;
    printf("p = &arr\n");
    printf("p=%p,*p=%p\n", p, *p);
    printf("arr[1] = %d\n", arr[1]);
    printf("*(*p+1) = %d\n", *(*p+1));
    //ָ���ά������Ԫ��
    p = brr;
    printf("p = brr\n");
    printf("brr[1][1] = %d\n", brr[1][1]);
    printf("*(*(p+1)+1) = %d\n", *(*(p+1)+1));
    return 0;
}
