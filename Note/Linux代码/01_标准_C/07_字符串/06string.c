/*�����ַ����������ַ�����ʾ�����ıȽ�
 */
#include <stdio.h>

int main(){
    char ch = 'c';
    //char str = "abc"; //����д�������ַ�����ֵ�������ַ�
    char *p_str = "abc";
    char str[] = "abc";
    printf("%c\n", ch);
    printf("%s\n", p_str);
    printf("%s\n", str);
    return 0;
}
